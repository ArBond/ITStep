#include <Windows.h>
#include "resource.h"

#define ID_EDIT 100

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hEditText;
	static HWND hEditFont;
	static HWND hButtonDelete;
	static HWND hEditCopies;
	static HWND hDlg;
	static HWND hListBoxFonts;
	static HWND hComboBox;

	int index;
	LONG style;

	switch (uMsg)
	{
	case WM_INITDIALOG:
		hButtonDelete = GetDlgItem(hWnd, IDC_BUTTONDELETE);
		hDlg = GetDlgItem(hWnd, IDD_DIALOG1);
		hComboBox = GetDlgItem(hWnd, IDC_COMBO);

		hEditText = CreateWindowEx(NULL, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE, 130, 20, 100, 50, hWnd, (HMENU)ID_EDIT, GetModuleHandle(NULL), NULL);
		hEditFont = CreateWindowEx(NULL, L"EDIT", L"Font(8 - 40):", WS_CHILD | WS_VISIBLE | ES_READONLY, 25, 15, 80, 20, hWnd, (HMENU)ID_EDIT, GetModuleHandle(NULL), NULL);
		hEditCopies = CreateWindowEx(NULL, L"EDIT", L"Copies:", WS_CHILD | WS_VISIBLE | ES_READONLY, 280, 15, 80, 20, hWnd, (HMENU)ID_EDIT, GetModuleHandle(NULL), NULL);
		hListBoxFonts = CreateWindowEx(NULL, L"LISTBOX", NULL, WS_CHILD | WS_VISIBLE | LBS_NOTIFY | LBS_STANDARD ^ LBS_SORT, 30, 40, 80, 30, hWnd, (HMENU)NULL, GetModuleHandle(NULL), NULL);
		SendMessage(hListBoxFonts, LB_ADDSTRING, 0, LPARAM(L"8"));
		SendMessage(hListBoxFonts, LB_ADDSTRING, 0, LPARAM(L"10"));
		SendMessage(hListBoxFonts, LB_ADDSTRING, 0, LPARAM(L"12"));
		SendMessage(hListBoxFonts, LB_ADDSTRING, 0, LPARAM(L"14"));
		SendMessage(hListBoxFonts, LB_ADDSTRING, 0, LPARAM(L"16"));
		SendMessage(hListBoxFonts, LB_ADDSTRING, 0, LPARAM(L"20"));
		
		SendMessage(hComboBox, CB_ADDSTRING, 0, LPARAM(L"1"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, LPARAM(L"2"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, LPARAM(L"3"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, LPARAM(L"4"));
		return true;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTONDELETE)
		{
			int len = SendMessage(hEditText, WM_GETTEXTLENGTH, 0, 0) + 1;
			SendMessage(hEditText, EM_SETSEL, 0, len);
			SendMessage(hEditText, WM_CLEAR, 0, 0);
		}
		else if (LOWORD(wParam) == IDC_BUTTONPRINT)
		{
			int len = SendMessage(hEditText, WM_GETTEXTLENGTH, 0, 0) + 1;
			wchar_t* buff = new wchar_t[len];
			buff[len - 1] = L'\0';

			GetWindowText(hEditText, buff, len);
			//SendMessage(hEditText, EM_GETLINE, 0, LPARAM(buff));

			SetWindowText(hWnd, buff);
			delete[] buff;
		}
		else if (LOWORD(wParam) == IDC_BUTTONADD)
		{
			wchar_t buff[30];
			GetWindowText(hEditText, buff, 30);
			SendMessage(hListBoxFonts, LB_ADDSTRING, 0, LPARAM(buff));
			int count = SendMessage(hListBoxFonts, LB_GETCOUNT, 0, 0);
			wsprintf(buff, L"fonts count: %d", count);
			MessageBox(NULL, buff, L"Size", MB_OK);
		}
		return true;
	case WM_RBUTTONDOWN:
		index = SendMessage(hListBoxFonts, LB_GETCURSEL, 0, 0);
		SendMessage(hListBoxFonts, LB_DELETESTRING, index, 0);
		return true;
	case WM_LBUTTONDOWN:
		style = GetWindowLong(hEditText, GWL_STYLE);
		return true;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	default:
		return false;
	}
	return false;
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
