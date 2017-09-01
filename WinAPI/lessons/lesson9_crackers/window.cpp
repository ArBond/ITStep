#include <time.h>
#include <Windows.h>

#include "window.h"
#include "resource.h"

window* window::ptr = NULL;

window::window()
{
	srand(time_t(0));
	ptr = this;
}

BOOL CALLBACK window::DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
	}
	return false;
}




void window::Cls_OnClose(HWND hWnd)
{
	DestroyWindow(hWnd);
	PostQuitMessage(0);
}

BOOL window::Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam)
{
	hDialog = hWnd;
	hButOk = GetDlgItem(hWnd, IDOK);
	hButCancel = GetDlgItem(hWnd, IDCANCEL);
	return true;
}

void window::Cls_OnCommand(HWND hWnd, int id, HWND hWndCtl, UINT codeNotify)
{
	switch (id)
	{
	case IDOK:
		break;
	case IDCANCEL:
		if (MessageBox(hWnd, L"Info", L"Info", MB_YESNO) == IDYES)
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);
		}
		break;
	default:
		break;
	}
}