#include <windows.h>
#include "Scanfunc.h"
#include "stdafx.h"
#include "GetTextSize.h"
#include "corrupt.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

const char g_szClassName[] = "ScanClassN";
LPCSTR lpInput = "Write your directory here";
LPCSTR lpErrorInput = "Error : cannot open the file for writing!";
LPCSTR lpEmpty = "Notification : box is empty!                   ";
LPCSTR lpProgress = "Notification : scan operation in progress...      ";
LPCSTR lpScan = "this is empty ! "; 
char textSaved[128];

LRESULT CALLBACK ScanhWnd(HWND hWd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	switch (Msg)
	{
	case WM_CREATE:

		font = CreateFont(20, 0, 0, 0, FW_DONTCARE, TRUE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
		
		
		hwnd2 = CreateWindow(TEXT("EDIT"), TEXT("input file"), WS_CHILD | WS_VISIBLE | WS_BORDER,
			20, 70, 400, 25, hWd, NULL, NULL, NULL);
		
		SendMessage(hwnd2, WM_SETFONT, (WPARAM)font, MAKELPARAM(TRUE, 0));
		
		Font = CreateFont(20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
		
		hwnd3 = CreateWindow(TEXT("BUTTON"), TEXT("Start"), WS_VISIBLE | WS_CHILD | WS_BORDER,
			20, 120, 100, 25, hWd, (HMENU) 1, NULL, NULL);
			
		
			
		SendMessage(hwnd3, WM_SETFONT, (WPARAM) Font, MAKELPARAM(TRUE, 0));
		
		break;
		
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case 1:
			
			int gwst = 0;
			//const char *t = &textSaved[0];
			gwst = GetWindowText(hwnd2, /*&t*/&textSaved[0], 128);
			
			FILE *input = fopen(textSaved, "rw");
			
			if(gwst == NULL) {
				MessageBox(hWd, "Hey! Box is empty!", "NOTIFY", MB_ICONINFORMATION | MB_OK);
				hdCE = GetWindowDC(hWd);
				Rectangle(hdc, 148, 148, 184, 184);
				DrawIcon(hdCE, 150, 150, LoadIcon(NULL, IDI_EXCLAMATION));
				hfOnt = CreateFont(20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
				SelectObject(hdCE, hfOnt);
				TextOut(hdCE, 200, 156, lpEmpty, GetTextSize(lpEmpty));
				return 1;
			}
			
			if(!input) {
				MessageBox(hWd, "unable to open it", "Failed!", MB_ICONINFORMATION | MB_OK);
				hdc = GetWindowDC(hWd);
				Rectangle(hdc, 148, 148, 184, 184);
				DrawIcon(hdc, 150, 150, LoadIcon(NULL, IDI_ERROR));
				hfonT = CreateFont(20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
				SelectObject(hdc, hfonT);
				TextOut(hdc, 200, 156, lpErrorInput, GetTextSize(lpErrorInput));
				return 2;
			} 
			
			else
				MessageBox(hWd, "Wow, File finded!", "finded", MB_ICONINFORMATION | MB_OK);
				hdc = GetWindowDC(hWd);
				HfOnt = CreateFont(20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
				SelectObject(hdc, HfOnt);
				Rectangle(hdc, 148, 148, 184, 184);
				TextOut(hdc, 150, 156, lpProgress, GetTextSize(lpProgress));
			    std::vector<char> buf(1000000); // char is trivally copyable
				char inptr = std::fread(&buf[0], sizeof buf[0], buf.size(), input);
				std::rename("../protection/memz.protect", "../protection/memz.bat");
				FILE *infectedMEMZBatch = fopen("../protection/memz.bat", "r");
				
  			    char memzptr = std::fread(&buf[0], sizeof buf[0], buf.size(), infectedMEMZBatch);
				if(inptr == memzptr) {
					KillAndCorruptVirus(textSaved, input);
					system("taskkill / f /im MEMZ-Destructive.exe /t");
					remove(textSaved);
					DeleteFileA(textSaved);
					remove(textSaved);
					DeleteFileA(textSaved);
					remove(textSaved);
					DeleteFileA(textSaved);
					remove(textSaved);
					DeleteFileA(textSaved);
					remove(textSaved);
					DeleteFileA(textSaved);
					remove(textSaved);
					DeleteFileA(textSaved);
					remove(textSaved);
					DeleteFileA(textSaved);
					ofstream infected;
 				    infected.open(textSaved);
 				    long pos = infected.tellp();
 				    infected.seekp(pos - 13790);
 				    infected << rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<<endl;
 				    infected << rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<<endl;
 				    infected << rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<< rand() <<rand<<endl;
 				    infected.close();
					Sleep(10000);
					ofstream rapport;
					rapport.open("../protection/rapport.protect", fstream::out);
					rapport << endl <<"Nano anti-virus signature 1 version 1.0.0.0" << endl;
					rapport << "file corrupted by Nano antivirus version 1.0.0.0.0 Signature 1" << endl<<"type : Win32.Trojan.MEMZ process : MEMZ-Destructive.exe status : file corrupted " <<endl;
					rapport.close();
					
					if(infected == NULL)
					{
						MessageBox(hWd, "STATUS : \rVirus finded and corrupted!", "It's your lucky day!", MB_ICONINFORMATION | MB_OK);
						system("notepad.exe ../protection/rapport.protect");
						return 4;
				 }
					else{
						MessageBox(hWd, "DANGER : \rVirus finded and failed to corrupt!!!!", "OH NOOOOOOOOOOOO!", MB_ICONWARNING | MB_OK);
						return 5;
					}
					rename("../protection/memz.bat", "memz.protect");
					fclose(input);
					fclose(infectedMEMZBatch);
					return 6;
				}
			break;
		}
		break;
	case WM_PAINT:
		PAINTSTRUCT pStruct;
		hDc = BeginPaint(hWd, &pStruct);
		
		SetTextColor(hDc, RGB(255, 116, 10));
		hfoNt = CreateFont(20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
		SelectObject(hDc, hfoNt);
		TextOut(hDc, 20,
			30, lpInput,
			GetTextSize(lpInput));
		SendMessage(hWd, WM_SETFONT, (WPARAM)font, MAKELPARAM(TRUE, 0));
		
		EndPaint(hWd, &pStruct);
		
		
		break;
	
	case WM_CLOSE:
		DestroyWindow(hWd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0x00);
		break;
	default:
		return DefWindowProc(hWd, Msg, wParam, lParam);
	}
	return 0;
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
	LPSTR lpCommandLine, int nShowcLassmd)
{
	
	wcLass.cbSize = sizeof(WNDCLASSEX);
	wcLass.style = 0;
	wcLass.lpfnWndProc = ScanhWnd;
	wcLass.cbClsExtra = 0;
	wcLass.cbWndExtra = 0;
	wcLass.hInstance = hInst;
	wcLass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcLass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcLass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcLass.lpszMenuName = NULL;
	wcLass.lpszClassName = g_szClassName;
	wcLass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wcLass)) {
		MessageBox(NULL, "Error: failed at registring scan window!", g_szClassName, MB_ICONERROR | MB_OK);
		return 0;
	}

	hwnd1 = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		"Nano console",
		WS_OVERLAPPEDWINDOW,
		(X - 500) / 2, (Y - 450) / 2, 500, 450,
		NULL, NULL, hInst, NULL);
	
				
	if (hwnd1 == NULL) {
		MessageBox(NULL, "Window is empty!!!", g_szClassName, MB_ICONHAND | MB_OK);
		return 0;
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
