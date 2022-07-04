#include "DxLib.h"
#include "Player.h"
#include "Ground.h"
#include "Collision.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(true);
    SetMainWindowText("Title");
    SetWindowIconID(LoadGraph(""));
    SetGraphMode(1280, 720, 32);
    SetDrawMode(DX_SCREEN_BACK);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    Player player(100, 500, 64, 64);
    Ground ground1(0, 620, 1280, 100);
    Ground ground2(400, 500, 1280, 100);
    Ground ground3(800, 300, 1280, 100);

    while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
    {
        ClearDrawScreen();

        GameObject::UpdateAll();
        GameObject::DrawAll();

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}
