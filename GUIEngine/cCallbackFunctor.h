#pragma once 
#include "StdInclude.h"

//�^�ը�ư����A�^�ը���~�ӳo�����O�A�ɰ���k


class cCallBackFunctorBasic
{
public:
	cCallBackFunctorBasic();
	~cCallBackFunctorBasic();
	virtual	void operator()() = 0;
private:
	int x;
	int y;
};