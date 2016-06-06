#pragma once
#include"StdInclude.h"
#include "ControlBasic.h"


/*******************************************************************************************/
//類別:
//圖片加載類
/*******************************************************************************************/
class cPicture :public ControlBasic
{
public:


	//創建普通位圖
	//建構子
	cPicture(tagPOINT Pos,
		int width, int Height,
	int ControlID);


	//解構子
	~cPicture();
	//加載位圖
	bool	PicLoadImage(LPTSTR lpszFilePath);
	HBITMAP	GethBitmap();
	//獲得位圖長度
	unsigned GetBitmapWidth();
	unsigned GetBitmapHeight();


private:
	HBITMAP m_hBitmap;
};




















//
//bool cPicture::ShowImage(HWND hWnd)
//{
//	if (hWnd == INVALID_HANDLE_VALUE)
//	{
//		return false;
//	}
//	HDC hDC;
//	HDC hMemDC;
//	HBITMAP hBmp;
//	hDC=GetWindowDC(hWnd);
//	hBmp = CreateCompatibleBitmap(hDC, GUIWINDOW_WIDTH, GUIWINDOW_HEIGHT);
//	hMemDC = CreateCompatibleDC(hDC);
//	SelectObject(hMemDC, hBmp);
//	DeleteObject(hBmp);
//	SelectObject(hMemDC, m_hBitmap);
//	BitBlt(hDC, this->GetPosition().x, this->GetPosition().y, GUIWINDOW_WIDTH, GUIWINDOW_HEIGHT,hMemDC, 0, 0, SRCCOPY);
//
//
//
//	
//	return true;
//
//
//
//
//}

