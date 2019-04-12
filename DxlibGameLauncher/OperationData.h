#pragma once
#include "SceneManager.h"
//#include "ObjectManager.h" add よてい
#include "DxLib.h"


namespace Ope {// externで各ソースを共有する

	extern bool APPLICATION_END_FLAG;

	extern SceneManager sceneManager;
	//extern ObjectManager objectManager; add 予定

	extern int CURRENT_WINDOW_SIZE_X;
	extern int CURRENT_WINDOW_SIZE_Y;
	extern int CURRENT_WINDOW_COLOR_BIT;

	extern int ER_WINDOW_SIZE_X;
	extern int ER_WINDOW_SIZE_Y;

	extern HWND MAIN_WINDOW_HANDLE;

	extern float WINDOW_SIZE_RATE;
	extern float WINDOW_SIZE_RATE_TIME;
};