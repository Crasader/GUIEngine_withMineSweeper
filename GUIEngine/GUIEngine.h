#pragma once

/********************************************************************************************/
//��󻡩�
/********************************************************************************************/
//���Y��󤤫ŧi�F�\�h���O�A�ä��O��GUIEngine�o�˪����O

/********************************************************************************************/
//�Y���ޥ�
/********************************************************************************************/
#include "StdInclude.h"
#include "define.h"
#include "cCallbackFunctor.h"
#include "resource.h"
#include "cButton.h"
#include "cPicture.h"

using namespace  GUITYPE;


/********************************************************************************************/
//����禡�ŧi
/********************************************************************************************/
void Paint();

/********************************************************************************************/
/*�����ܶq*/
/********************************************************************************************/

//����C��
//extern std::list<void *>g_AllControlList;
//extern	std::list<cPicture*> g_ImageList;
//extern	std::list<cButton*>g_ButtonList;
//extern	cPicture* g_ImageBackGround;

/*******************************************************************************************/
//���O:
//GUI�޲z��
/*******************************************************************************************/
class GUIManager
{
public:


public:
	GUIManager(HINSTANCE hInst)
	{
		this->m_hInstance = hInst;
	};
	~GUIManager(){};
	BOOL GUICreateWindow(LPTSTR lpszWinTitle, LPTSTR lpszMenu, int nWidth, int nHeight);
	void GUIRunWindow();
	HWND GUIGetMainWindow(){ return m_hWnd; };
	//�гy�Ϥ�
	BOOL GUICreatePicture(tagPOINT Pos,
		int width, int Height,  int ControlID, LPTSTR filePath);
	//�ЫحI��
	BOOL GUICreateBKPicture(tagPOINT Pos,
		int width, int Height,  int ControlID, LPTSTR filePath, bool IsBackGround);
	//GUIø��
	void Draw();
	//�Ыث��s
	BOOL GUICreateButton(
		tagPOINT Pos,
		int width, int Height, int ControlID, LPTSTR filePath, cCallBackFunctorBasic*);
	//��o�Ȥ�Ϥj�p
	tagPOINT GUIGetClientSize(){ return m_ClientSize; };
	//���U�ƥ�
	bool RegistEvent(int ControlID, ControlEventType EventType);
	
private:
	HINSTANCE			m_hInstance;
	HWND				m_hWnd;
	HBITMAP				m_hbmpBackground;
	tagPOINT			m_ClientSize;
	int					m_nWindowWidth;
	int					m_nWindowHeight;
	
};



