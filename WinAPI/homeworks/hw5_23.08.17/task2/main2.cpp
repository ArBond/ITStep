/*	Создайте программу для просмотра картинок на основе модального или
немодального диалогового окна.
На форме должно быть два флажка, два переключателя и две обычные кнопки :
С помощью флажков пользователь выбирает, какие изображения
демонстрируются(можно использовать изображения из папки Img).
Обратите внимание, что одновременно могут быть установлены оба
флажка.
С помощью переключателей задается скорость, с которой сменяются
изображения.
По нажатию на кнопку «Старт» начинается показ картинок, по нажатию
на кнопку «Стоп» демонстрация останавливается.
Дополнительно можно запретить максимизацию окна. */



#include <Windows.h>
#include <vector>
#include <algorithm>

#include "resource.h"

#define ID_TIMER 100

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hCheckCats, hCheckDogs;
	static HWND hRadioFast, hRadioSlow;
	static HWND hButtonStart;
	static HWND hPicture;

	BITMAP bm;
	PAINTSTRUCT ps;
	HDC hdc, hdcMem;
	HGDIOBJ oldBitmap;

	static std::vector<HBITMAP> cats;
	static std::vector<HBITMAP> dogs;
	static std::vector<HBITMAP> pets;

	static int count = 0;

	switch (uMsg)
	{
	case WM_INITDIALOG:

		hCheckCats = GetDlgItem(hWnd, IDC_CHECKCATS);
		hCheckDogs = GetDlgItem(hWnd, IDC_CHECKDOGS);
		hRadioFast = GetDlgItem(hWnd, IDC_RADIOFAST);
		hRadioSlow = GetDlgItem(hWnd, IDC_RADIOSLOW);
		hButtonStart = GetDlgItem(hWnd, IDC_BUTTONSTART);
		hPicture = GetDlgItem(hWnd, IDC_PICTURE);

		SendMessage(hRadioSlow, BM_SETCHECK, BST_CHECKED, 0);
		SendMessage(hCheckCats, BM_SETCHECK, BST_CHECKED, 0);

		cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1)));
		cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2)));
		cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP3)));
		cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP4)));
		cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP5)));
		dogs.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP6)));
		dogs.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP7)));
		dogs.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP8)));
		dogs.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP9)));
		dogs.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP10)));

		pets = cats;

		return true;
	case WM_PAINT:
		hdc = BeginPaint(hPicture, &ps);

		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, pets[count]);
		GetObject(pets[count], sizeof(bm), (LPSTR)&bm);
		BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);

		EndPaint(hPicture, &ps);
		return false;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTONSTART:
			if (SendMessage(hCheckCats, BM_GETCHECK, 0, 0) && SendMessage(hCheckDogs, BM_GETCHECK, 0, 0))
			{
				pets = cats;
				for (size_t i = 0; i < dogs.size(); i++)
				{
					pets.push_back(dogs[i]);
				}
				std::random_shuffle(pets.begin(), pets.end());
			}
			else if (SendMessage(hCheckCats, BM_GETCHECK, 0, 0))
				pets = cats;
			else if (SendMessage(hCheckDogs, BM_GETCHECK, 0, 0))
				pets = dogs;

			if (SendMessage(hRadioFast, BM_GETCHECK, 0, 0))
				SetTimer(hWnd, ID_TIMER, 1000, 0);
			else
				SetTimer(hWnd, ID_TIMER, 3000, 0);
			break;
		case IDC_BUTTONSTOP:
			KillTimer(hWnd, ID_TIMER);
			break;
		case IDC_CHECKCATS:
		case IDC_CHECKDOGS:
			if (SendMessage(hCheckCats, BM_GETCHECK, 0, 0) || SendMessage(hCheckDogs, BM_GETCHECK, 0, 0))
				EnableWindow(hButtonStart, true);
			else
				EnableWindow(hButtonStart, false);

		}
		return true;		
	case WM_TIMER:
		count++;
		if (count >= pets.size())
			count = 0;
		InvalidateRect(NULL, NULL, true);
		return true;
	case WM_CLOSE:
		if (MessageBox(hWnd, L"Вы действительно хотите выйти?", L"Info", MB_YESNO) == IDYES)
		{
			DestroyWindow(hWnd);
			PostQuitMessage(0);
		}
		return true;
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG), NULL, DlgProc);
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