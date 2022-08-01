#include "DxLib.h"
#include "Config.h"
#include "GameManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(true);
    SetMainWindowText("Title");
    SetWindowIconID(LoadGraph(""));
    SetGraphMode(WIN_WIDTH, WIN_HEIGHT, COLOR_BIT_DEPTH);
    SetDrawMode(DX_SCREEN_BACK);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    GameManager::Init(StageLevel::Normal);

    while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
    {
        ClearDrawScreen();

        GameManager::Play();

        ScreenFlip();
    }

    GameManager::End();

    DxLib_End();
    return 0;
}
