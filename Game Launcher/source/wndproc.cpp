#include "WndProc.hpp"
#include "ItemManager.hpp"
#include "GUI/SceneManager.hpp"
#include <wmsg.h>


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	static SceneManager *Scene = nullptr;

	switch (msg)
	{
	case WM_CREATE:
		SendMessage(hWnd, WM_ITEM_SCAN, 0, 0);
		Scene = new SceneManager(hWnd, SceneName_MainMenu, ((LPCREATESTRUCT)lp)->cx, ((LPCREATESTRUCT)lp)->cy);
		Scene->Initialize(hWnd);
		ShowWindow(hWnd, SW_SHOW);
		return 0;

	case WM_DESTROY:
		Scene->Finalize(hWnd);
		delete Scene;
		Scene = nullptr;
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		return Scene->Paint(hWnd);

	case WM_ERASEBKGND:
		return true;

	case WM_MOUSEMOVE:
		return Scene->MouseMove(hWnd, wp, lp);

	case WM_LBUTTONDOWN:
		return Scene->LButtonDown(hWnd, wp, lp);

	case WM_LBUTTONUP:
		return Scene->LButtonUp(hWnd, wp, lp);

	case WM_RBUTTONDOWN:
		return Scene->RButtonDown(hWnd, wp, lp);

	case WM_RBUTTONUP:
		return Scene->RButtonUp(hWnd, wp, lp);

	case WM_ITEM_SCAN:
		return ItemManager::ScanItems();

	case WM_ITEM_CLEAR:
		ItemManager::ClearItems();
		return 0;

	case WM_GUI_UPDATE:
		return Scene->Update(hWnd);

	case WM_GUI_CHANGESCENE:
		return Scene->ChangeScene(hWnd, wp);

	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
}