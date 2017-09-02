/*	Создайте приложение «Убегающий статик».В окне должен быть расположен
статический элемент управления(статик).Когда пользователь пытается подвести
курсор мыши к «статику», то, если курсор находится близко со «статиком», элемент
управления «убегает».Предусмотрите перемещение «статика» только в пределах
окна. */


#include <Windows.h>
#include <cmath>

const int windowWidth = 1000;
const int windowHeight = 600;

const int staticWidth = 60;
const int staticHeight = 50;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hStatic;

	static int xPosStatic = 400;
	static int yPosStatic = 300;

	int changingXPosStatic = 0;
	int changingYPosStatic = 0;
	
	static int xPushCount = 0;
	static int yPushCount = 0;

	static int level = 20;
	
	int deltaX;
	int deltaY;
	int distance;

	switch (uMsg)
	{
	case WM_CREATE:
		hStatic = CreateWindowEx(NULL, L"STATIC", NULL, WS_CHILD | WS_VISIBLE, xPosStatic, yPosStatic, staticWidth, staticHeight, hWnd, (HMENU)NULL, GetModuleHandle(NULL), NULL);
		break;
	case WM_MOUSEMOVE:
		wchar_t buff[30];
		memset(buff, 0, sizeof(buff));
		wsprintf(buff, L"  CLICK\t      ME!\nLevel:%i", level);
		SetWindowText(hStatic, buff);

		deltaX = xPosStatic + staticWidth / 2 - LOWORD(lParam);
		deltaY = yPosStatic + staticHeight / 2 - HIWORD(lParam);
		distance = (int)std::hypot(deltaX, deltaY);

		if (distance < level * 10)
		{
			if (deltaX * deltaY > 0)
			{
				changingXPosStatic = level * 10 / deltaY;
				changingYPosStatic = level * 10 / deltaX;
			}
			else if (deltaX * deltaY < 0)
			{
				changingXPosStatic = -(level * 10 / deltaY);
				changingYPosStatic = -(level * 10 / deltaX);
			}
			else if (deltaX == 0 && deltaY != 0)
			{
				changingYPosStatic = level * 10 / deltaY;
			}
			else if (deltaY == 0 && deltaX != 0)
			{
				changingXPosStatic = level * 10 / deltaX;
			}

			if (xPushCount > 0)
			{
				changingXPosStatic = 2;
				xPushCount--;
			}
			else if (xPushCount < 0)
			{
				changingXPosStatic = -2;
				xPushCount++;
			}
			if (yPushCount > 0)
			{
				changingYPosStatic = 2;
				yPushCount--;
			}
			else if (yPushCount < 0)
			{
				changingYPosStatic = -2;
				yPushCount++;
			}

			if (changingXPosStatic > 5)
				changingXPosStatic = 5;
			else if (changingXPosStatic < -5)
				changingXPosStatic = -5;
			if (changingYPosStatic > 5)
				changingYPosStatic = 5;
			else if (changingYPosStatic < -5)
				changingYPosStatic = -5;

			if (xPosStatic + changingXPosStatic >= 0 && xPosStatic + changingXPosStatic <= windowWidth - staticWidth)
				xPosStatic += changingXPosStatic;
			if (yPosStatic + changingYPosStatic >= 0 && yPosStatic + changingYPosStatic <= windowHeight - staticHeight)
				yPosStatic += changingYPosStatic;

			if (xPosStatic == 0)
				xPushCount = level * 10;
			else if (xPosStatic == windowWidth - staticWidth)
				xPushCount = -level * 10;
			if (yPosStatic == 0)
				yPushCount = level * 10;
			else if(yPosStatic == windowHeight - staticHeight)
				yPushCount = -level * 10;
		}
		MoveWindow(hStatic, xPosStatic, yPosStatic, staticWidth, staticHeight, true);
		break;
	case WM_LBUTTONDOWN:
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		InvalidateRect(hWnd, NULL, true);
		if (LOWORD(lParam) >= xPosStatic && LOWORD(lParam) <= xPosStatic + staticWidth && HIWORD(lParam) >= yPosStatic && HIWORD(lParam) <= yPosStatic + staticHeight)
		{
			level++;
			if (MessageBox(hWnd, L"Продолжить?", L"Инфо", MB_YESNO) == IDNO)
			{
				SendMessage(hWnd, WM_DESTROY, 0, 0);
			}
		}
		break;
	case WM_CLOSE:
		if (MessageBox(hWnd, L"Вы действительно хотите выйти?", L"Инфо", MB_YESNO) == IDYES)
		{
			SendMessage(hWnd, WM_DESTROY, 0, 0);
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
	HWND hWnd;
	WNDCLASSEX wnd;
	memset(&wnd, 0, sizeof(wnd));

	wnd.cbSize = sizeof(wnd);
	wnd.lpszClassName = L"Window";
	wnd.style = CS_HREDRAW | CS_VREDRAW;
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;

	if (!RegisterClassEx(&wnd))
	{
		return 1;
	}

	hWnd = CreateWindowEx(NULL, wnd.lpszClassName, L"Убегающий статик", WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME, 
		CW_USEDEFAULT, CW_USEDEFAULT, windowWidth + 17, windowHeight + 40, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return 2;
	}

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}