#include <windows.h>
#include <string>
#include <iostream>

std::wstring kPathToBrowser
	= TEXT("c:\\Program Files\\Google\\Chrome\\Application\\chrome.exe");

const DWORD kDelaySec = 10;

int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	CreateProcess(NULL, (LPWSTR)kPathToBrowser.c_str(), NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL, NULL, &si, &pi);
	for (int i = kDelaySec; i > 0; --i)
	{
		std::cout << i << " seconds left to sleep\n";
		Sleep(1000);
	}
	TerminateProcess(pi.hProcess, 0);

	return 0;
}
