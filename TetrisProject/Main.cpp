#include <Windows.h>
#include "Graphics.h"
#include "GameController.h"

#include "StraitBlock.h"
#include "SquareBlock.h"
#include "TBlock.h"
#include "LBlock.h"
#include "JBlock.h"
#include "ZBlock.h"
#include "SBlock.h"
#include "GameConstants.cpp"

Graphics* graphics;


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// the entry point for any Windows program
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX windowClass;
	ZeroMemory(&windowClass, sizeof(WNDCLASSEX));
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
	windowClass.hInstance = hInstance;
	windowClass.lpfnWndProc = WindowProc;
	windowClass.lpszClassName = "MainWindow";
	windowClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&windowClass);
	
	RECT rect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, windowClass.lpszClassName, "Tetris Project", WS_OVERLAPPEDWINDOW, 50, 100, (rect.right-rect.left), (rect.bottom-rect.top), NULL, NULL, hInstance, NULL);

	if (windowHandle == NULL)
	{
		return -1;
	}

	graphics = new Graphics();

	if (graphics->Init(windowHandle) == false)
	{
		delete graphics;
		return -1;
	}


	ShowWindow(windowHandle, nCmdShow);

	MSG message;
	message.message = WM_NULL;

	GameController::Init();
	GameController::LoadInitialLevel(new StraitBlock());

	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			DispatchMessage(&message);
		}
		else
		{
			GameController::Update();
			// Render!
			graphics->BeginDraw();

			GameController::Render(graphics);

			graphics->EndDraw();

			if (GameController::FinishedBlock())
			{
				GameController::SwitchLevel(new StraitBlock());
			}
		}
	}
	delete graphics;

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}
	else if (uMsg == WM_KEYDOWN)
	{
		if (wParam == VK_LEFT)
		{
			GameController::Left();
		}
		else if (wParam == VK_RIGHT)
		{
			GameController::Right();
		}
		else if (wParam == VK_DOWN)
		{
			GameController::Down(true);
		}
		else if (wParam == VK_UP)
		{
			GameController::Up();
		}
		else if (wParam == VK_SPACE)
		{
			GameController::Drop();
		}
	}
	else if (uMsg == WM_KEYUP)
	{
		if (wParam == VK_DOWN)
		{
			GameController::Down(false);
		}
	}
	else
	{
		DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 1;
}