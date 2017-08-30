/*	—оздайте приложение, в котором будут отображатьс€ четыре окна.¬се окна
должны иметь разные заголовки и разный цвет фона.
»змените приложение таким образом, чтобы каждое окно, кроме первого,
по€вл€лось по таймеру. */

#include <Windows.h>

#define ID_TIMER 1014

HWND hWnd1;
HWND hWnd2;
HWND hWnd3;
HWND hWnd4;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static int timerCount = 0;

	switch (uMsg)
	{
	case WM_CREATE:
		SetTimer(hWnd, ID_TIMER, 1000, NULL);
		break;
	case WM_TIMER:
		timerCount++;
		switch(timerCount)
		{
		case 1:
			SetClassLong(hWnd2, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(255, 0, 0)));
			ShowWindow(hWnd2, 1);
			break;
		case 5:
			SetClassLong(hWnd3, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(0, 0, 255)));
			ShowWindow(hWnd3, 1);
			break;
		case 9:
			SetClassLong(hWnd4, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(0, 255, 0)));
			ShowWindow(hWnd4, 1);
			break;
		default:
			break;
		}
		break;
	case WM_DESTROY:
		KillTimer(hWnd, ID_TIMER);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	WNDCLASSEX wnd;
	memset(&wnd, 0, sizeof(wnd));

	wnd.cbSize = sizeof(wnd);
	wnd.lpszClassName = L"WINDOW";
	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;

	if (!RegisterClassEx(&wnd))
	{
		return 1;
	}

	hWnd1 = CreateWindowEx(WS_EX_TOPMOST, wnd.lpszClassName, L"1", WS_OVERLAPPEDWINDOW, 300, 100, 200, 200, NULL, NULL, hInstance, NULL);
	hWnd2 = CreateWindowEx(WS_EX_TOPMOST, wnd.lpszClassName, L"2", WS_OVERLAPPEDWINDOW, 500, 100, 200, 200, NULL, NULL, hInstance, NULL);
	hWnd3 = CreateWindowEx(WS_EX_TOPMOST, wnd.lpszClassName, L"3", WS_OVERLAPPEDWINDOW, 300, 300, 200, 200, NULL, NULL, hInstance, NULL);
	hWnd4 = CreateWindowEx(WS_EX_TOPMOST, wnd.lpszClassName, L"4", WS_OVERLAPPEDWINDOW, 500, 300, 200, 200, NULL, NULL, hInstance, NULL);

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