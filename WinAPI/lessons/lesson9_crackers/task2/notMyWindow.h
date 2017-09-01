#pragma once

#include <Windows.h>
#include <windowsx.h>
#include <string>

class notMyWindow
{
	static notMyWindow* ptr;
	HWND hE_EDIT_1, hR_SUMM, hR_MULT, hR_AVER, hS_RESULT, hB_START;
	HMENU hM;
	RECT rect;
	HDC hdcStatic;
	HBRUSH hBr = CreateSolidBrush(RGB(200, 200, 200));

	BOOL Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hWnd, int id, HWND hWndCtl, UINT codeNotify);
	HBRUSH Cls_OnCtlColor(HWND hwnd, HDC hdc, HWND hwndChild, int type);
	void Cls_OnDrawItem(HWND hwnd, const DRAWITEMSTRUCT * lpDrawItem);
	void Cls_OnClose(HWND hWnd);

public:
	notMyWindow();
	static BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
};

