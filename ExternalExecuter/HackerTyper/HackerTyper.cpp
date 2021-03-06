// HackerTyper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>
#include <atlstr.h>

#include <Windows.h>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

void ExecuteProgram(CString address)
{
	ShellExecute(NULL, _T("open"), address, NULL, NULL, SW_MAXIMIZE);
}

void SetPrintColor(unsigned int color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

int main()
{	
	TCHAR dest[MAX_PATH];

	GetModuleFileName(NULL, dest, MAX_PATH);
	PathRemoveFileSpec(dest);
	

	std::ifstream codeFile(std::wstring(dest) + L"\\Text.txt");
	SetPrintColor(10);

	if (codeFile.is_open())
	{
		char c;
		while(codeFile.good())
		{
			Sleep(1);

			for (auto i = 0; i < 5; ++i)
			{
				codeFile.get(c);
				std::cout << c;
			}
			
		}
	}

	CString address = L"C:\\Users\\HookSSi\\Desktop\\개발\\유니티\\TDSS\\client\\Game\\GungeonOnline.exe";
	ExecuteProgram(address);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
