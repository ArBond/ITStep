#include <Windows.h>
#include <commdlg.h>

#include "resource.h"

BOOL CALLBACK DlgProcAbout(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		return true;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTONCANCEL)
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);
		}
		return true;
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return true;
	default:
		return false;
	}
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hEditMain;
	static HWND hAboutProgram;

	static OPENFILENAME openFile;

	static HMENU hMainMenu;
	static int i = 0;

	static wchar_t szFilePath[256];
	static wchar_t szFileTitle[100];

	static OPENFILENAME saveFile;

	static wchar_t szFilePathSave[256];
	static wchar_t szFileTitleSave[100];

	static bool flagVievHelp = true;

	RECT rect;

	switch (uMsg)
	{
	case WM_INITDIALOG:
		memset(&openFile, 0, sizeof(OPENFILENAME));

		openFile.lStructSize = sizeof(OPENFILENAME);
		openFile.hInstance = GetModuleHandle(NULL);
		openFile.hwndOwner = hWnd;
		openFile.lpstrFile = szFilePath;
		openFile.lpstrFileTitle = szFileTitle;
		openFile.nMaxFile = 256;
		openFile.nMaxFileTitle = 100;
		openFile.lpstrFilter = L"All Files(*.*)\0*.txt\0*.doc*\0\0";

		memset(&saveFile, 0, sizeof(OPENFILENAME));

		saveFile.lStructSize = sizeof(OPENFILENAME);
		saveFile.hInstance = GetModuleHandle(NULL);
		saveFile.hwndOwner = hWnd;
		saveFile.lpstrFile = szFilePathSave;
		saveFile.lpstrFileTitle = szFileTitleSave;
		saveFile.nMaxFile = 256;
		saveFile.nMaxFileTitle = 100;

		hEditMain = GetDlgItem(hWnd, IDC_EDITMAIN);
		hAboutProgram = GetDlgItem(hWnd, IDD_DIALOG2);

		hMainMenu = LoadMenu(GetModuleHandle(NULL), MAKEINTRESOURCE(IDR_MENU1));
		SetMenu(hWnd, hMainMenu);

		EnableMenuItem(hMainMenu, ID_EDIT_PASTE, MF_BYCOMMAND | MF_DISABLED);
		CheckMenuItem(hMainMenu, ID_HELP_VIEWHELP, MF_BYCOMMAND | MF_CHECKED);

		return true;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_FILE_OPEN)
		{
			GetOpenFileName(&openFile);
			SetWindowText(hWnd, openFile.lpstrFileTitle);
		}
		else if (LOWORD(wParam) == ID_FILE_SAVEAS)
		{
			GetSaveFileName(&saveFile);
		}


		else if (LOWORD(wParam) == ID_EDIT_COPY)
		{
			SendMessage(hEditMain, WM_COPY, 0, 0);
			EnableMenuItem(hMainMenu, ID_EDIT_PASTE, MF_BYCOMMAND | MF_ENABLED);
		}
		else if (LOWORD(wParam) == ID_EDIT_CUT)
		{
			SendMessage(hEditMain, WM_CUT, 0, 0);
			EnableMenuItem(hMainMenu, ID_EDIT_PASTE, MF_BYCOMMAND | MF_ENABLED);
		}
		else if (LOWORD(wParam) == ID_EDIT_PASTE)
		{
			SendMessage(hEditMain, WM_PASTE, 0, 0);
		}
		else if (LOWORD(wParam) == ID_EDIT_CLEAR)
		{
			SetWindowText(hEditMain, NULL);
		}


		else if (LOWORD(wParam) == ID_HELP_VIEWHELP)
		{
			if (flagVievHelp)
			{
				CheckMenuItem(hMainMenu, ID_HELP_VIEWHELP, MF_BYCOMMAND | MF_UNCHECKED);
			}
			else
			{
				CheckMenuItem(hMainMenu, ID_HELP_VIEWHELP, MF_BYCOMMAND | MF_CHECKED);
			}
			flagVievHelp = !flagVievHelp;
		}
		else if (LOWORD(wParam) == ID_HELP_ABOUTPROGRAM)
		{
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DlgProcAbout);
		}
		return true;
	case WM_SIZE:
		GetClientRect(hWnd, &rect);
		MoveWindow(hEditMain, 0, 0, rect.right, rect.bottom, true);
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
	LoadLibrary(L"Riched20.dll");
	HACCEL hAcc = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR1));

	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);

	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		if (!TranslateAccelerator(hWnd, hAcc, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}
