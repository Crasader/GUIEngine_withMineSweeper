#include "cButton.h"
#include "StdInclude.h"
#include "define.h"

bool cButton::GetIsEnable(){ return this->m_IsEnable; };
void cButton::SetIsEnableP(bool b){ this->m_IsEnable = b; };


cButton::cButton(tagPOINT Pos,
	int width, int Height, int ControlID, LPTSTR filepath, cCallBackFunctorBasic* pfunctor) :cPicture(Pos, width, Height, ControlID), m_CallbackFunctor(pfunctor)
{
	m_IsEnable = true;
}