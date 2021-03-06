#include "Button.hpp"


button::button(unsigned short Width, unsigned short Height)
	:mem_dc(Width, Height)
{
	x = 0;
	y = 0;
}

button::~button()
{

}

void button::SetPosition(unsigned short x, unsigned short y)
{
	this->x = x;
	this->y = y;
}

bool button::PointInButtonRect(unsigned short x, unsigned short y)const
{
	RECT Rect;
	Rect.left = this->x;
	Rect.top = this->y;
	Rect.right = Rect.left + Width;
	Rect.bottom = Rect.top + Height;
	return PtInRect(&Rect, POINT{x, y}) != 0;
}

void button::Paint(HDC hDC)const
{
	BitBlt(hDC, x, y, Width, Height, hMemDC, 0, 0, SRCCOPY);
}

void button::Color(const color &Color)
{
	Color.Rectangle(hMemDC, 0, 0, Width, Height);
}

void button::ColorGradation(const color &Color)
{
	Color.RectangleGradation(hMemDC, 0, 0, Width, Height);
}

void button::MaskBitmap(LPCTSTR FilePath)
{
	HDC hMaskDC = CreateCompatibleDC(NULL);
	HANDLE hMaskBmp = LoadImage(NULL, FilePath, IMAGE_BITMAP, Width, Height, LR_LOADFROMFILE);
	SelectObject(hMaskDC, hMaskBmp);
	Mask(hMaskDC);
	DeleteDC(hMaskDC);
	DeleteObject(hMaskBmp);
}

void button::Mask(HDC hDC)
{
	BitBlt(hMemDC, 0, 0, Width, Height, hDC, 0, 0, SRCAND);
}

RECT button::GetAbsoluteRect()const
{
	return RECT{x, y, x + Width, y + Height};
}

RECT button::GetRelativeRect() const
{
	return RECT{0, 0, Width, Height};
}
