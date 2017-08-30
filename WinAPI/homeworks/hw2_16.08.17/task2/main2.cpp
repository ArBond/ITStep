/*	Напишите приложение, которое «угадывает» задуманное пользователем число
от 1 до 100. Для запроса к пользователю используйте окна сообщений.Оформите их
подходящим образом. */

#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		MessageBox(hWnd, L"Go?", L"123", MB_YESNOCANCEL);
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
	HWND hWnd;
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

	hWnd = CreateWindowEx(WS_EX_TOPMOST, wnd.lpszClassName, L"1", WS_OVERLAPPEDWINDOW, 300, 100, 200, 200, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return 2;
	}

	//ShowWindow(hWnd, 1);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}