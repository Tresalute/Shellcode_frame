#include <stdio.h>
#include <windows.h>

int main(int argc,char* argv[])
{ 
	//��Ҫִ�е�ShellCode�ļ�
	HANDLE hFile = CreateFileA("ShellCode.bin", GENERIC_READ, 0, NULL, OPEN_ALWAYS, 0, NULL);
	if (hFile==INVALID_HANDLE_VALUE)
	{
		printf("CreateFile Error");
		return -1;
	}

	DWORD dwSize = 0;
	//��ȡShellCode���ܴ�С
	dwSize = GetFileSize(hFile, NULL);

	//����һ��ɶ���д��ִ�е��ڴ�
	LPVOID lpAddress = VirtualAlloc(NULL, dwSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (lpAddress == NULL)
	{
		printf("VirtualAlloc Error");
		CloseHandle(hFile);
		return -1;
	}

	//���ļ���ȡ��������ڴ���
	DWORD dwRead = 0;
	ReadFile(hFile, lpAddress, dwSize, &dwRead, 0);

	//ִ��ShellCode
	__asm
	{
		call lpAddress;
	}
	return 0;
}