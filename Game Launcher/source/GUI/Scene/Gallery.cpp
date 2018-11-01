#include "Gallery.hpp"
#include "wmsg.h"


item_button::item_button(unsigned short Width, unsigned short Height)
	:button(Width, Height)
{

}

item_button::~item_button()
{

}

const color gallery::ColorAccent[MAX_CATEGORY] = {
	RGB(0xdf, 0x3f, 0x3f),
	RGB(0xbf, 0xbf, 0x3f),
	RGB(0xaf, 0x2f, 0x9f),
	RGB(0x2f, 0xaf, 0xaf),
	RGB(0x2f, 0x5f, 0xdf),
	RGB(0x2f, 0xdf, 0x5f),
	RGB(0x7f, 0x7f, 0x7f)
};

void gallery::CreateButtons()
{
	int NumItems = Items.size();
	Buttons.resize(NumItems);
	for (int i = 0; i < NumItems; ++i)
	{
		Buttons[i] = new item_button(Width / 2, Height / 10);
		Buttons[i]->SetPosition(0, Height * i / 10);
		ButtonColor.RectangleGradation(Buttons[i]->hMemDC, Buttons[i]->GetRelativeRect());
	}
	ColorAccent[Category].RectangleGradation(MainMenuButton.hMemDC, MainMenuButton.GetRelativeRect());
}

void gallery::DeleteButtons()
{
	int NumButtons = (int)Buttons.size();
	for (int i = 0; i < NumButtons; ++i)
	{
		delete Buttons[i];
	}
}

void gallery::DrawBkgnd()
{
	for (int i = 0; i < Items.size(); ++i)
	{
		Buttons[i]->Paint(MenuWindow.hMemDC);
	}
	MainMenuButton.Paint(hMemDC);
	MenuWindow.Paint(hMemDC);
	PreviewWindow.Paint(hMemDC);
}

gallery::gallery(scene_manager_interface *SceneChanger, category Category, unsigned short BmpWidth, unsigned short BmpHeight)
	:scene(SceneChanger, BmpWidth, BmpHeight),
	Category(Category),
	ButtonColor(ColorAccent[Category].GetColorSubCode()),
	MenuWidth(BmpWidth / 2),
	MainMenuButton(200, 100),
	Items(ItemManager::GetItems(Category)),
	MenuWindow(MenuWidth, Items.size() * BmpHeight / 10),
	PreviewWindow(BmpWidth - MenuWidth, BmpHeight - 150)
{
	CreateButtons();
	MenuWindow.SetPosition(0, 0);
	MenuWindow.SetWindowSize(MenuWidth, BmpHeight);
	PreviewWindow.SetPosition(MenuWidth, 0);
	PreviewWindow.SetWindowSize(BmpWidth - MenuWidth, BmpHeight - 150);
	MainMenuButton.SetPosition(BmpWidth - 300, BmpHeight - 150);
	ColorBkgnd.Rectangle(MenuWindow.hMemDC, 0, 0, MenuWidth, Height);
	ColorBkgnd.Rectangle(PreviewWindow.hMemDC, 0, 0, Width - MenuWidth, Height);
}

gallery::~gallery()
{
	DeleteButtons();
}

int gallery::LButtonUp(HWND hWnd, WPARAM wp, LPARAM lp)
{
	unsigned short x = LOWORD(lp);
	unsigned short y = HIWORD(lp);
	if (MainMenuButton.PointInButtonRect(x, y))
	{
		PostMessage(hWnd, WM_GUI_CHANGESCENE, SceneName_MainMenu, 0);
	}
	return 0;
}