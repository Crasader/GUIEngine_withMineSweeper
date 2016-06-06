#include "cPicture.h"
#include "StdInclude.h"
#include "define.h"



cPicture::cPicture(tagPOINT Pos,
	int width, int Height,
	int ControlID):ControlBasic(Pos,width,Height,ControlID){};




//�[�����
bool cPicture::PicLoadImage(LPTSTR lpszFilePath)
{

	HBITMAP tempHbmp = (HBITMAP)LoadImage(NULL, lpszFilePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
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
	GetObject(m_hBitmap, sizeof(bitInfo), &bitInfo);
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

HBITMAP	cPicture::GethBitmap(){ return m_hBitmap; };