#pragma once

#include <Windows.h>
#include <windowsx.h>

class window
{
	static window* ptr;
	HWND hDialog;
	HWND hButOk, hButCancel;

	void Cls_OnClose(HWND hWnd);
	BOOL Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hWnd, int id, HWND hWndCtl, UINT codeNotify);

public:
	window();

	static BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

};

