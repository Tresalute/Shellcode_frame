#include "header.h"
#include "api.h"

__declspec(naked)void ShellCodeStart()
{
	__asm
	{
		jmp ShellCodeEntry;
	}
}



//************************************************************
// ��������: ShellCodeEntry
// ����˵��: ������ShellCode����
// ��	 ��: GuiShou
// ʱ	 ��: 2019/5/19
// ��	 ��: void
// �� �� ֵ: void
//************************************************************
void ShellCodeEntry()
{
	Functions fn;
	//��̬��ȡ������Ҫ�ĺ���ָ��
	Initfunctions(&fn);
	//����MessageBox
	char szText[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'G', 'u', 'i', 'S', 'h', 'o', 'u', 0 };
	char szCaption[] = { 'T', 'i', 'p', 0 };
	fn.fnMessageBoxA(NULL, szText, szCaption, MB_OK);
}