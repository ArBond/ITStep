/*	—оздайте приложение, в котором будут отображатьс€ четыре окна.¬се окна
должны иметь разные заголовки и разный цвет фона.
»змените приложение таким образом, чтобы каждое окно, кроме первого,
по€вл€лось по таймеру. */

#include <Windows.h>

#define ID_TIMER1 100
#define ID_TIMER2 102
#define ID_TIMER3 103

HWND hWnd1;
HWND hWnd2;
HWND hWnd3;
HWND hWnd4;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		SetTimer(hWnd, ID_TIMER1, 1000, NULL);
		SetTimer(hWnd, ID_TIMER2, 2000, NULL);
		SetTimer(hWnd, ID_TIMER3, 3000, NULL);
		break;
	case WM_TIMER:
		switch(wParam)
		{
		case ID_TIMER1:
			ShowWindow(hWnd2, 1);
			KillTimer(hWnd, ID_TIMER1);
			break;
		case ID_TIMER2:
			ShowWindow(hWnd3, 1);
			KillTimer(hWnd, ID_TIMER2);
			break;
		case ID_TIMER3:
			ShowWindow(hWnd4, 1);
			KillTimer(hWnd, ID_TIMER3);
			break;
		default:
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	WNDCLASSEX wnd1;
	WNDCLASSEX wnd2;
	WNDCLASSEX wnd3;
	WNDCLASSEX wnd4;

	memset(&wnd1, 0, sizeof(wnd1));
	wnd1.cbSize = sizeof(wnd1);
	wnd1.lpszClassName = L"Window1";
	wnd1.hbrBackground = CreateSolidBrush(RGB(255, 0, 0));
	wnd1.lpfnWndProc = WndProc;
	wnd1.hInstance = hInstance;

	wnd2 = wnd1;
	wnd2.lpszClassName = L"Window2";
	wnd2.hbrBackground = CreateSolidBrush(RGB(0, 255, 0));

	wnd3 = wnd1;
	wnd3.lpszClassName = L"Window3";
	wnd3.hbrBackground = CreateSolidBrush(RGB(0, 0, 255));

	wnd4 = wnd1;
	wnd4.lpszClassName = L"Window4";
	wnd4.hbrBackground = CreateSolidBrush(RGB(255, 255, 0));


	if (!(RegisterClassEx(&wnd1) && RegisterClassEx(&wnd2) && RegisterClassEx(&wnd3) && RegisterClassEx(&wnd4)))
	{
		return 1;
	}

	hWnd1 = CreateWindowEx(WS_EX_TOPMOST, wnd1.lpszClassName, L"1", WS_OVERLAPPEDWINDOW, 300, 100, 200, 200, NULL, NULL, hInstance, NULL);
	hWnd2 = CreateWindowEx(WS_EX_TOPMOST, wnd2.lpszClassName, L"2", WS_OVERLAPPEDWINDOW, 500, 100, 200, 200, NULL, NULL, hInstance, NULL);
	hWnd3 = CreateWindowEx(WS_EX_TOPMOST, wnd3.lpszClassName, L"3", WS_OVERLAPPEDWINDOW, 300, 300, 200, 200, NULL, NULL, hInstance, NULL);
	hWnd4 = CreateWindowEx(WS_EX_TOPMOST, wnd4.lpszClassName, L"4", WS_OVERLAPPEDWINDOW, 500, 300, 200, 200, NULL, NULL, hInstance, NULL);

	if (!(hWnd1 && hWnd2 && hWnd3 && hWnd1))
	{
		return 2;
	}

	ShowWindow(hWnd1, 1);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}