#include "StdInclude.h"
#include "GUIEngine.h"
#include "define.h"
#include "cPicture.h"
#include "cButton.h"



	 std::list<void *>g_AllControlList;
	std::list<cPicture*> g_ImageList;
	std::list<cButton*>g_ButtonList;
	cPicture* g_ImageBackGround;


/***************************************************************************************/
//全域函數(僅供回調函數調用)
/***************************************************************************************/
//調用GUI引擎裡的控件進行繪圖
void Paint()
{
	extern GUIManager* g_GUIMgptr;
	g_GUIMgptr->Draw();
}

//當點擊事件發生時，確定有哪幾個控件要響應事件觸發
void CheckClickOnbutton(int x, int y)
{
	for (auto& i : g_ButtonList)
	{
		//按鈕左上角座標TOP LEFT
		int nButtonTLx = i->GetPosition().x;
		int nButtonTLy = i->GetPosition().y;
		int width = i->GetWidth();
		int height = i->GetHeight();
		if (x < nButtonTLx || y < nButtonTLy)
		{
			continue;
		}

		if (x>nButtonTLx&&x<(nButtonTLx + width) && y>nButtonTLy&&y<(nButtonTLy + height))
		{
			if (i->GetIsEnable())//假如按鈕允許被觸發
			{
				cCallBackFunctorBasic* pf = i->m_CallbackFunctor;
				(*pf)();
				continue;
			}
		}
	}
}






/***************************************************************************************/
//GUIManager
/***************************************************************************************/

//回調函數宣告
/***************************************************************************************/
LRESULT CALLBACK CallWinProc(
	HWND		hWnd,
	UINT		message,
	WPARAM		wParam,
	LPARAM		lParam
	);



//創建視窗
/***************************************************************************************/
BOOL GUIManager::GUICreateWindow(LPTSTR lpszWinTitle, LPTSTR lpszMenu, int nWidth, int nHeight)
{
	//初始化
	this->m_nWindowWidth = nWidth;
	this->m_nWindowHeight = nHeight;


	//註冊
	WNDCLASSEX wndclass = { 0 };
	wndclass.cbSize = sizeof(wndclass);
	wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wndclass.lpszMenuName = lpszMenu;
	wndclass.lpszClassName = _T("GUIEngineClass");
	wndclass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wndclass.hInstance = m_hInstance;
	wndclass.lpfnWndProc = CallWinProc;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	int a = ::RegisterClassEx(&wndclass);
	if (a == 0)
	{
		MessageBox(NULL, _T("錯誤提示"), _T("創建窗口失敗"), MB_OK);
		return false;
	}

	RECT WindowRect = { 0, 0, m_nWindowWidth, m_nWindowHeight };
	::AdjustWindowRect(&WindowRect, GUIWINDOW_STYLE, TRUE);

	//計算顯示器中心
	int SCRTotalWidth = GetSystemMetrics(SM_CXSCREEN);
	int SCRTotalHeight = GetSystemMetrics(SM_CYSCREEN);

	//計算使視窗在中央的座標
	int x = ((SCRTotalWidth - m_nWindowWidth) / 2);
	int y = ((SCRTotalHeight - m_nWindowHeight) / 2);
	//創建視窗
	this->m_hWnd = ::CreateWindowEx(
		NULL,
		_T("GUIEngineClass"),
		lpszWinTitle,
		GUIWINDOW_STYLE,
		x,
		y,
		m_nWindowWidth,
		m_nWindowHeight,
		nullptr,
		nullptr,
		m_hInstance,
		nullptr
		);


	if (m_hWnd == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, _T("錯誤提示"), _T("創建窗口失敗"), MB_OK);
		return false;
	}
	else
	{
		RECT rect;
		GetClientRect(m_hWnd, &rect);
		m_ClientSize.x = rect.right - rect.left;
		m_ClientSize.y = rect.bottom - rect.top;

		ShowWindow(m_hWnd, SW_SHOW);
		UpdateWindow(m_hWnd);
		return true;
	}
}


//消息回調機制的實現
/***************************************************************************************/
LRESULT CALLBACK CallWinProc(
	HWND		hWnd,
	UINT		message,
	WPARAM		wParam,
	LPARAM		lParam
	)
{
	PAINTSTRUCT ps;
	switch (message)
	{
	case WM_PAINT:
	{
		BeginPaint(hWnd, &ps);
		Paint();
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		int x = (LOWORD(lParam));
		int y = (HIWORD(lParam));
		CheckClickOnbutton(x, y);
		Paint();
		break;
	}
	default:
		return ::DefWindowProc(hWnd, message, wParam, lParam);
	}
	return ::DefWindowProc(hWnd, message, wParam, lParam);
}


//消息循環
void GUIManager::GUIRunWindow()
{
	this->Draw();
	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
	return;
}
//創建圖片
BOOL GUIManager::GUICreatePicture(tagPOINT Pos,
	int width, int Height,int ControlID, LPTSTR filePath)
{
	cPicture* pic = new cPicture(Pos, width, Height, ControlID);
	if (pic == nullptr)
	{
		return false;
	}
	if (!pic->PicLoadImage(filePath))
	{
		return false;
	}
	g_ImageList.push_back(pic);
	g_AllControlList.push_back(pic);
	return true;
}

//創建背景，如果最後一個參數為FALSE直接回傳錯誤

BOOL GUICreateBKPicture(tagPOINT Pos,
	int width, int Height, ControlEventType eveType, int ControlID, LPTSTR filePath, bool IsBackGround)
{
	if (!IsBackGround)
	{
		return false;
	}

	cPicture* pic = new cPicture(Pos, width, Height, ControlID);
	if (pic == nullptr)
	{
		return false;
	}
	if (!pic->PicLoadImage(filePath))
	{
		return false;
	}
	g_ImageBackGround = pic;
	g_AllControlList.push_back(pic);
	return true;

}






//創建按鈕
BOOL GUIManager::GUICreateButton(
	tagPOINT Pos,
	int width, int Height, int ControlID, LPTSTR filePath, cCallBackFunctorBasic* pFunctor)
{
	cButton* button = new cButton(Pos, width, Height, ControlID, filePath, pFunctor);

	if (button == nullptr)
	{
		return false;
	}
	if (!button->PicLoadImage(filePath))
	{
		return false;
	}

	g_AllControlList.push_back(button);
	g_ButtonList.push_back(button);

	return true;
}

//繪圖函數
void GUIManager::Draw()
{
	HDC	hDc = GetDC(m_hWnd);
	HDC hMemDC = CreateCompatibleDC(hDc);
	if (m_hWnd == nullptr)
	{
		return;
	}
	//先對背景進行繪圖
	if (g_ImageBackGround != nullptr)
	{
		SelectObject(hMemDC, g_ImageBackGround->GethBitmap());

	}


	//對每個在圖片控件對列裡的空件進行繪圖
	for (auto& i : g_ImageList)
	{

		SelectObject(hMemDC, i->GethBitmap());
		BitBlt(hDc, i->GetPosition().x, i->GetPosition().y,
			i->GetWidth(), i->GetHeight(), hMemDC,
			0, 0, SRCCOPY);
	}
	for (auto& i : g_ButtonList)
	{
		SelectObject(hMemDC, i->GethBitmap());
		BitBlt(hDc, i->GetPosition().x, i->GetPosition().y,
			i->GetWidth(), i->GetHeight(), hMemDC,
			0, 0, SRCCOPY);
	}
	::DeleteObject(hMemDC);
}








/***************************************************************************************/
//全域變數
/***************************************************************************************/
GUIManager* g_GUIMgptr;


