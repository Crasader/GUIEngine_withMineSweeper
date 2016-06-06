#pragma once 
#include "StdInclude.h"

//回調函數基類，回調函數繼承這個類別，時做方法


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