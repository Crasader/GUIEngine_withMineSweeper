#pragma once
/**********************************************************************************/
//���f�ѼƩw�q
/**********************************************************************************/
	//���f����
#define GUIWINDOW_STYLE     WS_OVERLAPPED|WS_SYSMENU|WS_CAPTION|WS_MINIMIZEBOX
	//���f�W
#define	GUIWINDOW_TITLE		"GUIEngine"
	//���f����
#define GUIWINDOW_WIDTH		240
	//���f��
#define GUIWINDOW_HEIGHT	380
	//���f���ID
#define GUIWINDOW_MENU		IDC_MENU1



/**********************************************************************************/
//�C�������w�q
/**********************************************************************************/
//�a�p�����e�A�����

#define GAMEWINDOW_CELLWIDTH_HEIGHT	16

//�ѽL�P���f����
//			���Z�@	
//			�z�w�w�w�{
//	���Z�|	|	�f	 |	���Z�G
//			�|�w�w�w�}
//			���Z�T

	//���Z�@
#define GAMEWINDOW_MARGIN_TOP 90
	//���Z�G
#define GAMEWINDOW_MARGIN_RIGHT 20
	//���Z�T
#define GAMEWINDOW_MARGIN_BUT 20
	//���Z�|
#define GAMEWINDOW_MARGIN_LEFT 20

	//�y����m
#define GAMEFACE_MARGIN_TOP			30
#define GAMEFACE_MARGIN_LEFT 		100	


	//�a�p�Ӽ�
#define GAMEMINE_NUM	20




namespace GUITYPE{
	
	typedef void (*pfunc)();


	enum class ControlEventType
	{
		Button = 1,
		Image,
		Editor
	};

}


//���~�w�q
#define  ERRORDEF_GLOBAL_EXSISTED -1
