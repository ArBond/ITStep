#include <windows.h>
#include <tchar.h>
#include <time.h>
#include "lesson3\resource.h"

#define WIDE_WINDOW 1920
#define HIDE_WINDOW 1080

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	TEXTMETRIC tm;

	static int height;
	int x, y;

	switch (uMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		SetTextColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
		SetBkMode(hdc, TRANSPARENT);
		SetTextCharacterExtra(hdc, 5);

		TextOut(hdc, 130, 170, L"Hello Friend!", 13);

		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN: 
		switch (wParam)
		{
		case VK_ESCAPE:
			SendMessage(hWnd, WM_CLOSE, NULL, NULL);
			break;
		case VK_RETURN:
			MoveWindow(hWnd, 0, 0, 400, 400, true);
			break;
		default:
			break;
		}
		break;
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
		default:
			break;
		}
		break;
	case WM_RBUTTONDOWN:
		SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_ARROW));
		break;
	case WM_RBUTTONDBLCLK:
		SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(103)));
		break;
	case WM_LBUTTONDBLCLK:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		MoveWindow(hWnd, rand() % (WIDE_WINDOW - 400), rand() % (HIDE_WINDOW - 400), 400, 400, true);
		break;
	case WM_CREATE:
		hdc = GetDC(hWnd);
		GetTextMetrics(hdc, &tm);
		height = 40;
		ReleaseDC(hWnd, hdc);

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
		CW_USEDEFAULT, CW_USEDEFAULT, 400, 400, HWND_DESKTOP, NULL, hInstance, NULL);

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
