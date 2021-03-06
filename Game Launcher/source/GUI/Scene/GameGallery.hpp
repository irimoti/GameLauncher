#pragma once

#include "Gallery.hpp"

#ifndef INCLUDE_GAMEGallery_HPP
#define INCLUDE_GAMEGallery_HPP


class GameGallery :public Gallery
{
public:
	GameGallery(HWND hWnd, SceneChangerInterface* SceneChanger, unsigned short BmpWidth, unsigned short BmpHeight);
	int Initialize(HWND hWnd);
	int Finalize(HWND hWnd);
	int LButtonUp(HWND hWnd, WPARAM wp, LPARAM lp);
	int Update(HWND hWnd);
};


#endif