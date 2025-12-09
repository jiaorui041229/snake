#include "Interface_Menu.h"
#include "tools.h"
#include "gameControll.h"
#include "Input.h"
#include "sceneControll.h"
#include "UI_LevelSelect.h"

#include <iostream>


void Interface_Menu::Start()
{
	SetColor(3);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "贪吃蛇";
	SetCursorPosition(31, 4);
	std::cout << "难度：";
	SetCursorPosition(36, 5);

	switch (gameControll::model)
	{
	case   gameControll::gameModel::Jd:
		std::cout << "简单模式";
		break;
	case   gameControll::gameModel::Pt:
		std::cout << "普通模式";
		break;
	case   gameControll::gameModel::Kn:
		std::cout << "困难模式";
		break;
	case   gameControll::gameModel::Ly:
		std::cout << "炼狱模式";
		break;
	}

	SetCursorPosition(31, 7);
	std::cout << "得分：";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << " 方向键移动";
	SetCursorPosition(33, 15);
	std::cout << " ESC键暂停";
}


/// <summary>
/// 更新分数
/// </summary>
void Interface_Menu::UpdateScore()
{
	SetCursorPosition(37, 8);

	SetColor(11);
	int bit = 0;
	int tmp = gameControll::score;
	while (tmp != 0)
	{
		++bit;
		tmp /= 10;
	}
	for (int i = 0; i < (6 - bit); ++i)
	{
		std::cout << " ";
	}
	std::cout << gameControll::score;
}

int select = 0;

void Interface_Menu::DrawTitle() {

	displayText(34, 21, "继续游戏", select == 0);
	displayText(34, 23, "重新开始", select == 1);
	displayText(34, 25, "退出游戏", select == 2);

	SetCursorPosition(0, 31);
}

void Interface_Menu::ClearTitle() {
	SetCursorPosition(32, 19);
	std::cout << "                  ";
	SetCursorPosition(32, 21);
	std::cout << "                  ";
	SetCursorPosition(32, 23);
	std::cout << "                  ";
	SetCursorPosition(32, 25);
	std::cout << "                  ";
}



void Interface_Menu::Loop(double time)
{
	if (gameControll::state == gameControll::gameState::Pause) {


		if (Input::keyCodeDown == Input::enum_KeyCode::Arrow_Up) {

			if (select > 0) {
				select--;
				DrawTitle();
			}
		}
		else if (Input::keyCodeDown == Input::enum_KeyCode::Arrow_Down) {
			if (select < 2) {
				select++;
				DrawTitle();
			}
		}
		else if (Input::keyCodeDown == Input::enum_KeyCode::Enter) {
			ClearTitle();
			switch (select)
			{
			case 0:
				gameControll::state = gameControll::gameState::Run;
				break;
			case 1:

				currentScene->clear();
				currentScene->addBehavior(new UI_LevelSelect(currentScene));
				break;
			case 2:

				sceneControll::removeView(currentScene);
				break;
			default:
				break;
			}

		}

	}

}


void Interface_Menu::PauseMenu()
{
	/*绘制菜单*/
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "菜单：";

	DrawTitle();
}

void Interface_Menu::Destroy()
{
}


