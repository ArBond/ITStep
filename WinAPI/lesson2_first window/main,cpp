#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//HDC hdc;   // <- для рисование в окне
	//PAINTSTRUCT ps;
	//RECT rect;

	switch (iMsg) 
	{
	case WM_PAINT:
		// ...  <-  рисование в окне
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, iMsg, wParam, lParam);

	}

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	WNDCLASSEX wndclass;
	memset(&wndclass, 0, sizeof(wndclass));

	LPTSTR szClassName = _TEXT("FirstWindowClass");
	LPTSTR szTitleName = _TEXT("My first window");

	wndclass.cbSize = sizeof(wndclass);
	wndclass.lpszClassName = szClassName;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	//wndclass.cbClsExtra = 0;
	//wndclass.cbWndExtra = 0;

	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;

	//wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	//wndclass.lpszMenuName = NULL;

	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // или CreateSolidBrush(RGB(0, 0, 0));

	if (!RegisterClassEx(&wndclass))
	{
		return 1;
	}

	HWND hWnd = CreateWindowEx(WS_EX_TOPMOST, szClassName, szTitleName, WS_OVERLAPPEDWINDOW,
		500, 300, 1000, 500, NULL, NULL, hInstance, NULL);   //   <- создам окно

	if (!hWnd)
	{
		return 2;
	}

	int WINAPI MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType);
	MessageBoxW(NULL, L"You  are sure!", L"MessageBox", MB_YESNO | MB_ICONQUESTION);

	ShowWindow(hWnd, 1);    // <- показываем окно
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))  // <- цикл обработки сообщений
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
