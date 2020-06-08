///
/// @file xtbl_hook.c
/// @author tanwen
/// @date 2012-7-4
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
#include "xtbl_hook.h"

#ifdef _WIN64
#error "Only support 32 bit!"
#endif

// �ṩ���û�ʹ�õĺ���������һ��new_function��ָ�룬�������ԭ���ĺ�����ָ�롣
// �����û������Լ�ȥ�ҵ�Ҫhook�ĺ����ĵ�ַ��
void* xtblHook(void *func_to_hook,void* new_func, void **old_func)
{
	PBYTE func_body = (PBYTE)func_to_hook;
    PVOID *target_addr = *(PVOID *)(func_body + 2);
    PVOID ret = NULL;

    // �����������֧��32λ
    ASSERT(sizeof(PVOID) == 4);

    // ���������ĺ��������ص�ģ�����Ҫ������������ĺ�����
    // nt!IofCallDriver:
    // 804e47c5 ff2500375580    jmp     dword ptr [nt!pIofCallDriver (80553700)]
    if(func_body[0] != 0xff || func_body[1] != 0x25)
    {
        KdPrint(("xtbl: Not an export function.\r\n"));
        return NULL;
    }

    // �����������еĺ���Ӧ����һ���ں˵�ַ��������һ�ؼ�顣
    // ��������Ӧ����һ���ں˺����ĵ�ַ��
    if((ULONG)*target_addr < 0x80000000)
    {
        KdPrint(("xtbl: Not an export function.\r\n"));
        return NULL;
    }

    if((ULONG)new_func <= 0x80000000)
    {
        KdPrint(("xtbl: Not an good new function.\r\n"));
        return NULL;
    }

    // ����ȷ�����ˣ�����ȫȷ��������ȡ��
    ret = *target_addr;

    if(old_func != NULL)
        *old_func = ret;

    // ����֮���hook���ˡ���������֮ǰһ��Ҫ���úþɵġ�
	InterlockedExchange((PLONG)target_addr,
		(LONG)new_func);
	return ret;
}

void* xtblHookWithName(UNICODE_STRING *func_name,void* new_func, void **old_func)
{
    void *func_pt = MmGetSystemRoutineAddress(func_name);
    if(func_pt == NULL) 
    {
        KdPrint(("xtblHookWithName: failed to get the function address from %wZ\r\n", func_name));
        return NULL;
    }
    return xtblHook(func_pt, new_func, old_func);
}
