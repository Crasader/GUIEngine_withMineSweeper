#pragma once
#include"StdInclude.h"
#include "ControlBasic.h"


/*******************************************************************************************/
//���O:
//�Ϥ��[����
/*******************************************************************************************/
class cPicture :public ControlBasic
{
public:


	//�Ыش��q���
	//�غc�l
	cPicture(tagPOINT Pos,
		int width, int Height,
	int ControlID);


	//�Ѻc�l
	~cPicture();
	//�[�����
	bool	PicLoadImage(LPTSTR lpszFilePath);
	HBITMAP	GethBitmap();
	//��o��Ϫ���
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

