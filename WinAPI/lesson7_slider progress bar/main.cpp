#include <Windows.h>
#include <iostream>
#include <string>
#include <map>

#include "commctrl.h"
#pragma comment(lib, "comctl32")

#include "resource.h"


namespace Data
{
	std::map<std::wstring, std::pair<int, std::wstring>> studentData;
}

void addStudentData(std::map<std::wstring, std::pair<int, std::wstring>> &studentData)
{
	std::pair<int, std::wstring> item1 = { 10, L"General-purpose programming language. First appeared 1983" };
	studentData.insert({ L"C++", item1 });

	std::pair<int, std::wstring> item2 = { 0, L"Multi-paradigm programming language. First appeared 2000" };
	studentData.insert({ L"C#", item2 });

	std::pair<int, std::wstring> item3 = { 0, L"Application programming interfaces available in the Microsoft Windows OS." };
	studentData.insert({ L"WinApi", item3 });

	std::pair<int, std::wstring> item4 = { 10, L"Ðigh-level programming language for general-purpose programming. First appeared 1991" };
	studentData.insert({ L"Python", item4 });

	std::pair<int, std::wstring> item5 = { 0, L"General-purpose computer programming language that is concurrent, class-based. First appeared 1995" };
	studentData.insert({ L"Java", item5 });

	std::pair<int, std::wstring> item6 = { 0, L"Dynamic, reflective, object-oriented, general-purpose programming language. First appeared 1995" };
	studentData.insert({ L"Ruby", item6 });
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	static HWND hButtonShow;
	static HWND hComboItems;
	static HWND hEditInfo;
	static HWND hEditMark;

	switch (uMsg)
	{
	case WM_INITDIALOG:
		hButtonShow = GetDlgItem(hWnd, IDC_BUTTONSHOW);
		hComboItems = GetDlgItem(hWnd, IDC_COMBOITEMS);
		hEditInfo = GetDlgItem(hWnd, IDC_STATICINFO);
		hEditMark = GetDlgItem(hWnd, IDC_STATICUSERMARK);

		addStudentData(Data::studentData);
		
		for (auto it = Data::studentData.begin(); it != Data::studentData.end(); ++it)
		{
			SendMessage(hComboItems, CB_ADDSTRING, 0, LPARAM(it->first.c_str()));
			Data::studentData[L"C++"].first;
		}

		return true;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTONSHOW)
		{
			wchar_t item[20];
			GetDlgItemText(hWnd, IDC_COMBOITEMS, item, 20);
			std::wstring t = std::to_wstring(Data::studentData[item].first);
			SetWindowText(hEditMark, t.c_str());
			SetWindowText(hEditInfo, Data::studentData[item].second.c_str());
		}
		return true;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	default:
		return false;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);

	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}