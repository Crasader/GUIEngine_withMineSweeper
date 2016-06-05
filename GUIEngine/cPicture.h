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
	cPicture(tagPOINT Pos,
		int width, int Height,
		ControlEventType eveType,int ControlID);



	~cPicture();
	//�[�����
	bool	PicLoadImage(LPTSTR lpszFilePath);
	HBITMAP	GethBitmap(){ return m_hBitmap; };
	//��o��Ϫ���
	unsigned GetBitmapWidth();
	unsigned GetBitmapHeight();
	bool ShowImage(HWND hWnd);

private:
	HBITMAP m_hBitmap;
};






//�غc�l
cPicture::cPicture(tagPOINT Pos,
	int width, int Height,ControlEventType eveType,int ControlID):ControlBasic(Pos,width,Height,eveType,ControlID)
	{

	};








//�Ѻc�l
cPicture::~cPicture()
{


};


//�[�����
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



//��o��ϼe��
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



//�����Ϫ���
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

