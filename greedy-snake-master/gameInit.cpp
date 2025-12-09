#include "gameInit.h"
#include "tools.h"
#include "sceneControll.h"
#include "mainScene.h"


int gameInit::Width = 41;
int gameInit::Height = 32;
int gameInit::FrameRatio = 60;

/// <summary>
/// 游戏初始类
/// </summary>
void gameInit::Start() {
	// 游戏入口

	//舞台大小
	SetWindowSize(gameInit::Width, gameInit::Height);

	sceneControll::addView(new mainScene());

}

void gameInit::clear()
{
	SetColor(2);
	system("cls");
}
