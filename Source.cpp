#include <Windows.h>
#include "GetTextSize.h"
#include "functions.h"
#include "stdafx.h"
#include "resource.h"


const char szClassName[] = "NanoShield";
int X, Y;
LPCSTR LPchar = "Select SCAN NOW to begin";
LPCSTR lpUserName = "Notify : Click change username for changing the username";
LPCSTR lpRec = "this is recommended (restart required)";
char TextSaved[20];


LRESULT CALLBACK Window(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;

	switch (Msg) {
	case WM_CREATE:
		
		hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	
		HWnd = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("BUTTON"), TEXT("SCAN NOW!!!"), WS_CHILD | WS_VISIBLE, 400 - (200 + 50), 230, 100, 25, hWnd, HMENU(ID_SCANBUT), GetModuleHandle(NULL), NULL);

		SendMessage(HWnd, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE, 0));

		font = (HFONT)GetStockObject(DEFAULT_GUI_FONT);

		HwnD = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("BUTTON"), TEXT("QUIT"), WS_CHILD | WS_VISIBLE, 50, 230, 100, 25, hWnd, HMENU(ID_QUITBUT), GetModuleHandle(NULL), NULL);

		SendMessage(HwnD, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE, 0));

		HFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	
		hWNd = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("BUTTON"), TEXT("CHANGE"), WS_CHILD | WS_VISIBLE | WS_BORDER, 250, 230, 100, 25, hWnd, HMENU(ID_ABOUTBUT), GetModuleHandle(NULL), NULL);

		SendMessage(hWNd, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE, 0));
		
		hfoNt = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
		
		Change = CreateWindow(TEXT("EDIT"), TEXT("Change"), WS_CHILD | WS_VISIBLE | WS_BORDER, 340, 10,
			280, 50, 
			hWnd, NULL, NULL, NULL);
			
		SendMessage(Change, WM_SETFONT, (WPARAM)hfoNt, MAKELPARAM(TRUE, 0));
		
	
		break;
		
	case WM_COMMAND:
		
		if(LOWORD(wParam) == ID_QUITBUT) {
			DestroyWindow(hWnd);
			ExitProcess(NULL);
			return 1;
		}
		
		if(LOWORD(wParam) == ID_SCANBUT) {
			FreeConsole();
			system("explorer scan");
			system("exit");
			Sleep(3000);
			DestroyWindow(hWnd);
			ExitProcess(NULL);
			return 10;
		}
		
		switch(LOWORD(wParam))
		{
			case ID_ABOUTBUT:
				
				int gwstat = 0;
				gwstat = GetWindowText(Change, &TextSaved[0], 20);
				::SetComputerName(TextSaved);
				DWORD dw = MessageBox(hWnd, "restart now?", "Confirm", MB_ICONQUESTION | MB_YESNO);
				if(dw == IDNO)
				{
					return 9;
				}
				if(dw == IDYES)
				{
					HANDLE token;
					TOKEN_PRIVILEGES privileges;

					OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token);

					LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &privileges.Privileges[0].Luid);
					privileges.PrivilegeCount = 1;
					privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

					AdjustTokenPrivileges(token, FALSE, &privileges, 0, (PTOKEN_PRIVILEGES)NULL, 0);

					//restart
					ExitWindowsEx(EWX_REBOOT | EWX_FORCE, SHTDN_REASON_MAJOR_HARDWARE | SHTDN_REASON_MINOR_DISK);
					return EXIT_SUCCESS;
				}
				break;
		}
		
		hfOnt = CreateFont(14, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
		hdC = GetWindowDC(hWnd);
		SelectObject(hdC, hfOnt);
		TextOut(hdC, 60, 40, lpUserName, GetTextSize(lpUserName));
		TextOut(hdC, 60, 70, lpRec, GetTextSize(lpRec));
		
		break;
		
	case WM_CLOSE:
		
		DestroyWindow(hWnd);
		break;
		
	case WM_DESTROY:
		
		PostQuitMessage(0x00);
		break;
		
	case WM_PAINT:
		
		PAINTSTRUCT ps;
		hdc = BeginPaint(hWnd, &ps);
	    HFONt = CreateFont(24, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
		SelectObject(hdc, HFONt);
		TextOut(hdc,
			60, 100,
			LPchar,
			GetTextSize(LPchar));
		EndPaint(hWnd, &ps);
		
		break;
		
	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	return 0;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
	LPSTR lpCommandLine, int showCmd)
{
	X = GetSystemMetrics(SM_CXSCREEN) / 2;
	Y = GetSystemMetrics(SM_CYSCREEN) / 2;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = Window;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = (HICON) LoadImage( // returns a HANDLE so we have to cast to HICON
    NULL,             // hInstance must be NULL when loading from a file
    "icon.ico",   // the icon file name
    IMAGE_ICON,       // specifies that the file is an icon
    0,                // width of the image (we'll specify default later on)
    0,                // height of the image
    LR_LOADFROMFILE|  // we want to load a file (as opposed to a resource)
    LR_DEFAULTSIZE|   // default metrics based on the type (IMAGE_ICON, 32x32)
    LR_SHARED         // let the system release the handle when it's no longer used
);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	wc.hIconSm = LoadIcon(hInstance, IDI_ICON);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}


	// Step 2: Creating the Window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		szClassName,
		"Nano console",
		WS_OVERLAPPEDWINDOW,
		X - (400 / 2), Y - (350 / 2), 400, 350,
		NULL, NULL, hInstance, NULL);


	HDC hDC = GetDC(hwnd);
	

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	
	


	ShowWindow(hwnd, showCmd);
	UpdateWindow(hwnd);

	// Step 3: The Message Loop
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return Msg.wParam;
	
	
}
