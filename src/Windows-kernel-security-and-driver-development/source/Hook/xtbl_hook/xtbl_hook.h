///
/// @file xtbl_hook.h
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
///

#ifndef _XTBL_HOOK_HEADER_
#define _XTBL_HOOK_HEADER_

#ifdef __cplusplus
extern "C" {
#endif

// �ṩ���û�ʹ�õĺ���������һ��new_function��ָ�룬�������ԭ���ĺ�����ָ�롣
// �����û������Լ�ȥ�ҵ�Ҫhook�ĺ����ĵ�ַ��
void* xtblHook(void *function,void* new_function, void **old_func);

// ���ϱߵĺ���һ����ֻ���õ��Ǻ�������
void* xtblHookWithName(UNICODE_STRING *func_name,void* new_func, void **old_func);


#ifdef __cplusplus
}
#endif

#endif // _XTBL_HOOK_HEADER_