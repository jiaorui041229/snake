#include "mainScene.h"
#include "UI_Logo.h"
#include "tools.h"
#include "snake.h"

void mainScene::Init()
{
	SetColor(2);//设置开始动画颜色


	behaviors.emplace_back(new UI_Logo(this));
	//behaviors.emplace_back(new snake(this));


	//snake

}