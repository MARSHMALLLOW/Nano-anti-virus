#include <windows.h>
#include "Scanfunc.h"
#include "FileApi.h"
#include "stdafx.h"

LRESULT CALLBACK ScanhWnd(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	switch (Msg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0x00);
		break;
	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	return 0;
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
	LPSTR lpCommandLine, int nShowcLassmd)
{
	
	wcLass.cbSize = sizeof(WNDCLASS);
	wcLass.style = 0;
	wcLass.lpfnWndProc = ScanhWnd;
	wcLass.cbClsExtra = 0;
	wcLass.cbWndExtra = 0;
	wcLass.hInstance = hInst;
	wcLass.hIcon = LoadIcon(NULL, IDI_SHIELD);
	wcLass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcLass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcLass.lpszMenuName = NULL;
	wcLass.hIconSm = LoadIconA(NULL, IDI_SHIELD);
	wcLass.lpszClassName = Class;

	if (!RegisterClassEx(&wcLass)) {
		MessageBox(NULL, "Error: failed at registring scan window!", Class, MB_ICONERROR | MB_OK);
		return 1;
	}

	hwnd1 = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		Class,
		"Nano console",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 300, 250,
		NULL, NULL, hInst, NULL);

	HFONT font = (HFONT) DEFAULT_GUI_FONT;

	hwnd2 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT("input file"), WS_CHILD | WS_VISIBLE,
		120, 70, 100, 25, hwnd1, HMENU(NULL), GetModuleHandle(NULL), NULL);
	SendMessage(hwnd2, WM_SETFONT, (WPARAM)font, MAKELPARAM(TRUE, 0));

	if (hwnd1 == NULL) {
		MessageBox(NULL, "Window is empty!!!", Class, MB_ICONHAND | MB_OK);
		return 2;
	}

	ShowWindow(hwnd1, nShowcLassmd);
	UpdateWindow(hwnd1);


	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
