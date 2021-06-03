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
// 函数名称: ShellCodeEntry
// 函数说明: 真正的ShellCode代码
// 作	 者: GuiShou
// 时	 间: 2019/5/19
// 参	 数: void
// 返 回 值: void
//************************************************************
void ShellCodeEntry()
{
	Functions fn;

	Initfunctions(&fn);
	//C:\Program Files(x86)\Essentials Codec Pack\FFDShow\ffdshow.ax
	//调用MessageBox
	char szText[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'G', 'u', 'i', 'S', 'h', 'o', 'u', 0 };
	char szCaption[] = { 'T', 'i', 'p', 0 };
	char szLoadDll[] = { 'C',':','\\','P','r','o','g','r','a','m','F','i','l','e','s','(','x','8','6',')','\\','E','s','s','e','n','t','i','a','l','s',' ','C','o','d','e','c',' ','P','a','c','k','\\','F','F','D','S','h','o','w','\\','f','f','d','s','h','o','w','.','a','x',0 };
	fn.fnMessageBoxA(NULL, szText, szCaption, MB_OK);
	fn.fnLoadLibraryA(szLoadDll);
}