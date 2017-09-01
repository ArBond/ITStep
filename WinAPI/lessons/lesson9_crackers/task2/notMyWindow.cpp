#include "notMyWindow.h"

#pragma comment(lib, "comctl32")
#include <Windows.h>
#include "resource.h"
#include <tchar.h>
#include <ctime>
#include <string>
#include <commCtrl.h>

notMyWindow* notMyWindow::ptr = NULL;

notMyWindow::notMyWindow()
{
	srand(time_t(0));
	ptr = this;
}

BOOL CALLBACK notMyWindow::DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
	}
	return false;
}


BOOL notMyWindow::Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam)
{
	hE_EDIT_1 = GetDlgItem(hWnd, EDIT1);
	hR_SUMM = GetDlgItem(hWnd, R_SUMM);
	hR_MULT = GetDlgItem(hWnd, R_MULT);
	hR_AVER = GetDlgItem(hWnd, R_AVER);
	hS_RESULT = GetDlgItem(hWnd, S_RESULT);
	hB_START = GetDlgItem(hWnd, B_START);

	hM = LoadMenu(GetModuleHandle(NULL), MAKEINTRESOURCE(IDR_MENU1));
	SetMenu(hWnd, hM);
	SendMessage(hR_SUMM, BM_SETCHECK, BST_CHECKED, 0);
	return true;
}

void notMyWindow::Cls_OnCommand(HWND hWnd, int id, HWND hWndCtl, UINT codeNotify)
{

	srand(time(NULL));
	std::wstring s, result = L"", r;
	TCHAR buf[100], *r_buf;
	int arr[20];
	int size;
	static int summ = 0;
	static double average = 0;
	static long multiple = 1;

	if (id == B_CLOSE)
		SendMessage(hWnd, WM_CLOSE, 0, 0);
	else if (id == B_RE) {
		SendMessage(hWnd, WM_COMMAND, MAKEWPARAM(B_START, BN_CLICKED), (LPARAM)hB_START);
	}
	else if (id == B_ABOUT)
		MessageBox(hWnd, TEXT("Математический калейдоскоп V 1.0003"), TEXT("About"), MB_OK);
	else if (id == B_AUTHOR) {
		MessageBox(hWnd, TEXT("Вячеслав Афанасенко\r\ne-mail: dezzfafara@gmail.com\r\nSkype: dezzfafara"), TEXT("Author"), MB_OK);
	}


	if (id == B_START)
	{
		MessageBox(hWnd, TEXT("BUTTON"), TEXT("About"), MB_OK);
		multiple = 1;
		summ = 0;
		average = 1;
		size = 10 + rand() % (20 - 10);
		for (int i = 0; i < size; i++)
		{
			arr[i] = -10 + rand() % (10 + 10);
			if (arr[i] == 0)
			{
				while (arr[i] == 0)
					arr[i] = -10 + rand() % (10 + 10);
			}
			s = std::to_wstring(arr[i]);
			result += s;
			if (i != size - 1)
				result += L"\r\n";
			summ += arr[i];
			multiple *= arr[i];
		}
		average = (double)summ / (double)size;
		_tcscpy(buf, result.c_str());
		SetWindowText(hE_EDIT_1, buf);
	}
	else if (id == R_MULT || SendDlgItemMessage(hWnd, R_MULT, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		r = std::to_wstring(multiple);
		r_buf = new TCHAR[r.length() + 1];
		_tcscpy(r_buf, r.c_str());
		SetWindowText(hS_RESULT, r_buf);
		delete[] r_buf;
		r_buf = NULL;
	}
	else if (id == R_SUMM || SendDlgItemMessage(hWnd, R_SUMM, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		r = std::to_wstring(summ);
		r_buf = new TCHAR[r.length() + 1];
		_tcscpy(r_buf, r.c_str());
		SetWindowText(hS_RESULT, r_buf);
		delete[] r_buf;
		r_buf = NULL;
	}
	else if (id == R_AVER || SendDlgItemMessage(hWnd, R_AVER, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		r = std::to_wstring(average);
		r_buf = new TCHAR[r.length() + 1];
		_tcscpy(r_buf, r.c_str());
		SetWindowText(hS_RESULT, r_buf);
		delete[] r_buf;
		r_buf = NULL;
	}


}

HBRUSH notMyWindow::Cls_OnCtlColor(HWND hwnd, HDC hdc, HWND hwndChild, int type)
{
	hdcStatic = (HDC)type;
	SetBkColor(hdcStatic, RGB(200, 200, 200));
	return (HBRUSH)hBr;
}

void notMyWindow::Cls_OnDrawItem(HWND hwnd, const DRAWITEMSTRUCT * lpDrawItem)
{
	LPDRAWITEMSTRUCT pDIS = (LPDRAWITEMSTRUCT)lpDrawItem;
	if (pDIS->hwndItem == hB_START)
	{
		SetBkColor(pDIS->hDC, RGB(200, 200, 200));
		SetTextColor(pDIS->hDC, RGB(0, 0, 0));
		WCHAR staticText[99];
		int len = SendMessage(hB_START, WM_GETTEXT, ARRAYSIZE(staticText), (LPARAM)staticText);
		GetClientRect(hB_START, &rect);
		DrawText(pDIS->hDC, staticText, len, &rect, DT_CENTER);

	}
}

void notMyWindow::Cls_OnClose(HWND hWnd)
{
	DestroyWindow(hWnd);
	PostQuitMessage(0);
}