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
#include "../ssdt_hook/sh_ssdt_hook.h"
#include "../xtbl_hook/xtbl_hook.h"

static SH_ZW_CREATE_FILE_F hsOriginalZwCreateFile = NULL;
static SH_ZW_CLOSE_F hsOriginalZwClose = NULL;

// ��������У�hook ZwCreateFile��ZwClose,�������̷����ļ��������
NTSTATUS hsZwCreateFile(
	OUT PHANDLE  file_handle,
    IN ACCESS_MASK  desired_access,
    IN POBJECT_ATTRIBUTES  obj_attr,
    OUT PIO_STATUS_BLOCK  io_status,
    IN PLARGE_INTEGER  alloc_size  OPTIONAL,
    IN ULONG  file_attr,
    IN ULONG  shared_access,
    IN ULONG  create_dispos,
    IN ULONG  create_options,
    IN PVOID  ea_buffer  OPTIONAL,
    IN ULONG  ea_length)
{
	NTSTATUS status;
	// �����������ǵ��þɺ�����
	status = hsOriginalZwCreateFile(
		file_handle, 
		desired_access, 
		obj_attr, 
		io_status, 
		alloc_size, 
		file_attr, 
		shared_access, 
		create_dispos,
		create_options,
		ea_buffer,
		ea_length);
	// ��ӡһ����Ϣ���˽�˭���ĸ����̣����ʲô�ļ���������ĸ����
	// �����顣
	DbgPrint("ZwCreateFile: %wZ, desired_access = %x, returned status = %x, handle = %x\r\n", 
		obj_attr->ObjectName, desired_access, status, *file_handle);
	return status;
};

NTSTATUS hsZwClose(
    IN HANDLE  handle
)
{
	DbgPrint("ZwClose: handle %x was closed.\r\n", handle);
	return hsOriginalZwClose(handle);	
};

// ���ȶ���һ��IofCallDriver�ĺ�������
typedef NTSTATUS (__fastcall *HS_IOF_CALLDIVER)(PDEVICE_OBJECT dev,PIRP irp);
HS_IOF_CALLDIVER hsOriginalIofCallDriver = NULL;

NTSTATUS __fastcall hsIofCallDriver(PDEVICE_OBJECT dev,PIRP irp)
{
    // ��������ĵ��ô���̫���ˡ������ӡ�����Ļ���������ǵء�����
    // �������ÿ256�δ�ӡһ����
    static ULONG count = 0;
    count ++;
    if(count % 256 == 0)
    {
        DbgPrint("IofCallDriver: dev = %x, irp = %x\r\n", dev, irp);
    }
    return hsOriginalIofCallDriver(dev, irp);
}


static void hsSleep(int msec)
{
    LARGE_INTEGER interval;
#define DELAY_ONE_MICROSECOND   (-10)
#define DELAY_ONE_MILLISECOND   (DELAY_ONE_MICROSECOND*1000)
#define DELAY_ONE_SECOND        (DELAY_ONE_MILLISECOND*1000)
    interval.QuadPart = (msec * DELAY_ONE_MILLISECOND);
    KeDelayExecutionThread(KernelMode, FALSE, &interval);
}


VOID hsDriverUnload(IN PDRIVER_OBJECT DriverObject) 
{
	UNICODE_STRING zw_create_file = RTL_CONSTANT_STRING(L"ZwCreateFile");
	UNICODE_STRING zw_close_file = RTL_CONSTANT_STRING(L"ZwClose");
    UNICODE_STRING iof_call_driver = RTL_CONSTANT_STRING(L"IofCallDriver");
	void *pt_create = NULL, *pt_close = NULL, *pt_iof_call_driver = NULL;
	if(hsOriginalZwCreateFile != NULL) 
	{
		pt_create = MmGetSystemRoutineAddress(&zw_create_file);
		shSsdtHook(pt_create, hsOriginalZwCreateFile, NULL);
	}
	if(hsOriginalZwClose != NULL)
	{
		pt_close = MmGetSystemRoutineAddress(&zw_close_file);
		shSsdtHook(pt_close, hsOriginalZwClose, NULL);
	}
    if(hsIofCallDriver != NULL)
    {
        pt_iof_call_driver = MmGetSystemRoutineAddress(&iof_call_driver);
        xtblHook(pt_iof_call_driver, hsOriginalIofCallDriver, NULL);
    }

	// ������ж����hook,Ҳ���ų�һЩ�������������ĵ��û��ڽ����С�����
	// ���ʱ������ж�����������ܵ�������ִ�еĴ��뱻ж�ص��ˣ�����ᵼ��
	// ��������������û��ʲô�ر�õĽ��������һ����Ծ���˯��һ��ʱ��
	// ������Щ������ִ����ϡ������5000��ζ��5�롣
	hsSleep(5000);
}

NTSTATUS
DriverEntry(
             IN PDRIVER_OBJECT   driver,
             IN PUNICODE_STRING  reg_path)
{
	UNICODE_STRING zw_create_file = RTL_CONSTANT_STRING(L"ZwCreateFile");
	UNICODE_STRING zw_close_file = RTL_CONSTANT_STRING(L"ZwClose");
    UNICODE_STRING iof_call_driver = RTL_CONSTANT_STRING(L"IofCallDriver");
	void *pt_create = NULL, *pt_close = NULL, *pt_iof_call_driver = NULL;
	void *pt = NULL;
	NTSTATUS status = STATUS_UNSUCCESSFUL;

	KdBreakPoint();

	pt_create = MmGetSystemRoutineAddress(&zw_create_file);
	pt_close = MmGetSystemRoutineAddress(&zw_close_file);
    pt_iof_call_driver = MmGetSystemRoutineAddress(&iof_call_driver);

	ASSERT(pt_create != NULL);
	ASSERT(pt_close != NULL);

	do {
		// ��������������ĵ�ַ���ò������Ǿ�ֱ�ӷ���ʧ�ܼ���
		if(pt_create == NULL ||
			pt_close == NULL)
		{
			break;
		}
		
		// ��ַ�õ�֮��Ϳ�ʼ��hook��
		if(shSsdtHook(pt_create, hsZwCreateFile, (void **)&hsOriginalZwCreateFile) == NULL)
		{
			// ���hookʧ�ܵĻ�������ʧ�ܡ�
			break;
		}

		// �������һ��hook�ɹ������еڶ���
		// ��ַ�õ�֮��Ϳ�ʼ��hook��
		if(shSsdtHook(pt_close, hsZwClose, (void **)&hsOriginalZwClose) == NULL)
		{
			// ���hookʧ�ܵĻ�������ʧ�ܡ�����֮ǰ�ָ���һ��hook.
			pt_create = MmGetSystemRoutineAddress(&zw_create_file);
			shSsdtHook(pt_create, hsOriginalZwCreateFile, NULL);
			break;
		}
		status = STATUS_SUCCESS;
        if(xtblHook(pt_iof_call_driver, hsIofCallDriver, (void **)&hsOriginalIofCallDriver) == NULL)
        {
			// ���hookʧ�ܵĻ�������ʧ�ܡ�����֮ǰ�ָ���һ,����hook.
			pt_create = MmGetSystemRoutineAddress(&zw_create_file);
			shSsdtHook(pt_create, hsOriginalZwCreateFile, NULL);
			pt_close = MmGetSystemRoutineAddress(&zw_close_file);
			shSsdtHook(pt_close, hsOriginalZwClose, NULL);
            break;
        }
	} while(0);
	driver->DriverUnload = hsDriverUnload;
	return status;
}