#pragma once
#include "StdInclude.h"
#include "define.h"




/********************************************************************************************/
//定義:
//資料類型定義
/********************************************************************************************/
//enum class ControlEventType
//{
//	Button = 1,
//	Image,
//	Editor
//};
using namespace GUITYPE;


/*******************************************************************************************/
//類別:
//控件基類
/*******************************************************************************************/
class ControlBasic
{

public:
	ControlBasic(tagPOINT Pos,
		int width,
		int Height,
		ControlEventType eveType,int ControlID);
	~ControlBasic();

	virtual	void SetPosition(tagPOINT t){ this->m_ControlPosition = t; };
	virtual	tagPOINT GetPosition(){ return this->m_ControlPosition; };
	virtual	void SetWidth(int n){ this->m_nWidth = n; };
	virtual	int GetWidth(){ return this->m_nWidth; };
	virtual	void SetHeight(int n){ m_nHeight = n; };
	virtual	int GetHeight(){ return this->m_nHeight; };
	virtual void SetControlID(int n){ this->m_ControlID = n; };
	virtual int GetControlID(){ return this->m_ControlID; };

protected:


	tagPOINT m_ControlPosition;
	int		m_nWidth;
	int		m_nHeight;
	int		m_ControlID;

private:

	ControlEventType m_EveType;
};




//建構子
ControlBasic::ControlBasic(
	tagPOINT Pos,
	int width,
	int Height,
	ControlEventType eveType,
	int ControlID
	):m_ControlPosition(Pos),
	m_nHeight(Height),
	m_nWidth(width),
	m_EveType(eveType),
	m_ControlID(ControlID)
{



};



//解構子
ControlBasic::~ControlBasic()
{



};


