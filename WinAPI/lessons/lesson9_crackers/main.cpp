#include <Windows.h>

#include "window.h"
#include "resource.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	window wnd;
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, window::DlgProc);
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while(GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
