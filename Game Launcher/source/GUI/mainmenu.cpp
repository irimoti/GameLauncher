#include "mainmenu.hpp"


MainMenu::MainMenu(HWND hWnd, unsigned short BmpWidth, unsigned short BmpHeight) :Scene(BmpWidth, BmpHeight)
{
	hBrushBkgnd = CreateSolidBrush(RGB(0x3f, 0x3f, 0x3f));
}

MainMenu::~MainMenu()
{
	SelectObject(GethMemDC(), GetStockObject(NULL_BRUSH));//hMemDCがまだ破棄されていないので、別のブラシを選択しておく
	DeleteObject(hBrushBkgnd);
	hBrushBkgnd = NULL;
}

int MainMenu::Initialize(HWND hWnd)
{
	HDC hdc = GethMemDC();

	//背景を塗りつぶす
	SelectObject(hdc, hBrushBkgnd);
	Rectangle(hdc, 0, 0, GetWidth(), GetHeight());

	return 0;
}

int MainMenu::Finalize(HWND hWnd)
{
	return 0;
}

int MainMenu::ChangeScene(HWND hWnd, int NextScene)
{
	return 0;
}