#include <Windows.h>
#include <unordered_set>
#include <vector>
#include <set>
#include <algorithm>
#include <time.h>

#include "resource.h"

#include "commctrl.h"
#pragma comment (lib, "comctl32")

#define ID_TIMER 300

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hEditNumbers, hProgressBar;
	static HWND hButtonNewGame, hButtonPause;
	static HWND hListGameTime;
	static HMENU hMenu, hSubMenuGame, hSubMenuInfo, hSubMenuDiapason, hSubMenuLevel;

	static std::unordered_set<int> numbers;
	static std::vector<int> sortNumbers;
	static std::set<HWND> hSortButtons;
	
	static int numberCount;
	static int buttonsLineQuantity = 4;
	static int range = 100;
	static int timeInMiliSec;
	static bool isPausePushed = false;
	static int countOfRedProgressBar = 0;

	switch (uMsg)
	{
	case WM_INITDIALOG:

		srand(time(0));
		hButtonNewGame = GetDlgItem(hWnd, IDC_BUTTON_NEWGAME);
		hEditNumbers = GetDlgItem(hWnd, IDC_EDIT_NUMBERS);
		hProgressBar = GetDlgItem(hWnd, IDC_PROGRESS);
		hButtonPause = GetDlgItem(hWnd, IDC_BUTTON_PAUSE);
		hListGameTime = GetDlgItem(hWnd, IDC_LIST_GAMETIME);

		hMenu = CreateMenu();

		hSubMenuLevel = CreatePopupMenu();
		AppendMenu(hSubMenuLevel, MF_STRING | MFT_RADIOCHECK, 21, L"Очень легко");
		AppendMenu(hSubMenuLevel, MF_STRING | MFT_RADIOCHECK, 22, L"Легко");
		AppendMenu(hSubMenuLevel, MF_STRING | MFT_RADIOCHECK, 23, L"Средне");
		AppendMenu(hSubMenuLevel, MF_STRING | MFT_RADIOCHECK, 24, L"Сложно");
		AppendMenu(hSubMenuLevel, MF_STRING | MFT_RADIOCHECK, 25, L"Очень сложно");

		hSubMenuDiapason = CreatePopupMenu();
		AppendMenu(hSubMenuDiapason, MF_STRING | MFT_RADIOCHECK, 31, L"1-100");
		AppendMenu(hSubMenuDiapason, MF_STRING | MFT_RADIOCHECK, 32, L"1-1000");
		AppendMenu(hSubMenuDiapason, MF_STRING | MFT_RADIOCHECK, 33, L"1-10000");

		hSubMenuGame = CreatePopupMenu();
		AppendMenu(hSubMenuGame, MF_STRING, ID_GAME_NEWGAME, L"Новая игра\tCtrl+N");
		AppendMenu(hSubMenuGame, MF_STRING, ID_GAME_EXIT, L"Закрыть\tCrtl+X");
		AppendMenu(hSubMenuGame, MF_SEPARATOR, 0, 0);
		AppendMenu(hSubMenuGame, MF_POPUP, (UINT_PTR)hSubMenuLevel, L"Сложность");
		AppendMenu(hSubMenuGame, MF_POPUP, (UINT_PTR)hSubMenuDiapason, L"Диапазон");

		hSubMenuInfo = CreatePopupMenu();
		AppendMenu(hSubMenuInfo, MF_STRING, ID_ABOUT, L"О программе\tCtrl+O");
		AppendMenu(hSubMenuInfo, MF_STRING, ID_AUTHOR, L"Автор\tCtrl+A");

		AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenuGame, L"Игра");
		AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenuInfo, L"Инфо");

		SetMenu(hWnd, hMenu);

		CheckMenuRadioItem(hMenu, 21, 25, 22, MF_CHECKED);
		CheckMenuRadioItem(hMenu, 31, 33, 31, MF_CHECKED);

		SendMessage(hListGameTime, LB_ADDSTRING, 0, (LPARAM)L"10");
		SendMessage(hListGameTime, LB_ADDSTRING, 0, (LPARAM)L"20");
		SendMessage(hListGameTime, LB_ADDSTRING, 0, (LPARAM)L"30");
		SendMessage(hListGameTime, LB_ADDSTRING, 0, (LPARAM)L"40");
		SendMessage(hListGameTime, LB_ADDSTRING, 0, (LPARAM)L"50");
		SendMessage(hListGameTime, LB_ADDSTRING, 0, (LPARAM)L"60");
		SendMessage(hListGameTime, LB_ADDSTRING, 0, (LPARAM)L"80");
		SendMessage(hListGameTime, LB_ADDSTRING, 0, (LPARAM)L"100");
		SendMessage(hListGameTime, LB_ADDSTRING, 0, (LPARAM)L"120");
		SendMessage(hListGameTime, LB_ADDSTRING, 0, (LPARAM)L"150");
		SendMessage(hListGameTime, LB_ADDSTRING, 0, (LPARAM)L"180");
		SendMessage(hListGameTime, LB_SETCURSEL, 0, 0);

		return true;

	case WM_CTLCOLORSTATIC:

		if ((HWND)lParam == hEditNumbers)
		{
			SetBkColor((HDC)wParam, RGB(255, 255, 255));
			return (LRESULT)CreateSolidBrush(RGB(255, 255, 255));
		}
		return true;

	case WM_TIMER:

		SendMessage(hProgressBar, PBM_DELTAPOS, 1, 0);
		timeInMiliSec--;
		if (countOfRedProgressBar == 0)
			SendMessage(hProgressBar, PBM_SETBARCOLOR, 0, RGB(0, 220, 0));
		else
			countOfRedProgressBar--;
		if (timeInMiliSec <= 0)
		{
			KillTimer(hWnd, ID_TIMER);
			MessageBox(hWnd, L"Вы не справились :(", L"Info", MB_OK);
			SendMessage(hProgressBar, PBM_SETPOS, 0, 0);
			EnableWindow(hButtonPause, false);
			for (auto it : hSortButtons)
				ShowWindow(it, SW_HIDE);
		}
		return true;

	case WM_COMMAND:

		if (LOWORD(wParam) == IDC_BUTTON_NEWGAME)
		{
			if (SendMessage(hProgressBar, PBM_GETPOS, 0, 0) != 0)
			{
				if(MessageBox(hWnd, L"Вы действительно хотите закрыть эту игру и начать новую?", L"Info", MB_YESNO) == IDNO)
					return true;
			}
			SendMessage(hProgressBar, PBM_SETPOS, 0, 0);
			SendMessage(hProgressBar, PBM_SETBARCOLOR, 0, RGB(0, 220, 0));
			wchar_t buff[5];
			int idx = SendMessage(hListGameTime, LB_GETCURSEL, 0, 0);
			SendMessage(hListGameTime, LB_GETTEXT, idx, (LPARAM)buff);
			timeInMiliSec = _wtoi(buff) * 10;
			SendMessage(hProgressBar, PBM_SETRANGE, 0, MAKELPARAM(0, timeInMiliSec));
			SetTimer(hWnd, ID_TIMER, 100, NULL);
			numberCount = 0;
			SetWindowText(hEditNumbers, L"");
			EnableWindow(hButtonPause, true);

			for (auto it : hSortButtons)
				DestroyWindow(it);

			numbers.clear();
			while (numbers.size() < buttonsLineQuantity * buttonsLineQuantity)
				numbers.insert(rand() % range + 1);

			sortNumbers.clear();
			for (auto it : numbers)
				sortNumbers.push_back(it);

			std::sort(sortNumbers.begin(), sortNumbers.end());

			auto itNumbers = numbers.begin();
			hSortButtons.clear();
			for (size_t i = 0; i < buttonsLineQuantity; i++)
			{
				for (size_t j = 0; j < buttonsLineQuantity; j++)
				{
					wchar_t numberBuff[10];
					wsprintf(numberBuff, L"%i", *(itNumbers++));
					hSortButtons.insert(CreateWindowEx(NULL, L"BUTTON", numberBuff, WS_CHILD | WS_VISIBLE,
						j * 300 / buttonsLineQuantity + 12, i * 300 / buttonsLineQuantity + 15, 300 / buttonsLineQuantity - 8, 300 / buttonsLineQuantity - 8,
						hWnd, HMENU(NULL), GetModuleHandle(NULL), NULL));
				}
			}
		}
		else if (LOWORD(wParam) == IDC_BUTTON_PAUSE)
		{
			if (isPausePushed)
			{
				for (auto it : hSortButtons)
					ShowWindow(it, SW_SHOW);

				SetTimer(hWnd, ID_TIMER, 100, 0);
			}
			else
			{
				for (auto it : hSortButtons)
					ShowWindow(it, SW_HIDE);

				KillTimer(hWnd, ID_TIMER);
			}
			isPausePushed = !isPausePushed;
		}
		else if(hSortButtons.find((HWND)lParam) != hSortButtons.end())
		{
			wchar_t numberBuff[10];
			GetWindowText((HWND)lParam, numberBuff, sizeof(numberBuff));
			if (_wtoi(numberBuff) == sortNumbers[numberCount])
			{
				if (++numberCount == buttonsLineQuantity * buttonsLineQuantity)
				{
					KillTimer(hWnd, ID_TIMER);
					MessageBox(hWnd, L"Поздравляю вы справились!", L"Info", MB_OK);
					SendMessage(hProgressBar, PBM_SETPOS, 0, 0);
					EnableWindow(hButtonPause, false);
					for (auto it : hSortButtons)
						ShowWindow(it, SW_HIDE);
				}
				EnableWindow((HWND)lParam, false);
				LONG len = SendMessageA(hEditNumbers, WM_GETTEXTLENGTH, 0, 0);
				wchar_t* numbersEditBuff = new wchar_t[len + 10];
				memset(numbersEditBuff, 0, len + 10);
				GetWindowText(hEditNumbers, numbersEditBuff, len);
				wcscat(numbersEditBuff, numberBuff);
				wcscat(numbersEditBuff, L"\r\n\r");
				SetWindowText(hEditNumbers, numbersEditBuff);
				delete[] numbersEditBuff;
			}
			else
			{
				timeInMiliSec -= 15;
				SendMessage(hProgressBar, PBM_DELTAPOS, 15, 0);
				SendMessage(hProgressBar, PBM_SETBARCOLOR, 0, RGB(220, 0, 0));
				countOfRedProgressBar = 5;
			}
		}
		else if (LOWORD(wParam) == ID_GAME_NEWGAME)
			SendMessage(hWnd, WM_COMMAND, MAKEWPARAM(IDC_BUTTON_NEWGAME, BN_CLICKED), (LPARAM)hButtonNewGame);
		else if (LOWORD(wParam) == ID_GAME_EXIT)
			SendMessage(hWnd, WM_CLOSE, 0, 0);
		else if (LOWORD(wParam) == ID_ABOUT)
			MessageBox(hWnd, L"Это очень крутая игрушка!\n Версия: 1.00\n Дата: 06.09.17", L"О программе", MB_OK);
		else if (LOWORD(wParam) == ID_AUTHOR)
			MessageBox(hWnd, L"Очень скромный парень!\nВеб сайт: https://vk.com/id73128569 \nПочта: bon_artem@mail.ru", L"Автор", MB_OK);
		else if (LOWORD(wParam) >= 21 && LOWORD(wParam) <= 25)
		{
			CheckMenuRadioItem(hMenu, 21, 25, LOWORD(wParam), MF_CHECKED);
			if(LOWORD(wParam) == 21)
				buttonsLineQuantity = 3;
			else if(LOWORD(wParam) == 22)
				buttonsLineQuantity = 4;
			else if (LOWORD(wParam) == 23)
				buttonsLineQuantity = 5;
			else if (LOWORD(wParam) == 24)
				buttonsLineQuantity = 6;
			else if (LOWORD(wParam) == 25)
				buttonsLineQuantity = 7;
		}
		else if (LOWORD(wParam) >= 31 && LOWORD(wParam) <= 33)
		{
			CheckMenuRadioItem(hMenu, 31, 33, LOWORD(wParam), MF_CHECKED);
			if (LOWORD(wParam) == 31)
				range = 100;
			else if (LOWORD(wParam) == 32)
				range = 1000;
			else if (LOWORD(wParam) == 33)
				range = 10000;
		}

		return true;

	case WM_CLOSE:

		if (MessageBox(hWnd, L"Вы действительно хотите выйти?", L"Info", MB_YESNO) == IDYES)
		{
			DestroyWindow(hWnd);
			PostQuitMessage(0);
		}

		return true;

	default:
		return false;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	LoadLibrary(L"Riched20.dll");
	HACCEL hAcc = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR1));

	INITCOMMONCONTROLSEX cc;
	cc.dwSize = sizeof(cc);
	cc.dwICC = ICC_PROGRESS_CLASS;
	InitCommonControlsEx(&cc); 

	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG), NULL, DlgProc);

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