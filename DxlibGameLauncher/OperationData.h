#pragma once
#include "SceneManager.h"
//#include "ObjectManager.h" add ��Ă�
#include "DxLib.h"


namespace Ope {// extern�Ŋe�\�[�X�����L����

	extern bool APPLICATION_END_FLAG;

	extern SceneManager sceneManager;
	//extern ObjectManager objectManager; add �\��

	extern int CURRENT_WINDOW_SIZE_X;
	extern int CURRENT_WINDOW_SIZE_Y;
	extern int CURRENT_WINDOW_COLOR_BIT;

	extern int ER_WINDOW_SIZE_X;
	extern int ER_WINDOW_SIZE_Y;

	extern HWND MAIN_WINDOW_HANDLE;

	extern float WINDOW_SIZE_RATE;
	extern float WINDOW_SIZE_RATE_TIME;
};