/*	Создайте приложение, которое будет проверять : (1) являются ли анаграммами
две строки, введенные пользователем; (2) является ли палиндромом единственная
строка, введенная пользователем.Два слова называются анаграммами, если они
состоят из одинаковых символов(например, апельсин и спаниель или тавро и отвар).
Слово называется палиндромом, если оно читается слева направо и справа налево
одинаково(например, поток или заказ).
	Окно должно содержать следующие элементы управления, созданные
программно :
		Статики(класс Static) для надписей и для вывода результата.
		Два текстовых поля типа Edit для ввода строк.
		Два переключателя для выбора условия, на соответствие которому
	проверяются строки(или строка).Когда выбран переключатель
	«Анаграмма», оба текстовых поля должны быть доступны для ввода, а
	когда выбран переключатель «Палиндром» – только первое текстовое
	поле.
		Две кнопки.По нажатию на первую кнопку в статик посылается
	результат проверки.По нажатию на вторую кнопку текстовые поля и
	статик с результатом очищаются. */


#include <Windows.h>
#include <locale.h>

#include "resource.h"

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hEditWord1, hEditWord2, hStaticResult;
	static HWND hRadioAnagram, hRadioPalindrom;

	switch (uMsg)
	{
	case WM_INITDIALOG:
		hEditWord1 = GetDlgItem(hWnd, IDC_EDITFIRSTWORD);
		hEditWord2 = GetDlgItem(hWnd, IDC_EDITSECONDWORD);
		hRadioAnagram = GetDlgItem(hWnd, IDC_RADIOANAGRAM);
		hRadioPalindrom = GetDlgItem(hWnd, IDC_RADIOPALINDROM);
		hStaticResult = GetDlgItem(hWnd, IDC_STATICRESULT);

		SendMessage(hRadioAnagram, BM_SETCHECK, BST_CHECKED, 0);
		return true;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTONCHECK:
		{
			wchar_t word1buff[100];
			int len1 = SendMessage(hEditWord1, WM_GETTEXTLENGTH, 0, 0) + 1;
			GetWindowText(hEditWord1, word1buff, len1);

			for (int i = 0; i < len1; i++)
			{
				if (word1buff[i] >= 'A' && word1buff[i] <= 'Z')
					word1buff[i] += 'z' - 'Z';
				else if (word1buff[i] >= 1040 && word1buff[i] <= 1071) // русские а и я в юникоде
					word1buff[i] += 32;
			}

			if (SendMessage(hRadioAnagram, BM_GETCHECK, 0, 0) == BST_CHECKED)
			{
				wchar_t word2buff[100];
				int len2 = SendMessage(hEditWord2, WM_GETTEXTLENGTH, 0, 0) + 1;
				GetWindowText(hEditWord2, word2buff, len2);

				for (int i = 0; i < len1; i++)
				{
					if (word2buff[i] >= 'A' && word2buff[i] <= 'Z')
						word2buff[i] += 'z' - 'Z';
					else if (word2buff[i] >= 1040 && word2buff[i] <= 1071)
						word2buff[i] += 32;
				}

				if (len1 == len2)
				{
					for (int i = 1; i < len1 - 1; i++)
					{
						for (int j = i; j > 0 && word1buff[j - 1] > word1buff[j]; j--)
						{
							wchar_t buff = word1buff[j - 1];
							word1buff[j - 1] = word1buff[j];
							word1buff[j] = buff;
						}
						for (int j = i; j > 0 && word2buff[j - 1] > word2buff[j]; j--)
						{
							wchar_t buff = word2buff[j - 1];
							word2buff[j - 1] = word2buff[j];
							word2buff[j] = buff;
						}
					}
					if (wcscmp(word1buff, word2buff) == 0)
						SetWindowText(hStaticResult, L"Анаграммы");
					else
						SetWindowText(hStaticResult, L"Не анаграммы");
				}
				else
				{
					SetWindowText(hStaticResult, L"Не анаграммы");
				}
			}
			else
			{
				SetWindowText(hStaticResult, L"Палиндром");
				for (int i = 0; i < len1 / 2; i++)
				{
					if (word1buff[i] != word1buff[len1 - 2 - i])
					{
						SetWindowText(hStaticResult, L"Не палиндром");
						break;
					}
				}
			}
			break;
		}
		case IDC_BUTTONCLEAR:
			SetWindowText(hEditWord1, L"");
			SetWindowText(hEditWord2, L"");
			SetWindowText(hStaticResult, L"");
			break;
		case IDC_RADIOANAGRAM:
			SendMessage(hEditWord2, EM_SETREADONLY, false, 0);
			break;
		case IDC_RADIOPALINDROM:
			SendMessage(hEditWord2, EM_SETREADONLY, true, 0);
			break;
		default:
			break;
		}
		return true;
	case WM_CLOSE:
		if (MessageBox(hWnd, L"Вы действительно хотите выйти?", L"Info", MB_YESNO) == IDYES)
		{
			DestroyWindow(hWnd);
			PostQuitMessage(0);
			return true;
		}
	default:
		return false;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	setlocale(LC_ALL, "Russian");
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