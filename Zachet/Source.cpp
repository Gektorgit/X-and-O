#include <Windows.h>
#include "Header.h"
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void Proverka (HWND hWnd, int * Chek);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

#pragma region 1. WindowClass
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WndProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra  = 0;
	wcl.hInstance = hInstance;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	
	wcl.hbrBackground = (HBRUSH)(16);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = L"X and 0";
	wcl.hIconSm = NULL;
	if (!RegisterClassEx(&wcl))	return 0;
#pragma endregion
#pragma region 2. Window
	HWND hWnd =		  CreateWindowEx(0, wcl.lpszClassName, L"                  X and 0", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, 0, WIDTH * 3.5, HEIGHT * 5, NULL, NULL, hInstance, NULL);
#pragma endregion

#pragma region Menu
	HMENU hMenuMain = CreateMenu();
	HMENU hMenuCorrection = CreatePopupMenu();
	//-----------------------------------------------------------------------------
	AppendMenu(hMenuMain, MF_STRING|MF_POPUP, (UINT)hMenuCorrection, L"&Menu");
	//----------------------------------------------------------------------------
	AppendMenu(hMenuCorrection, MF_STRING, ID_NEW, L"New Game");
	AppendMenu(hMenuCorrection, MF_STRING, ID_EXIT, L"Exit");

	//----------------------------------------------------------------------------	
	SetMenu(hWnd, hMenuMain);
#pragma endregion

#pragma region 3. Other Operations
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while(GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
#pragma endregion
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);
	static int * Check = new int [9];
	WCHAR *temp;
	HBITMAP hBitmapX = LoadBitmap (hInst, MAKEINTRESOURCE (IDB_BITMAP1));
	HBITMAP hBitmapO = LoadBitmap (hInst, MAKEINTRESOURCE (IDB_BITMAP2));
#pragma region Flag
	static int flag = 1;
	if (flag)
	{
		temp = L"X";
	}
	else
	{
		temp = L"0";
	}
#pragma endregion

	switch(message)
	{
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
				case ID_NEW:
				{
					for (int i = 0; i < 9; i++)
					{
						Check[i] = 2;
					}
					flag = 1;
					DestroyWindow (GetDlgItem (hWnd, ID_B1));
					DestroyWindow (GetDlgItem (hWnd, ID_B2));
					DestroyWindow (GetDlgItem (hWnd, ID_B3));
					DestroyWindow (GetDlgItem (hWnd, ID_B4));
					DestroyWindow (GetDlgItem (hWnd, ID_B5));
					DestroyWindow (GetDlgItem (hWnd, ID_B6));
					DestroyWindow (GetDlgItem (hWnd, ID_B7));
					DestroyWindow (GetDlgItem (hWnd, ID_B8));
					DestroyWindow (GetDlgItem (hWnd, ID_B9));
					CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"", WS_CHILD|WS_VISIBLE, 15,  15,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B1,	hInst, NULL);
					CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"", WS_CHILD|WS_VISIBLE, 120, 15,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B2,	hInst, NULL);
					CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"", WS_CHILD|WS_VISIBLE, 225, 15,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B3,	hInst, NULL);
					CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"", WS_CHILD|WS_VISIBLE, 15,  120, WIDTH, HEIGHT, hWnd, (HMENU)ID_B4,	hInst, NULL);
					CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"", WS_CHILD|WS_VISIBLE, 120, 120, WIDTH, HEIGHT, hWnd, (HMENU)ID_B5,	hInst, NULL);
					CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"", WS_CHILD|WS_VISIBLE, 225, 120, WIDTH, HEIGHT, hWnd, (HMENU)ID_B6,	hInst, NULL);
					CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"", WS_CHILD|WS_VISIBLE, 15,  225, WIDTH, HEIGHT, hWnd, (HMENU)ID_B7,	hInst, NULL);
					CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"", WS_CHILD|WS_VISIBLE, 120, 225, WIDTH, HEIGHT, hWnd, (HMENU)ID_B8,	hInst, NULL);
					CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"", WS_CHILD|WS_VISIBLE, 225, 225, WIDTH, HEIGHT, hWnd, (HMENU)ID_B9,	hInst, NULL);
					CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"", WS_CHILD|WS_VISIBLE|SS_CENTER|WS_EX_CLIENTEDGE, 15,  330,  WIDTH * 3 + 5, HEIGHT, hWnd, (HMENU)ID_STATIC,	hInst, NULL);
				}
				break;
				case ID_B1:
					{
						DestroyWindow (GetDlgItem (hWnd, ID_B1));
						CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"", WS_CHILD|WS_VISIBLE|SS_BITMAP, 15,  15,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B1,	hInst, NULL);
						if (temp == L"X")
							SendMessage (GetDlgItem (hWnd, ID_B1), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapX);
						else
							SendMessage (GetDlgItem (hWnd, ID_B1), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapO);
						Check [0] = flag;
						flag = !flag;
						Proverka (hWnd, Check);
					}
					break;
				case ID_B2:
					{
						DestroyWindow (GetDlgItem (hWnd, ID_B2));
						CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"", WS_CHILD|WS_VISIBLE|SS_BITMAP, 120,  15,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B2,	hInst, NULL);
						if (temp == L"X")
							SendMessage (GetDlgItem (hWnd, ID_B2), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapX);
						else
							SendMessage (GetDlgItem (hWnd, ID_B2), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapO);
						Check [1] = flag;
						flag = !flag;
						Proverka (hWnd, Check);
					}
					break;
				case ID_B3:
					{
						DestroyWindow (GetDlgItem (hWnd, ID_B3));
						CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"", WS_CHILD|WS_VISIBLE|SS_BITMAP, 225,  15,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B3,	hInst, NULL);
						if (temp == L"X")
							SendMessage (GetDlgItem (hWnd, ID_B3), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapX);
						else
							SendMessage (GetDlgItem (hWnd, ID_B3), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapO);
						Check [2] = flag;
						flag = !flag;
						Proverka (hWnd, Check);
					}
					break;
				case ID_B4:
					{
						DestroyWindow (GetDlgItem (hWnd, ID_B4));
						CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"", WS_CHILD|WS_VISIBLE|SS_BITMAP, 15,  120,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B4,	hInst, NULL);
						if (temp == L"X")
							SendMessage (GetDlgItem (hWnd, ID_B4), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapX);
						else
							SendMessage (GetDlgItem (hWnd, ID_B4), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapO);
						Check [3] = flag;
						flag = !flag;
						Proverka (hWnd, Check);
					}
					break;
				case ID_B5:
					{
						DestroyWindow (GetDlgItem (hWnd, ID_B5));
						CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"", WS_CHILD|WS_VISIBLE|SS_BITMAP, 120,  120,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B5,	hInst, NULL);
						if (temp == L"X")
							SendMessage (GetDlgItem (hWnd, ID_B5), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapX);
						else
							SendMessage (GetDlgItem (hWnd, ID_B5), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapO);
						Check [4] = flag;
						flag = !flag;
						Proverka (hWnd, Check);
					}
					break;
				case ID_B6:
					{
						DestroyWindow (GetDlgItem (hWnd, ID_B6));
						CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"", WS_CHILD|WS_VISIBLE|SS_BITMAP, 225,  120,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B6,	hInst, NULL);
						if (temp == L"X")
							SendMessage (GetDlgItem (hWnd, ID_B6), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapX);
						else
							SendMessage (GetDlgItem (hWnd, ID_B6), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapO);
						Check [5] = flag;
						flag = !flag;
						Proverka (hWnd, Check);
					}
					break;
				case ID_B7:
					{
						DestroyWindow (GetDlgItem (hWnd, ID_B7));
						CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"", WS_CHILD|WS_VISIBLE|SS_BITMAP, 15,  225,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B7,	hInst, NULL);
						if (temp == L"X")
							SendMessage (GetDlgItem (hWnd, ID_B7), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapX);
						else
							SendMessage (GetDlgItem (hWnd, ID_B7), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapO);
						Check [6] = flag;
						flag = !flag;
						Proverka (hWnd, Check);
					}
					break;
				case ID_B8:
					{
						DestroyWindow (GetDlgItem (hWnd, ID_B8));
						CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"", WS_CHILD|WS_VISIBLE|SS_BITMAP, 120,  225,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B8,	hInst, NULL);
						if (temp == L"X")
							SendMessage (GetDlgItem (hWnd, ID_B8), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapX);
						else
							SendMessage (GetDlgItem (hWnd, ID_B8), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapO);
						Check [7] = flag;
						flag = !flag;
						Proverka (hWnd, Check);
					}
					break;
				case ID_B9:
					{
						DestroyWindow (GetDlgItem (hWnd, ID_B9));
						CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"", WS_CHILD|WS_VISIBLE|SS_BITMAP, 225,  225,  WIDTH, HEIGHT, hWnd, (HMENU)ID_B9,	hInst, NULL);
						if (temp == L"X")
							SendMessage (GetDlgItem (hWnd, ID_B9), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapX);
						else
							SendMessage (GetDlgItem (hWnd, ID_B9), STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmapO);
						Check [8] = flag;
						flag = !flag;
						Proverka (hWnd, Check);
					}
					break;
			case ID_EXIT:
				{
					SendMessage(hWnd, WM_DESTROY, 0, 0);
				}
				break;
			}
		}
		break;
	case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

}
void Proverka (HWND hWnd, int * Chek)
{
	if (Chek[0]==Chek[1]&&Chek[1]==Chek[2]&&Chek[2]==1 || Chek[3]==Chek[4]&&Chek[4]==Chek[5]&&Chek[5]==1 || Chek[6]==Chek[7]&&Chek[7]==Chek[8]&&Chek[8]==1 ||
		Chek[0]==Chek[3]&&Chek[3]==Chek[6]&&Chek[6]==1 || Chek[1]==Chek[4]&&Chek[4]==Chek[7]&&Chek[7]==1 || Chek[2]==Chek[5]&&Chek[5]==Chek[8]&&Chek[8]==1 ||
		Chek[0]==Chek[4]&&Chek[4]==Chek[8]&&Chek[8]==1 || Chek[2]==Chek[4]&&Chek[4]==Chek[6]&&Chek[6]==1)
			{
				SetWindowText (GetDlgItem (hWnd,ID_STATIC), L"Выиграл Х");
			}
	else if (Chek[0]==Chek[1]&&Chek[1]==Chek[2]&&Chek[2]==0 || Chek[3]==Chek[4]&&Chek[4]==Chek[5]&&Chek[5]==0 || Chek[6]==Chek[7]&&Chek[7]==Chek[8]&&Chek[8]==0 ||
			 Chek[0]==Chek[3]&&Chek[3]==Chek[6]&&Chek[6]==0 || Chek[1]==Chek[4]&&Chek[4]==Chek[7]&&Chek[7]==0 || Chek[2]==Chek[5]&&Chek[5]==Chek[8]&&Chek[8]==0 ||
			 Chek[0]==Chek[4]&&Chek[4]==Chek[8]&&Chek[8]==0 || Chek[2]==Chek[4]&&Chek[4]==Chek[6]&&Chek[6]==0)
			{
				SetWindowText (GetDlgItem (hWnd,ID_STATIC), L"Выиграл O");
			}
}