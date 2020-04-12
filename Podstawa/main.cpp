#include <Windows.h>
#include <d2d1.h>
#include "Graphics.h"
#include "Level1.h"
#include "GameController.h"

Graphics* graphics;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}
	/*if (uMsg == WM_PAINT)
	{
		graphics->BeginDraw();

		graphics->ClearScreen(0.0f, 0.0f, 0.5f);
		for (int i = 0; i < 400; i++)
		{
			graphics->DrawCircle(400,550-i, 50, 1.0f, 0.7, 0.4, 1.0);
		}
		graphics->EndDraw();
	}*/
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, int nCmdShow)
{
	WNDCLASSEX windowsclass;
	ZeroMemory(&windowsclass, sizeof(WNDCLASSEX));
	windowsclass.cbSize = sizeof(WNDCLASSEX);
	windowsclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowsclass.hInstance = hInstance;
	windowsclass.lpfnWndProc = WindowProc;
	windowsclass.lpszClassName = "MainWindow";
	windowsclass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&windowsclass);

	RECT rect = { 0,0,800,600 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_OVERLAPPEDWINDOW);

	HWND windowhandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MainWindow", "DirectXTut!", WS_OVERLAPPEDWINDOW, 100, 100, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);

	if (!windowhandle) return -1;

	graphics = new Graphics();
	if (!graphics->Init(windowhandle))
	{
		delete graphics;
		return -1;
	}

	ShowWindow(windowhandle, nCmdShow);

	GameController::LoadInitialLevel(new Level1());

	MSG message;
	message.message = WM_NULL;
	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
			DispatchMessage(&message);
		else
		{
			//update
			GameController::Update();
			
			//render
			graphics->BeginDraw();

			GameController::Render(graphics);
		
			graphics->EndDraw();
		}
	}
	/*MSG message;
	while (GetMessage(&message, NULL, 0, 0))
	{
		DispatchMessage(&message);
	}*/
	delete graphics;
	return 0;
}