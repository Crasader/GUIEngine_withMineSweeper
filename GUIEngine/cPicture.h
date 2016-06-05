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
	cPicture(tagPOINT Pos,
		int width, int Height,
		ControlEventType eveType,int ControlID);



	~cPicture();
	//加載位圖
	bool	PicLoadImage(LPTSTR lpszFilePath);
	HBITMAP	GethBitmap(){ return m_hBitmap; };
	//獲得位圖長度
	unsigned GetBitmapWidth();
	unsigned GetBitmapHeight();
	bool ShowImage(HWND hWnd);

private:
	HBITMAP m_hBitmap;
};






//建構子
cPicture::cPicture(tagPOINT Pos,
	int width, int Height,ControlEventType eveType,int ControlID):ControlBasic(Pos,width,Height,eveType,ControlID)
	{

	};








//解構子
cPicture::~cPicture()
{


};


//加載位圖
bool cPicture::PicLoadImage(LPTSTR lpszFilePath)
{
	
	HBITMAP tempHbmp=(HBITMAP)LoadImage(NULL,lpszFilePath,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	if (!tempHbmp)
		{
			return false;
	}
	m_hBitmap = tempHbmp;
	return true;
};



//獲得位圖寬度
unsigned cPicture::GetBitmapWidth()
{
	BITMAP bitInfo;
	if (!m_hBitmap)
	{
		return 0;
	}
	GetObject(m_hBitmap, sizeof(bitInfo),&bitInfo);
	return bitInfo.bmWidth;
	
};



//獲取位圖長度
unsigned cPicture::GetBitmapHeight()
{
	BITMAP bitInfo;
	if (!m_hBitmap)
	{
		return 0;
	}
	GetObject(m_hBitmap, sizeof(bitInfo), &bitInfo);
	return bitInfo.bmHeight;
};




bool cPicture::ShowImage(HWND hWnd)
{
	if (hWnd == INVALID_HANDLE_VALUE)
	{
		return false;
	}
	HDC hDC;
	HDC hMemDC;
	HBITMAP hBmp;
	hDC=GetWindowDC(hWnd);
	hBmp = CreateCompatibleBitmap(hDC, GUIWINDOW_WIDTH, GUIWINDOW_HEIGHT);
	hMemDC = CreateCompatibleDC(hDC);
	SelectObject(hMemDC, hBmp);
	DeleteObject(hBmp);
	SelectObject(hMemDC, m_hBitmap);
	BitBlt(hDC, this->GetPosition().x, this->GetPosition().y, GUIWINDOW_WIDTH, GUIWINDOW_HEIGHT,hMemDC, 0, 0, SRCCOPY);



	
	return true;




}

