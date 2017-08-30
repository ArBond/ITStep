#include <Windows.h>

#include "commctrl.h"
#pragma comment(lib, "comctl32")

#include "resource.h"

#define ID_TIMER1 123
#define ID_TIMER2 124

#define ID_STATUSBAR 234

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hPrBar;
	static HWND hStatusBar;
	static HWND hSlider;
	static HWND hTimerInSec;

	static int seconds = 0;
	static int parts[3] = { 150, 250, -1 };

	switch (uMsg)
	{
	case WM_INITDIALOG:
		hPrBar = GetDlgItem(hWnd, IDC_PROGRESS1);
		hSlider = GetDlgItem(hWnd, IDC_SLIDER1);

		hStatusBar = CreateWindowEx(NULL, STATUSCLASSNAME, NULL, WS_CHILD | WS_VISIBLE | SBARS_TOOLTIPS | SBARS_SIZEGRIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, (HMENU)ID_STATUSBAR, GetModuleHandle(NULL), NULL);
		SendMessage(hStatusBar, SB_SIMPLE, false, 0);
		SendMessage(hStatusBar, SB_SETPARTS, 3, (LPARAM)parts);
		SendMessage(hStatusBar, SB_SETTEXT, 0, LPARAM(L"  User: Bondarenko Artemi"));
		SendMessage(hStatusBar, SB_SETTEXT, 2, LPARAM(L"  Time: 0 sec"));

		SendMessage(hPrBar, PBM_SETBKCOLOR, 0, LPARAM(RGB(100, 200, 100)));
		SendMessage(hPrBar, PBM_SETBARCOLOR, 0, LPARAM(RGB(55, 50, 200)));
		SendMessage(hPrBar, PBM_SETRANGE, 0, MAKELPARAM(0, 100));

		SendMessage(hSlider, TBM_SETRANGE, true, MAKELPARAM(0, 255));
		SendMessage(hSlider, TBM_SETPOS, true, 200);

		SetTimer(hWnd, ID_TIMER1, 100, NULL);
		SetTimer(hWnd, ID_TIMER2, 1000, NULL);

		hTimerInSec = GetDlgItem(hWnd, ID_TIMER2);

		return true;
	case WM_TIMER:
		SendMessage(hPrBar, PBM_DELTAPOS, 1, 0);

		wchar_t buff[50];
		memset(buff, 0, 50);

		wsprintf(buff, L"  Progress: %i %%", (LPCWSTR)SendMessage(hPrBar, PBM_GETPOS, 1, 0));
		SendMessage(hStatusBar, SB_SETTEXT, 1, LPARAM(buff));

		if (LOWORD(wParam) == ID_TIMER2)
		{
			seconds++;
			memset(buff, 0, 50);
			wsprintf(buff, L"  Time: %i sec", seconds);
			SendMessage(hStatusBar, SB_SETTEXT, 2, LPARAM(buff));
		}

		if (SendMessage(hPrBar, PBM_GETPOS, 0, 0) == 100)
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);
		}
		return true;
	case WM_HSCROLL:
		SendMessage(hPrBar, PBM_SETBARCOLOR, 0, LPARAM(RGB(255 - SendMessage(hSlider, TBM_GETPOS, 0, 0), 50, SendMessage(hSlider, TBM_GETPOS, 0, 0))));
		return true;
	case WM_CLOSE:
		KillTimer(hWnd, ID_TIMER1);
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	default:
		return false;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	INITCOMMONCONTROLSEX cc;
	cc.dwSize = sizeof(cc);
	cc.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&cc);

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
