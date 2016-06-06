#pragma once 
#include "cPicture.h"
#include "cCallbackFunctor.h"
class cButton : public cPicture
{
public:
	cButton(tagPOINT Pos,
		int width, int Height,int ControlID,LPTSTR filepath,cCallBackFunctorBasic*);
	~cButton();
	//���s�^�ը��
	cCallBackFunctorBasic* m_CallbackFunctor;

public:
	bool GetIsEnable();
	void SetIsEnableP(bool b);

private:
	bool m_IsEnable;
};
