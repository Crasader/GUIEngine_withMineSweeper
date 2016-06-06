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
	//建構子
	ControlBasic(tagPOINT Pos,
		int width,
		int Height,
		int ControlID);
	//解構子
	~ControlBasic();

	virtual	void SetPosition(tagPOINT t);
	virtual	tagPOINT GetPosition();
	virtual	void SetWidth(int n);
	virtual	int GetWidth();
	virtual	void SetHeight(int n);
	virtual	int GetHeight();
	virtual void SetControlID(int n);
	virtual int GetControlID();


protected:


	tagPOINT m_ControlPosition;
	int		m_nWidth;
	int		m_nHeight;
	int		m_ControlID;
private:
	std::vector<ControlEventType> m_EventTypes;
};