#include "DxLib.h"
#include "Config.h"
#include "GameObject.h"
#include "StageCreator.h"

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

    StageCreator::Load(StageLevel::Easy);

    while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
    {
        ClearDrawScreen();

        GameObject::UpdateAll();
        GameObject::DrawAll();

        ScreenFlip();
    }

    StageCreator::Delete();

    DxLib_End();
    return 0;
}
