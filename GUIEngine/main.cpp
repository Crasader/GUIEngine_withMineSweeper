#include"StdInclude.h"

#include "MinesweeperGui.h"
#pragma comment(lib,"user32.lib")
/*******************************************************************************************/
//¥þ°ìÅÜ¼Æ
/*******************************************************************************************/

std::map<HWND, GUIManager*>g_WindowHandleMap;
std::map<HWND, GUIManager*>::iterator g_it;



using namespace std;


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	cMineSweeperGUI* GameGui = new cMineSweeperGUI(hInstance);
	return 0;
}