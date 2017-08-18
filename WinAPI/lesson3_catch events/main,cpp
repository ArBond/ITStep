#include <windows.h>
#include <tchar.h>
#include <time.h>
#include "lesson3\resource.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	int x, y;
	switch (uMessage)
	{
	case WM_LBUTTONDBLCLK:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		MoveWindow(hWnd, x, y, 300, 300, true);
		SendMessage(hWnd, WM_CLOSE, 0, 0);
		break;
	case WM_CREATE:
			srand(time(0));
			SetTimer(hWnd, 1, 200, NULL);
			break;
	case WM_TIMER:
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
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
		KillTimer(hWnd, 1);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	WNDCLASSEX wnd;
	memset(&wnd, 0, sizeof(wnd));

	LPTSTR szClassName = _TEXT("Window");

	wnd.cbSize = sizeof(wnd);
	wnd.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(102));
	wnd.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(102));
	wnd.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(103));
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = szClassName;
	wnd.hIconSm = LoadIcon(NULL, IDI_HAND);
	wnd.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;

	if(!RegisterClassEx(&wnd))
	{
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	HWND hWnd = CreateWindowEx(WS_EX_WINDOWEDGE, szClassName, _TEXT("Hello"), WS_OVERLAPPEDWINDOW | WS_VISIBLE| WS_MAXIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, HWND_DESKTOP, NULL, hInstance, NULL);

	if(!hWnd)
	{
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK | MB_ICONERROR);
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
