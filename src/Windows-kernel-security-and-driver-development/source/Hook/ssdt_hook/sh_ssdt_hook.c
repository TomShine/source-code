///
/// @file sh_ssdt_hook.c
/// @author tanwen
/// @date 2012-6-19
/// 
/// ��Ȩ������
/// 
/// 1.�˷ݴ���Ϊ̷��Ϊ������ҹ�������ĵ�Windows�ں˰�ȫ��̡�����д�Ĵ���
/// ������Ϊ���鸽������δ���ۣ�������߱��˲����Դ�ıȡ�κ���ҵ���棬ͬʱ
/// ��Ϊ�������ṩ�κε�����
///
/// 2.ʹ�ô˴�����������ѧϰ֮���������;����Ҫ��������Э�飺�˴������߲�
/// Ϊ�˴��뵣�κ����Ρ�����������������ʹ�ô˴���������κ�ֱ�ӻ��߼�ӵ�
/// ��ʧ���Լ�֪ʶ��Ȩ���鵼�µľ��ף�����Ҳ����е��κξ�֤�����Ρ�ʹ����
/// �����Լ��е�һ�����Ρ�
///
/// 3.ʹ�ô˴��뼴Ϊ��������Э�顣����������Э���ߣ�����ʹ�ô˴��롣


#include <ntifs.h>
#include <windef.h>
#include "sh_ssdt_hook.h"

#if 0

void shDisableWriteProtect(ULONG *old)
{
	wd_ulong cr0_old;
	_asm
	{
		// ȡ����ǰcr0��ֵ����edi�����ݵ�������
		mov edi,cr0 
		mov cr0_old,edi
		// �ø��ַ�������edi����0fffeffffh
		xor edx, edx
		or edx, 0fffe0000h
		push edx
		pop ecx
		or ecx, 00000ffffh
		and edi,ecx;
		cli
		mov cr0,edi;
	};
	*old = cr0_old;
}

void shEnableWriteProtect(ULONG old)
{
	_asm {
		push old
		pop ebx
		mov cr0,ebx
		sti
	};
}

#else 

// ֱ���˵��İ汾�����ܱ�ɱ�����ֱ��ɾ��
void shDisableWriteProtect(ULONG *old)
{
	ULONG cr0_old;
	_asm
	{
		cli
		// ȡ����ǰcr0��ֵ����eax�����ݵ�������
		mov eax,cr0 
		mov cr0_old,eax
		// ��eax����0fffeffffh
		and eax,0fffeffffh
		mov cr0,eax;
	};
	*old = cr0_old;
}

void shEnableWriteProtect(ULONG old)
{
	_asm {
		mov eax,old
		mov cr0,eax
		sti
	};
}

#endif

void* shSsdtHook(
		 void *func_to_hook,
		 void *new_func,
         void **old_func)
{
	ULONG service_id;
	void *function = NULL;
	ULONG cr0_old;
	void* old_function = NULL;

	ASSERT(func_to_hook != NULL);
	ASSERT(new_func != NULL);
	if(func_to_hook == NULL || new_func == NULL)
		return NULL;

	// ��÷�����
	service_id = *(PULONG)(((PUCHAR)func_to_hook)+1);
	// ���ԭ�еĺ���ָ�롣
	old_function = (void *)KeServiceDescriptorTable.ServiceTableBase[service_id];

    // һ��Ҫ��������ԭ�к���ָ�룬Ȼ����hook�������
    // �ܳ���hook֮��ԭ�к�����Ȼ��NULL������ڵ���ԭ
    // �к�����ʱ��crash��
    if(old_func != NULL)
        *old_func = old_function;

	// ����д֮������һ��֮��hook���Ѿ��������ˡ�
	shDisableWriteProtect(&cr0_old);
	KeServiceDescriptorTable.ServiceTableBase[service_id] = (unsigned int)new_func;
	shEnableWriteProtect(cr0_old);

	// ���ؾɵġ�
	return old_function;
}
