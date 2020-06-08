///
/// @file sh_ssdt_hook.h
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
///

#ifndef _SH_SSDTHOOK_HEADER_
#define _SH_SSDTHOOK_HEADER_

#ifdef __cplusplus
extern "C" {
#endif

// �ṩ���û�ʹ�õĺ���������һ��new_function��ָ�룬�������ԭ���ĺ�����ָ�롣
// �����û������Լ�ȥ�ҵ�Ҫhook�ĺ����ĵ�ַ��
void* shSsdtHook(
		 void *func_to_hook,
		 void *new_func,
         void **old_func);

// ����ṹʵ��δ�������������Լ����塣
typedef struct ServiceDescriptorEntry {
	unsigned int *ServiceTableBase;
	unsigned int *ServiceCounterTableBase;
	unsigned int NumberOfServices;
	unsigned char *ParamTableBase;
} ServiceDescriptorTableEntry_t, *PServiceDescriptorTableEntry_t;

// ����SSDT�ķ���
__declspec(dllimport)  ServiceDescriptorTableEntry_t KeServiceDescriptorTable;

// ���������Ķ��塣���Ҫ��Hook�Ļ�����Щ���������Ͷ����������ϵġ�
typedef NTSTATUS (*SH_ZW_CREATE_FILE_F)(
	OUT PHANDLE  FileHandle,
    IN ACCESS_MASK  DesiredAccess,
    IN POBJECT_ATTRIBUTES  ObjectAttributes,
    OUT PIO_STATUS_BLOCK  IoStatusBlock,
    IN PLARGE_INTEGER  AllocationSize  OPTIONAL,
    IN ULONG  FileAttributes,
    IN ULONG  ShareAccess,
    IN ULONG  CreateDisposition,
    IN ULONG  CreateOptions,
    IN PVOID  EaBuffer  OPTIONAL,
    IN ULONG  EaLength
);

typedef NTSTATUS (*SH_ZW_CREATE_DIRECTORY_OBJECT_F)(
    OUT PHANDLE  DirectoryHandle,
    IN ACCESS_MASK  DesiredAccess,
    IN POBJECT_ATTRIBUTES  ObjectAttributes
);

typedef NTSTATUS (*SH_ZW_CLOSE_F)(
    IN HANDLE  Handle
);

typedef NTSTATUS (*SH_ZW_READ_FILE_F)(
    IN HANDLE  FileHandle,
    IN HANDLE  Event  OPTIONAL,
    IN PIO_APC_ROUTINE  ApcRoutine  OPTIONAL,
    IN PVOID  ApcContext  OPTIONAL,
    OUT PIO_STATUS_BLOCK  IoStatusBlock,
    OUT PVOID  Buffer,
    IN ULONG  Length,
    IN PLARGE_INTEGER  ByteOffset  OPTIONAL,
    IN PULONG  Key  OPTIONAL
    );

typedef NTSTATUS (*SH_ZW_WRITE_FILE_F)(
    IN HANDLE  FileHandle,
    IN HANDLE  Event  OPTIONAL,
    IN PIO_APC_ROUTINE  ApcRoutine  OPTIONAL,
    IN PVOID  ApcContext  OPTIONAL,
    OUT PIO_STATUS_BLOCK  IoStatusBlock,
    IN PVOID  Buffer,
    IN ULONG  Length,
    IN PLARGE_INTEGER  ByteOffset  OPTIONAL,
    IN PULONG  Key  OPTIONAL
);

typedef NTSTATUS (*SH_ZW_SET_INFORMATION_FILE_F)(
    IN HANDLE  FileHandle,
    OUT PIO_STATUS_BLOCK  IoStatusBlock,
    IN PVOID  FileInformation,
    IN ULONG  Length,
    IN FILE_INFORMATION_CLASS  FileInformationClass
);

typedef NTSTATUS (*SH_ZW_DELETE_FILE_F)(
    IN POBJECT_ATTRIBUTES  ObjectAttributes
);

typedef NTSTATUS (*SH_ZW_CREATE_PROCESS_EX_F)(
    OUT PHANDLE ProcessHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
    IN HANDLE ParentProcess,
    IN BOOLEAN InheritObjectTable,
    IN HANDLE SectionHandle OPTIONAL,
    IN HANDLE DebugPort OPTIONAL,
    IN HANDLE ExceptionPort OPTIONAL,
    IN HANDLE Unknown 
);  

typedef NTSTATUS
	(*SH_ZW_OPEN_PROCESS)(
		IN PHANDLE  ProcessHandle,
		IN ACCESS_MASK  DesiredAccess,
		IN POBJECT_ATTRIBUTES  ObjectAttributes,
		IN PCLIENT_ID  ClientId);

#ifdef __cplusplus
}
#endif

#endif 