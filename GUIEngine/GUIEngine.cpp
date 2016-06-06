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
//������(�ȨѦ^�ը�ƽե�)
/***************************************************************************************/
//�ե�GUI�����̪�����i��ø��
void Paint()
{
	extern GUIManager* g_GUIMgptr;
	g_GUIMgptr->Draw();
}

//���I���ƥ�o�ͮɡA�T�w�����X�ӱ���n�T���ƥ�Ĳ�o
void CheckClickOnbutton(int x, int y)
{
	for (auto& i : g_ButtonList)
	{
		//���s���W���y��TOP LEFT
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
			if (i->GetIsEnable())//���p���s���\�QĲ�o
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

//�^�ը�ƫŧi
/***************************************************************************************/
LRESULT CALLBACK CallWinProc(
	HWND		hWnd,
	UINT		message,
	WPARAM		wParam,
	LPARAM		lParam
	);



//�Ыص���
/***************************************************************************************/
BOOL GUIManager::GUICreateWindow(LPTSTR lpszWinTitle, LPTSTR lpszMenu, int nWidth, int nHeight)
{
	//��l��
	this->m_nWindowWidth = nWidth;
	this->m_nWindowHeight = nHeight;


	//���U
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
		MessageBox(NULL, _T("���~����"), _T("�Ыص��f����"), MB_OK);
		return false;
	}

	RECT WindowRect = { 0, 0, m_nWindowWidth, m_nWindowHeight };
	::AdjustWindowRect(&WindowRect, GUIWINDOW_STYLE, TRUE);

	//�p����ܾ�����
	int SCRTotalWidth = GetSystemMetrics(SM_CXSCREEN);
	int SCRTotalHeight = GetSystemMetrics(SM_CYSCREEN);

	//�p��ϵ����b�������y��
	int x = ((SCRTotalWidth - m_nWindowWidth) / 2);
	int y = ((SCRTotalHeight - m_nWindowHeight) / 2);
	//�Ыص���
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
		MessageBox(NULL, _T("���~����"), _T("�Ыص��f����"), MB_OK);
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


//�����^�վ����{
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


//�����`��
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
//�ЫعϤ�
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

//�ЫحI���A�p�G�̫�@�ӰѼƬ�FALSE�����^�ǿ��~

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






//�Ыث��s
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

//ø�Ϩ��
void GUIManager::Draw()
{
	HDC	hDc = GetDC(m_hWnd);
	HDC hMemDC = CreateCompatibleDC(hDc);
	if (m_hWnd == nullptr)
	{
		return;
	}
	//����I���i��ø��
	if (g_ImageBackGround != nullptr)
	{
		SelectObject(hMemDC, g_ImageBackGround->GethBitmap());

	}


	//��C�Ӧb�Ϥ������C�̪��ť�i��ø��
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
//�����ܼ�
/***************************************************************************************/
GUIManager* g_GUIMgptr;


