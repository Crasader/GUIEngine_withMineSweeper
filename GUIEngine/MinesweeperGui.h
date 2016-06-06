#pragma once
#include "stdinclude.h"
#include "MineSweeperLogic.h"
#include "cCallbackFunctor.h"
#include "resource.h"
#include "ControlDefine.h"
#include "GUIEngine.h"

/************************************************************************************************/
//�~���ŧi�����ܼ�
/***********************************************************************************************/
extern  GUIManager*  g_GUIMgptr;
extern	std::list<cButton*>g_ButtonList;
cMineSweeperLogic*	g_MineSweeperGameLogic;


/**********************************************************************************************/
//�����ƫŧi
/**********************************************************************************************/
void	ShowAllMine();
void   ReDrawStatus();


/**********************************************************************************************/
//����^�ը�ƫŧi
/*********************************************************************************************/
//�ϥΪ̫��U�ѽL���s���^�ը��
class HideMine :public cCallBackFunctorBasic
{
public:
	HideMine(int n){ this->m_ControlID = n; };
	~HideMine(){};
	void	operator()()
	{
		//std::wstring strint = std::to_wstring(m_ControlID);
		//std::wstring total = L"BUMP!!" + strint;
		//MessageBox(NULL, total.c_str(), _T("WTF AMAZING"), MB_OK);
		for (auto&i : g_ButtonList)
		{
			if (i->GetControlID() == m_ControlID)
			{
				if ((g_MineSweeperGameLogic->m_sh_pGameStatus)->at(m_ControlID - 1) == gameStatus::mine)
				{
					ShowAllMine();
					for (auto&j : g_ButtonList)
					{
						if (j->GetControlID() == GAMEFACE_BUT_CONTROLID)
						{
							DeleteObject(j->GethBitmap());
							j->PicLoadImage(_T("deadface.bmp"));
						}
					}
				}
				else
				{
					DeleteObject(i->GethBitmap());
					(g_MineSweeperGameLogic->m_sh_pGameStatus)->at(m_ControlID - 1) = gameStatus::Checked;
					//��o�w�����|
			//		g_MineSweeperGameLogic->GetSafePath(m_ControlID - 1);
				//	ReDrawStatus();
					i->PicLoadImage(_T("beenclick.bmp"));
				}
			}
	
		}

	};
private:
	int m_ControlID;
};




//
////�ѽL�W�����s�~�Ӧ�GUI������BUTTON�A�h�X���A�ݩʡA�H�Φۤv��ID
//class Cell:public cButton
//{
//public:
//	Cell(tagPOINT Pos,
//		int width, int Height, ControlEventType eveType, int ControlID, LPTSTR filepath, cCallBackFunctorBasic* pfun, gameStatus gs)
//		:cButton(Pos, width, Height, eveType, ControlID, filepath, pfun)
//	{
//		this->m_CellStatus = gs;
//		m_CellID++;
//	};
//private:
//	gameStatus		m_CellStatus;
//	int		m_CellID;
//};
//
////�N�B�~�ݮi������A�[�JGUI�����޲z�C��
//



//�H�y����^�ը��
class GameFace :public cCallBackFunctorBasic
{
public:
	GameFace(){};
	~GameFace(){};

	void	operator()()
	{
		for (auto&i : g_ButtonList)
		{
			if (i->GetControlID() == GAMEFACE_BUT_CONTROLID)
			{
				DeleteObject(i->GethBitmap());
				i->PicLoadImage(_T("smilefaceclicked.bmp"));
				Paint();
				Sleep(100);
				g_MineSweeperGameLogic->InitialCell();
				for (auto&j : g_ButtonList)
				{
					if (j->GetControlID() > 0 && j->GetControlID() < 200)
					{
						DeleteObject(j->GethBitmap());
						j->PicLoadImage(_T("space.bmp"));
					}
				}
				DeleteObject(i->GethBitmap());
				i->PicLoadImage(_T("smilefaceUnclick.bmp"));
				Paint();
			}
		}
	};

};




//�w�����^�ը��
class safePlace :public cCallBackFunctorBasic
{
public:
	safePlace(){};
	~safePlace(){};
	void operator()()
	{
		
		MessageBox(NULL,_T("huuuu~"), _T("SAFE"), MB_OK);

	}

};

/*********************************************************************************************/
//GUI��{�D��
/*********************************************************************************************/
class cMineSweeperGUI
{
public:
	cMineSweeperGUI(HINSTANCE hinstance);
	~cMineSweeperGUI() {};
private:
	cMineSweeperLogic* m_GameLogic;
	int m_CellWNum ;
	int m_CellHNum ;
	int m_MineNum ;
};



cMineSweeperGUI::cMineSweeperGUI(HINSTANCE hInstance)
{

	g_GUIMgptr = new GUIManager(hInstance);
	g_GUIMgptr->GUICreateWindow(_T("��a�p"), MAKEINTRESOURCE(IDR_MENU1), GUIWINDOW_WIDTH, GUIWINDOW_HEIGHT);


	m_CellWNum = 11;
	m_CellHNum = 12;

	m_MineNum = GAMEMINE_NUM;
	

	//�s�W�C���޿�
	g_MineSweeperGameLogic = new cMineSweeperLogic(m_CellWNum,m_CellHNum,m_MineNum);
	tagPOINT psbk = { 0 };

	//ø�s�I��
	int w = g_GUIMgptr->GUIGetClientSize().x;
	int h = g_GUIMgptr->GUIGetClientSize().y;
	g_GUIMgptr->GUICreatePicture(psbk, w,h,
	GAMEBACKGRAOUND_IMG_CONTROL, _T("background.bmp"));


	//ø�s�H�y
	tagPOINT psface = { 0 };
	psface.x = GAMEFACE_MARGIN_LEFT;
	psface.y = GAMEFACE_MARGIN_TOP;

	GameFace* pfacefunc = new GameFace();
	g_GUIMgptr->GUICreateButton(psface, 24, 24, GAMEFACE_BUT_CONTROLID, _T("SmilefaceUnclick.bmp"), pfacefunc);


	//ø�s�ѽL
	for (int i = 0; i != m_CellHNum; i++)
	{
		for (int j = 0; j != m_CellWNum; j++)
		{
			int a = 1+i*m_CellWNum + j;
			HideMine* phide = new HideMine(a);
			
			tagPOINT ps = { 0 };
			ps.x = GAMEWINDOW_MARGIN_LEFT+j*16;
			ps.y = GAMEWINDOW_MARGIN_TOP+i*16;
			g_GUIMgptr->GUICreateButton(ps, 16, 16,a, _T("space.bmp"),phide);
	
			
		}
	}
	g_GUIMgptr->GUIRunWindow();

}






void	ShowAllMine()
{
	for (auto& i : g_MineSweeperGameLogic->GetIdHadMine())
	{
		for (auto&j : g_ButtonList)
		{
			if (j->GetControlID() == i + 1)
			{
				DeleteObject(j->GethBitmap());
				j->PicLoadImage(_T("bump.bmp"));
				Paint();
			}
		}

	}
}





void ReDrawStatus()
{
	for (int i = 0; i != g_MineSweeperGameLogic->GetTotalNum(); i++)
	{
		if ((*g_MineSweeperGameLogic->m_sh_pGameStatus).at(i)==gameStatus::Checked)
		{
			for (auto&j : g_ButtonList)
			{
				if (j->GetControlID() == i + 1)
				{
					DeleteObject(j->GethBitmap());
					j->PicLoadImage(_T("beenClick.bmp"));
					Paint();
				}
			}


		}
		
	}

}