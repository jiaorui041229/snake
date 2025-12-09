
#include "UI_LevelSelect.h"
#include "tools.h"
#include "Input.h"
#include "Input.h"
#include "Interface.h"
#include "gameControll.h"

#include <string>
#include <iostream>



void DrawTitle() {

	displayText(27, 22, "简单模式", gameControll::model == gameControll::gameModel::Jd);
	displayText(27, 24, "普通模式", gameControll::model == gameControll::gameModel::Pt);
	displayText(27, 26, "困难模式", gameControll::model == gameControll::gameModel::Kn);
	displayText(27, 28, "炼狱模式", gameControll::model == gameControll::gameModel::Ly);

	SetCursorPosition(0, 31);
}
void UI_LevelSelect::Start()
{
	//gameControll::model = gameControll::gameModel::Jd;
	gameControll::score = 0;

	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "请选择游戏难度：";
	SetCursorPosition(6, 22);
	std::cout << "(上下键选择,回车确认)";

	DrawTitle();
}



void UI_LevelSelect::Loop(double time)
{

	if (Input::keyCodeDown == Input::enum_KeyCode::Arrow_Down) {

		int m = gameControll::model;
		m++;

		if (m > gameControll::gameModel::Ly) {
			gameControll::model = gameControll::gameModel::Ly;
		}
		else {
			gameControll::model = gameControll::gameModel(m);
		}
		DrawTitle();
	}
	else if (Input::keyCodeDown == Input::enum_KeyCode::Arrow_Up) {

		int m = gameControll::model;
		m--;

		if (m < gameControll::gameModel::Jd) {
			gameControll::model = gameControll::gameModel::Jd;
		}
		else {
			gameControll::model = gameControll::gameModel(m);
		}
		DrawTitle();
	}
	else if (Input::keyCodeDown == Input::enum_KeyCode::Enter) {

		if (gameControll::model == gameControll::gameModel::None)
			return;
		// 开始游戏
		// 清空现有场景
		// 开始加载游戏场景
		currentScene->clear();
		currentScene->addBehavior(new Interface(currentScene));
	}
}

