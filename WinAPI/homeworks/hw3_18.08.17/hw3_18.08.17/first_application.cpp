/*	1) Слушатель Глеб, пребывая в состоянии пьяной лени, попытался создать
оконное приложение под Windows(файл first_application.cpp), но оказалось,
что код не компилируется.Помогите Глебу отладить программу.
	2) Измените приложение следующим образом :
размеры окна 200х100(задаются как константы);
окно нельзя максимизировать;
окно нельзя свернуть.
	3) В приложении first_application замените иконку на myIcon.ico
или любую свою.
	4) Измените курсор в приложении на курсор, созданный самостоятельно с
помощью редактора ресурсов.
	5) Измените приложение first_application таким образом, чтобы спустя
10 секунд после запуска у пользователя спрашивалось, хочет ли он завершить работу.
	6) Настройте обработку сообщений мыши следующим образом :
по нажатию на левую кнопку мыши курсор приложения изменяется
на один из стандартных курсоров;
по двойному щелчку левой кнопкой мыши курсор приложения
изменяется на исходный;
по нажатию на правую кнопку мыши цвет фона меняется случайным
образом;
по двойному щелчку правой кнопкой мыши цвет фона изменяется на
белый.
* Получить дескриптор приложения можно с помощью функции
GetModuleHandle с аргументом NULL.
	7) Настройте обработку сообщений клавиатуры следующим образом :
по сочетанию клавиш Alt + ↓ окно сворачивается;
по сочетанию клавиш Alt + ↑ окно максимизируется;
по сочетанию клавиш Alt + ← или Alt + → окно показывается в
своем исходном размере;
по сочетанию клавиш Alt + F4 появляется диалоговое окно
с предложением завершить работу приложения;
по нажатию на клавишу Enter окно перемещается в правый верхний
угол рабочего стола и начинает перемещаться вдоль его границы с
постоянной скоростью;
по нажатию на клавишу Escape окно прекращает движение.
* Чтобы получить размеры рабочего стола, воспользуйтесь функцией
SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0).
	8) Настойте прорисовку в центре окна системного времени в формате
часы : минуты:секунды.Время должно обновляться каждую секунду.
* Чтобы вызвать обновление окна, вызовите следующую функцию :
RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW). */



#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include <time.h>
#include <ctime>

#define ID_TIMER_10_SEC 101
#define ID_TIMER_MOVEWINDOW 102
#define ID_TIMER_TIME 103

int const windowWidth = 200;
int const windowHeight = 100;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{

	RECT rect;

	HDC hdc;
	PAINTSTRUCT ps;

	static tm* tm;
	time_t currentTime;

	wchar_t timeStr[10];
	static int xPositionWindow = 0;

	switch (uMessage)
	{
	case WM_CREATE:
		srand(time_t(0));
		SetTimer(hWnd, ID_TIMER_10_SEC, 10000, NULL);
		SetTimer(hWnd, ID_TIMER_TIME, 1000, NULL);
		break;

	case WM_PAINT:
		currentTime = std::time(nullptr);
		tm = localtime(&currentTime);
		wsprintf(timeStr, L"%02i:%02i:%02i", tm->tm_hour, tm->tm_min, tm->tm_sec);

		hdc = BeginPaint(hWnd, &ps);

		GetClientRect(hWnd, &rect);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		DrawText(hdc, timeStr, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		EndPaint(hWnd, &ps);		
		break;

	case WM_TIMER:
		switch (LOWORD(wParam))
		{
		case ID_TIMER_10_SEC:
			KillTimer(hWnd, ID_TIMER_10_SEC);
			if (MessageBox(hWnd, _TEXT("Может вы хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES)
			{
				DestroyWindow(hWnd);
			}
			break;
		case ID_TIMER_MOVEWINDOW:
			MoveWindow(hWnd, --xPositionWindow, 0, windowWidth, windowHeight, true);
			if (xPositionWindow == 0)
			{
				KillTimer(hWnd, ID_TIMER_MOVEWINDOW);
			}
		case ID_TIMER_TIME:
			RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW);
			break;
		default:
			break;
		}
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RETURN:
			SetTimer(hWnd, ID_TIMER_MOVEWINDOW, 1, NULL);
			SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
			xPositionWindow = rect.right - windowWidth;
			MoveWindow(hWnd, xPositionWindow, 0, windowWidth, windowHeight, true);
			break;
		case VK_ESCAPE:
			KillTimer(hWnd, ID_TIMER_MOVEWINDOW);
			break;
		default:
			break;
		}

	case WM_SYSKEYDOWN:
		switch (wParam)
		{
		case VK_UP:
			ShowWindow(hWnd, SW_SHOWMAXIMIZED);
			break;
		case VK_DOWN:
			ShowWindow(hWnd, SW_SHOWMINIMIZED);
			break;
		case VK_LEFT:
		case VK_RIGHT:
			ShowWindow(hWnd, SW_SHOWDEFAULT);
			break;
		case VK_F4:
			if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES)
			{
				DestroyWindow(hWnd);
			}
			break;
		default:
			break;
		}
		break;

	case WM_LBUTTONDOWN:
		SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_ARROW));
		break;

	case WM_LBUTTONDBLCLK:
		SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1)));
		break;

	case WM_RBUTTONDOWN:
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_RBUTTONDBLCLK:
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(255, 255, 255)));
		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_CLOSE:
		if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES)
		{
			DestroyWindow(hWnd);
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wnd;

	memset(&wnd, 0, sizeof(wnd));

	wnd.cbSize = sizeof(wnd);
	wnd.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wnd.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wnd.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wnd.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wnd.lpszClassName = _TEXT("Window");
	wnd.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;

	if(!RegisterClassEx(&wnd))
	{
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK|MB_ICONERROR);
		return 0;
	}

	hWnd = CreateWindowEx(NULL, wnd.lpszClassName, TEXT("Hello"), WS_OVERLAPPEDWINDOW ^ WS_MINIMIZEBOX ^ WS_MAXIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, windowWidth, windowHeight, NULL, NULL, hInstance, NULL);

	if(!hWnd)
	{
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK|MB_ICONERROR);
		return 0;
	}

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}