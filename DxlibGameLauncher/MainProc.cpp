#include "DxLib.h"
#include "OperationData.h"

// extern 書き込み場所
bool Ope::APPLICATION_END_FLAG = FALSE;
SceneManager Ope::sceneManager;
int Ope::CURRENT_WINDOW_SIZE_X;
int Ope::CURRENT_WINDOW_SIZE_Y;
int Ope::CURRENT_WINDOW_COLOR_BIT;
int Ope::ER_WINDOW_SIZE_X;
int Ope::ER_WINDOW_SIZE_Y;
HWND Ope::MAIN_WINDOW_HANDLE;
float Ope::WINDOW_SIZE_RATE;
float Ope::WINDOW_SIZE_RATE_TIME;

#pragma warning(push)
#pragma warning(disable:28251)

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);
	SetUseDirectInputFlag(TRUE);
	SetAlwaysRunFlag(TRUE);

	Ope::MAIN_WINDOW_HANDLE = GetMainWindowHandle();
	//SetWindowText("KCCT");

	DxLib_Init();

	while(!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen())
	{
		SetDrawScreen(DX_SCREEN_BACK);

	}

	return 0;				// ソフトの終了 
}

#pragma warning(pop)