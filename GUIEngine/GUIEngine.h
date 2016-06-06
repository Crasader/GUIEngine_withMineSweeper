#pragma once

/********************************************************************************************/
//文件說明
/********************************************************************************************/
//本頭文件中宣告了許多類別，並不是有GUIEngine這樣的類別

/********************************************************************************************/
//頭文件引用
/********************************************************************************************/
#include "StdInclude.h"
#include "define.h"
#include "cCallbackFunctor.h"
#include "resource.h"
#include "cButton.h"
#include "cPicture.h"

using namespace  GUITYPE;


/********************************************************************************************/
//全域函式宣告
/********************************************************************************************/
void Paint();

/********************************************************************************************/
/*全局變量*/
/********************************************************************************************/

//控件列表
//extern std::list<void *>g_AllControlList;
//extern	std::list<cPicture*> g_ImageList;
//extern	std::list<cButton*>g_ButtonList;
//extern	cPicture* g_ImageBackGround;

/*******************************************************************************************/
//類別:
//GUI管理器
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
	//創造圖片
	BOOL GUICreatePicture(tagPOINT Pos,
		int width, int Height,  int ControlID, LPTSTR filePath);
	//創建背景
	BOOL GUICreateBKPicture(tagPOINT Pos,
		int width, int Height,  int ControlID, LPTSTR filePath, bool IsBackGround);
	//GUI繪圖
	void Draw();
	//創建按鈕
	BOOL GUICreateButton(
		tagPOINT Pos,
		int width, int Height, int ControlID, LPTSTR filePath, cCallBackFunctorBasic*);
	//獲得客戶區大小
	tagPOINT GUIGetClientSize(){ return m_ClientSize; };
	//註冊事件
	bool RegistEvent(int ControlID, ControlEventType EventType);
	
private:
	HINSTANCE			m_hInstance;
	HWND				m_hWnd;
	HBITMAP				m_hbmpBackground;
	tagPOINT			m_ClientSize;
	int					m_nWindowWidth;
	int					m_nWindowHeight;
	
};



