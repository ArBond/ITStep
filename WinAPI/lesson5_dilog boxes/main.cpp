#include <Windows.h>
#include "resource.h"


//			МОДАЛЬНОЕ

//BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (uMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_CLOSE:
//		EndDialog(hwnd, 0);
//		return true;
//	default:
//		return false;
//	} 
//}
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
//{
//	return DialogBox(hInstance, MAKEINTRESOURCE(101), NULL, DlgProc);
//}



//			НЕМОДАЛЬНОЕ

#define ID_BUTTON 3000
#define WIDE_WINDOW 1900
#define HIDE_WINDOW 1000

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hStatic1;
	static HWND hWndButCLick, hWwdButYes, hWndButNo, hWndButGo, hWndButChekWont;

	switch (uMsg)
	{
	case WM_INITDIALOG:
		hWwdButYes = GetDlgItem(hWnd, IDOK);
		hWndButNo = GetDlgItem(hWnd, IDNO);
		hWndButGo = GetDlgItem(hWnd, IDC_BUTTON1);
		hWndButChekWont = GetDlgItem(hWnd, IDC_CHECK1);

		hStatic1 = CreateWindowEx(NULL, L"Static", L"My First Static", WS_CHILD | WS_VISIBLE, 120, 30, 100, 20, hWnd, (HMENU)NULL, GetModuleHandle(NULL), NULL);

		hWndButCLick = CreateWindowEx(WS_EX_TOPMOST, L"BUTTON", L"Click", WS_CHILD | WS_VISIBLE, 150, 60, 50, 50, hWnd, (HMENU)ID_BUTTON, GetModuleHandle(NULL), NULL);

		return true;
	case WM_COMMAND:
		if ((HWND)lParam == hWndButNo)
		{
			MessageBox(NULL, L"Bye", L"Ok", MB_OK);
			break;
		}

		switch (LOWORD(wParam))
		{
		case IDOK:
			MessageBox(NULL, L"Good!", L"Ok", MB_OK);
			if (SendMessage(hWndButChekWont, BM_GETCHECK, 0, 0) == BST_UNCHECKED)
			{
				SendMessage(hWndButChekWont, BM_SETCHECK, BST_CHECKED, 0);
			}
			else
			{
				SendMessage(hWndButChekWont, BM_SETCHECK, BST_UNCHECKED, 0);
			}
			break;
		case ID_BUTTON:
			MoveWindow(hWnd, rand() % (WIDE_WINDOW - 400), rand() % (HIDE_WINDOW - 400), 350, 200, true);
			break;
		}
	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;	
	}
	return false;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(103), NULL, DlgProc);
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
