#include "ControlBasic.h"
#include "define.h"
#include "StdInclude.h"



ControlBasic::ControlBasic(
tagPOINT Pos,
int width,
int Height,
//ControlEventType eveType, 改用 regist event 得方式進行
int ControlID
):m_ControlPosition(Pos),
m_nHeight(Height),
m_nWidth(width),
m_ControlID(ControlID)
{
}



void			 ControlBasic::SetPosition(tagPOINT t){ this->m_ControlPosition = t; };
tagPOINT		 ControlBasic::GetPosition(){ return this->m_ControlPosition; };
void			 ControlBasic::SetWidth(int n){ this->m_nWidth = n; };
int				 ControlBasic::GetWidth(){ return this->m_nWidth; };
void			 ControlBasic::SetHeight(int n){ m_nHeight = n; };
int				 ControlBasic::GetHeight(){ return this->m_nHeight; };
void			 ControlBasic::SetControlID(int n){ this->m_ControlID = n; };
int				 ControlBasic::GetControlID(){ return this->m_ControlID; };


