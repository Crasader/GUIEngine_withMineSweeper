#pragma once
#include "stdInclude.h"
#include <assert.h>
#include "define.h"



/**************************************************************************/
//�C�����A�����ŧi
/**************************************************************************/
enum class gameStatus
	{
	nearHasMine1 = 1,
	nearHasMine2 = 2,
	nearHasMine3 = 3,
	nearHasMine4 = 4,
	nearHasMine5 = 5,
	nearHasMine6 = 6,
	nearHasMine7=7,
	nearHasMine8=8,
	userUseFlag=9,
	mine=999,
	Checked=600,
	safe=0,
};

/*************************************************************************/
//�s�x�C�����A��vector
/*************************************************************************/



class cMineSweeperLogic
{
public:
	std::shared_ptr<std::vector<gameStatus>> m_sh_pGameStatus;

	std::vector<int> GetIdHadMine(){ return this->m_idHadMine; };


	/**************************************************************************/
	//�Ǧ^�ȱo���
	/**************************************************************************/
	int GetTotalNum()
	{
		return this->m_TotalCellNum;
	}






public:

	//�غc�l�A��J����Ƭ��C�����j�p,�H�Φa�p�Ӽ�,���s(�����)�e
	cMineSweeperLogic(int x, int y, int num)
	{
		//�T�O�Ыت��C�������j��10*10
		assert(x >= 3);
		assert(y >= 3);
		//�T�O�a�p�ӼƤ��|�W�L�`�ѽL�Ӽ�
		assert(x*y >= num);
		//��l�ƴѧ�
		srand(time(NULL));
		m_bumbNum = num;
		m_CellWNum = x;
		m_CellHNum = y;
		m_TotalCellNum = x*y;
		m_SafePath.clear();
		this->InitialCell();
	
	}
/************************************************************************************/
//��ϥΪ̦��\�U�F�@�l����A�i��E�c��M���p��
/************************************************************************************/

int  CheckMine(int n)
	{
	//�V���ˬd
	if (n == -1)
	{
		return -1;
	}

		if ((*m_sh_pGameStatus).at(n) == gameStatus::mine)
		{	
			return 1;
		}
		else
		{
			return 0;
		}

	}

///*********************************************************************************/
////�z�靈���u�εL���u�����A
///*********************************************************************************/
//int PickTheEventHaveBumb(int n)
//{
//	if (n ==0)//�p�G�L���u
//	{
//		return 0;
//	}
//	if (n==1)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//

/********************************************************************************/
//��o�w������
/*********************************************************************************/
//void GetSafePath(int n)
//{
//
//	/***
//	//check has mine return 0,1,2
//	
//	
//	***/
//
//
//	if (n > m_TotalCellNum)
//	{
//		return;
//	}
//	(*m_sh_pGameStatus).at(n) = gameStatus::Checked;
//	int nTop = CheckHasMine(n, 1, 0);//�W
//	int nTR = PickTheEventHaveBumb(CheckHasMine(n, 1, 1));//�k�W
//	int nRight =CheckHasMine(n, 0, 1);//�k
//	int nRB =PickTheEventHaveBumb(CheckHasMine(n, -1, 1));//�k�U
//	int nButtom =CheckHasMine(n, -1, 0);//�U
//	int nBL = PickTheEventHaveBumb(CheckHasMine(n, -1, -1));//���U
//	int nLeft =CheckHasMine(n, 0, -1);//��
//	int nTL = PickTheEventHaveBumb(CheckHasMine(n, 1, -1));//���W
//
//
//	if (nTop == 0)
//	{
//		if ((*m_sh_pGameStatus).at(GetNPos(n,1,0)) != gameStatus::Checked)
//		m_SafePath.push_back(n-m_CellWNum);
//	}
//	if (nRight == 0)
//	{
//		if ((*m_sh_pGameStatus).at(GetNPos(n,0,1)) != gameStatus::Checked)
//		m_SafePath.push_back(n+1);
//	}
//	if (nLeft == 0)
//	{
//		if ((*m_sh_pGameStatus).at(GetNPos(n, 0, -1)) != gameStatus::Checked)
//		m_SafePath.push_back(n-1);
//	}
//
//	if (nButtom == 0)
//	{
//		if ((*m_sh_pGameStatus).at(GetNPos(n, -1, 0)) != gameStatus::Checked)
//		m_SafePath.push_back(n+m_CellWNum);
//	}
//
//
//	nTop = PickTheEventHaveBumb(nTop);
//	nRight = PickTheEventHaveBumb(nRight);
//	nLeft = PickTheEventHaveBumb(nLeft);
//	nButtom = PickTheEventHaveBumb(nButtom);
//	//��o�ӾF���l�W���Ҧ����u�q
//	std::vector<int> temp_v;
//	if (nTop > 0)
//	{
//
//		temp_v.push_back(nTop);
//	}
//	if (nTR > 0)
//	{
//
//		temp_v.push_back(nTR);
//	}
//	if (nButtom>0)
//	{
//
//		temp_v.push_back(nButtom);
//	}
//	if (nBL > 0)
//	{
//
//		temp_v.push_back(nBL);
//	}
//	if (nLeft > 0)
//	{
//		temp_v.push_back(nLeft);
//	}
//	if (nTL > 0)
//	{
//		temp_v.push_back(nTL);
//	}
//
//	int sum=0;
//	for (auto& i: temp_v)
//	{
//		sum += i;
//	}
//
//		switch (sum)
//		{
//		case 0:
//		{
//			(*m_sh_pGameStatus).at(n) = gameStatus::safe;
//			break;
//		}
//
//		case 1:
//		{
//			(*m_sh_pGameStatus).at(n) = gameStatus::nearHasMine1;
//			break;
//		}
//		case 2:
//		{
//			(*m_sh_pGameStatus).at(n) = gameStatus::nearHasMine2;
//			break;
//		}
//		case 3:
//		{
//			(*m_sh_pGameStatus).at(n) = gameStatus::nearHasMine3;
//			break;
//		}
//		case 4:
//		{
//			(*m_sh_pGameStatus).at(n) = gameStatus::nearHasMine4;
//			break;
//		}
//		case 5:
//		{
//			(*m_sh_pGameStatus).at(n) = gameStatus::nearHasMine5;
//			break;
//		}
//		case 6:
//		{
//			(*m_sh_pGameStatus).at(n) = gameStatus::nearHasMine6;
//			break;
//		}
//		case 7:
//		{
//			(*m_sh_pGameStatus).at(n) = gameStatus::nearHasMine7;
//			break;
//		}
//		case 8:
//		{
//			(*m_sh_pGameStatus).at(n) = gameStatus::nearHasMine8;
//			break;
//		}
//		return;
//	}
//		
//	while (!m_SafePath.empty())
//	{
//		int nNewn = m_SafePath.back();
//		GetSafePath(nNewn);
//		m_SafePath.pop_back();
//	}
//	return;
//	}
	

void GetSafePath(int n)
{
	int top = GetTop(n);
	int Right = GetRight(n);
	int Left = GetLeft(n); 
	int Buttom = GetButtom(n);
	while (top != -1)
	{
		if (std::find(m_idHadMine.begin(), m_idHadMine.end(), top )!= m_idHadMine.end())
		{
			(*m_sh_pGameStatus).at(top) = gameStatus::Checked;
		}
		top = GetTop(top);
	}

	while (Right != -1)
	{

		if (std::find(m_idHadMine.begin(), m_idHadMine.end(), Right) != m_idHadMine.end())
			{
			(*m_sh_pGameStatus).at(Right) = gameStatus::Checked;
		}
		Right = GetRight(Right);
	}


	while (Left!=-1)
		{
		if (std::find(m_idHadMine.begin(), m_idHadMine.end(), Left) != m_idHadMine.end())
		{
			(*m_sh_pGameStatus).at(Left) = gameStatus::Checked;
		}
		Left = GetLeft(Left);
	}

	while (Buttom != -1)
	{
		if (std::find(m_idHadMine.begin(), m_idHadMine.end(), Buttom) != m_idHadMine.end())
		{
			(*m_sh_pGameStatus).at(Buttom) = gameStatus::Checked;
		}
		Buttom = GetButtom(Buttom);

	}



}



/************************************************************************************/
//��V�y�����ڮy��
/************************************************************************************/
int GetNPos(int CellPos, int goTorD, int goRorL)
{

	if ((CellPos+goRorL) > m_TotalCellNum)
	{
		return -1;
	}

	if ((CellPos+goRorL)%m_CellWNum == 0&&CellPos!=0)//���p�Ѥl�b�̥k��
	{
		if (goRorL == 1)
		{
			return -1;
		}
	}
	if ((CellPos+goRorL) % m_CellWNum == 0)
	{
		if (goRorL == -1)//���p�Ѥl�b�̥���
		{
			return -1;
		}
	}

	if ((CellPos+goRorL - m_CellWNum) <= 0)//���p�X�l�b�̤W

	{
		if (goTorD == 1)
		{
			return -1;
		}
	}

	if (((CellPos+goRorL) / m_CellWNum == m_CellHNum) || (CellPos+goRorL) / m_CellWNum == (m_CellHNum - 1))
	{

		if (goTorD == -1)
		{

			return -1;
		}
	}

	return (CellPos - goTorD*m_CellWNum + goRorL);






}
/********************************************************************************/
//�ˬd���A���򥻨��
/****************************************************************************/
//int CheckHasMine(int CellPos, int goTorD, int goRorL)
//{
//	int n = GetNPos(CellPos, goTorD, goRorL);
//		if (n != -1)
//		{
//		if ((*m_sh_pGameStatus).at(n) == gameStatus::mine)
//		{
//			return 1;//�����u
//		}
//		else if ((*m_sh_pGameStatus).at(n) != gameStatus::safe)
//		{
//			return 2;//�w�g�]�m�L���A
//		}
//		else {
//			return 0;//�L���u
//		}
//
//		}
//}

/****************************************************************************/
int GetTop(int n){ return GetNPos(n, 1, 0); };
int GetRT(int n){ return GetNPos(n, 1, 1); };
int GetRight(int n){ return GetNPos(n, 0, 1); };
int GetRB(int n){ return GetNPos(n, -1, 1); };
int GetButtom(int n){ return GetNPos(n, -1, 0); };
int GetLB(int n){ return GetNPos(n, -1 ,- 1); };
int GetLeft(int n){ return GetNPos(n, 0, -1); };
int GetLT(int n){ return GetNPos(n, 1, -1); };



/****************************************************************************/
//��l�ƴѽL���A
/*****************************************************************************/
	
	void InitialCell()
	{

		//��l�Ƽƾ�
		m_PridictStatus.clear();
		m_SafePath.clear();
		m_idHadMine.clear();
		m_sh_pGameStatus = nullptr;
		m_sh_pGameStatus = std::make_shared<std::vector<gameStatus>>(m_CellWNum*m_CellHNum);
		m_PridictStatus = std::vector<int>(m_CellHNum*m_CellWNum);
		//��@�}�l�ҳ]���ŴѽL
		std::fill((*m_sh_pGameStatus).begin(), (*m_sh_pGameStatus).end(), gameStatus::safe);
		std::fill(m_PridictStatus.begin(), m_PridictStatus.end(), 0);
		//�W�[�a�p
		for (int i = 0; i != m_bumbNum; i++)
		{
			int bumbx = rand() % m_CellWNum;
			int bumby = rand() % m_CellHNum;
			m_idHadMine.push_back(bumbx*m_CellWNum + bumby);
			(*m_sh_pGameStatus).at(bumbx*m_CellWNum + bumby) = gameStatus::mine;
		}
		this->initialCellforPredict();
	}


/**********************************************************************************/
//��l�Ʊ����L
/*********************************************************************************/


	void initialCellforPredict()
	{
		for (int i = 0; i != m_TotalCellNum; i++)
		{

			int sum=0;
			if ((m_sh_pGameStatus->at(i)) != gameStatus::mine)
			{
				if (GetTop(i) != -1)
				{
					if (m_sh_pGameStatus->at(GetTop(i)) == gameStatus::mine)
					{
						sum += 1;
					}

				}
				if (GetRT(i) != -1)
				{
					if (m_sh_pGameStatus->at(GetRT(i))==gameStatus::mine)
						{
						sum += 1;
					}
				}
				if (GetRight(i) != -1)
				{
				}


			}
		}


		TurnToStatus();
	}
	
/***********************************************************************************/
//�N�w���ಾ�� m_sh_status
/************************************************************************************/
	
	void TurnToStatus()
{
		int Count = 0;
		for (int i = 0; i != m_TotalCellNum;i++)
		{
			if ((*m_sh_pGameStatus).at(Count) != gameStatus::mine)
			{
				switch (i)
				{
				case	1:
				{
					(*m_sh_pGameStatus).at(Count) = gameStatus::nearHasMine1;
					break;
				}
				case   2:
				{
					(*m_sh_pGameStatus).at(Count) = gameStatus::nearHasMine2;
					
					break;
				}
				case 3:
				{
					(*m_sh_pGameStatus).at(Count) = gameStatus::nearHasMine3;
					break;
				}
				case 4:
				{
					(*m_sh_pGameStatus).at(Count) = gameStatus::nearHasMine4;
					break;
				}
				case 5:
				{
					(*m_sh_pGameStatus).at(Count) = gameStatus::nearHasMine5;
					break;
				}
				case 6:
				{
					(*m_sh_pGameStatus).at(Count) = gameStatus::nearHasMine6;
					break;
				}
				case 7:
				{
					(*m_sh_pGameStatus).at(Count) = gameStatus::nearHasMine7;
					break;
				}
				case 8:
				{
					(*m_sh_pGameStatus).at(Count) = gameStatus::nearHasMine8;
					break;
				}
				default:
					break;
				}
			}
			Count++;
		}
	}


	~cMineSweeperLogic()
	{
		//share_ptr �|�ۤvDELETE�A�����ѦҴN��
		m_sh_pGameStatus = nullptr;
	}

private:


	
	int		m_CellWNum;
	int		m_CellHNum;
	int		m_bumbNum;
	std::vector<int> m_idHadMine;
	bool m_isGameStart;
	int m_TotalCellNum;
	

	std::vector<int>	m_PridictStatus;
	std::vector<int>	m_CheckNearMineCell;
	std::vector<int>	m_SafePath;
};

