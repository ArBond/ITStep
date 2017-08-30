#include <windows.h>
#include <tchar.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPWSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wnd;
	wnd.cbSize = sizeof(wnd);
	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;
	wnd.hIcon = LoadIcon(NULL, IDI_QUESTION);
	wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	wnd.hbrBackground = GetStockObject(WHITE_BRUSH);
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = _TEXT("Window");
	wnd.hIconSm = LoadIcon(NULL, IDI_HAND);

	if(!RegisterClassEx(&wnd)){
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK|MB_ICONERROR);
		return 0;
	}

	hWnd = CreateWindowEx(WS_EX_WINDOWEDGE, _TEXT("Windоw"), TEXT("Hello"), WS_OVERLAPPED | WS_VISIBLE ^ WS_MAXIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		HWND_DESKTOP, NULL, hInstance, NULL);

	if(!hWnd){
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK|MB_ICONERROR);
		return 0;
	}

	ShowWindow(NULL, 1);
	UpdateWindow(hWnd);

	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
	}
	return msg.lParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch(uMessage)
	{
	case WM_CLOSE:
		if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES){
			DestroyWindow(NULL);
		}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, lParam, wParam);
	}
	return 0;
}