#pragma once 
#include "cPicture.h"
#include "cCallbackFunctor.h"
class cButton : public cPicture
{
public:
	cButton(tagPOINT Pos,
		int width, int Height, ControlEventType eveType,int ControlID,LPTSTR filepath,cCallBackFunctorBasic*);
	~cButton();
	//«ö¶s¦^½Õ¨ç¼Æ
	cCallBackFunctorBasic* m_CallbackFunctor;

public:
	bool GetIsEnable(){ return this->m_IsEnable; };
	void SetIsEnableP(bool b){ this->m_IsEnable = b; };

private:
	bool m_IsEnable;
};



cButton::cButton(tagPOINT Pos,
	int width, int Height, ControlEventType eveType,int ControlID, LPTSTR filepath,cCallBackFunctorBasic* pfunctor):cPicture(Pos, width, Height, eveType,ControlID), m_CallbackFunctor(pfunctor)
{
	m_IsEnable = true;
}