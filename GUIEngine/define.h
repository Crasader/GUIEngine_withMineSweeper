#pragma once
/**********************************************************************************/
//窗口參數定義
/**********************************************************************************/
	//窗口風格
#define GUIWINDOW_STYLE     WS_OVERLAPPED|WS_SYSMENU|WS_CAPTION|WS_MINIMIZEBOX
	//窗口名
#define	GUIWINDOW_TITLE		"GUIEngine"
	//窗口長度
#define GUIWINDOW_WIDTH		240
	//窗口高
#define GUIWINDOW_HEIGHT	380
	//窗口菜單ID
#define GUIWINDOW_MENU		IDC_MENU1



/**********************************************************************************/
//遊戲相關定義
/**********************************************************************************/
//地雷的長寬，正方形

#define GAMEWINDOW_CELLWIDTH_HEIGHT	16

//棋盤與窗口間格
//			間距一	
//			┌───┐
//	間距四	|	口	 |	間距二
//			└───┘
//			間距三

	//間距一
#define GAMEWINDOW_MARGIN_TOP 90
	//間距二
#define GAMEWINDOW_MARGIN_RIGHT 20
	//間距三
#define GAMEWINDOW_MARGIN_BUT 20
	//間距四
#define GAMEWINDOW_MARGIN_LEFT 20

	//臉的位置
#define GAMEFACE_MARGIN_TOP			30
#define GAMEFACE_MARGIN_LEFT 		100	


	//地雷個數
#define GAMEMINE_NUM	20




namespace GUITYPE{
	
	typedef void (*pfunc)();


	enum class ControlEventType
	{
		Button = 1,
		Image,
		Editor
	};

}


//錯誤定義
#define  ERRORDEF_GLOBAL_EXSISTED -1
