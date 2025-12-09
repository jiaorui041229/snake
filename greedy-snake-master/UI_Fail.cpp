#include "UI_Fail.h"
#include "tools.h"
#include "gameControll.h"
#include "Input.h"
#include "sceneControll.h"
#include "UI_LevelSelect.h"

void UI_Fail::Start()
{
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

	SetCursorPosition(9, 9);
	std::cout << " ┃               Game Over !!!              ┃";
	SetCursorPosition(9, 10);
	std::cout << " ┃                                          ┃";
	;
	SetCursorPosition(9, 11);
	std::cout << " ┃              很遗憾！你挂了              ┃";

	SetCursorPosition(9, 12);
	std::cout << " ┃                                          ┃";

	SetCursorPosition(9, 13);
	std::cout << " ┃             你的分数为：                 ┃";
	SetCursorPosition(24, 13);
	std::cout << gameControll::score;

	SetCursorPosition(9, 14);
	std::cout << " ┃                                          ┃";

	SetCursorPosition(9, 15);
	std::cout << " ┃   是否再来一局？                         ┃";

	SetCursorPosition(9, 16);
	std::cout << " ┃                                          ┃";

	SetCursorPosition(9, 17);
	std::cout << " ┃                                          ┃";

	SetCursorPosition(9, 18);
	std::cout << " ┃    嗯，好的        不了，还是学习有意思  ┃";

	SetCursorPosition(9, 19);
	std::cout << " ┃                                          ┃";

	SetCursorPosition(9, 20);
	std::cout << " ┃                                          ┃";

	SetCursorPosition(10, 21);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";


	DispalyOption();
}

/// <summary>
/// 显示选项
/// </summary>
void UI_Fail::DispalyOption()
{

	displayText(12, 18, "嗯，好的", selectId == 0);
	displayText(20, 18, "不了，还是学习有意思", selectId == 1);
	SetCursorPosition(0, 31);
}

void UI_Fail::Loop(double time)
{
	if (Input::keyCodeDown == Input::enum_KeyCode::Arrow_Left) {

		if (selectId > 0) {
			selectId--;
			DispalyOption();
		}
	}
	else if (Input::keyCodeDown == Input::enum_KeyCode::Arrow_Right) {
		if (selectId < 1) {
			selectId++;
			DispalyOption();
		}
	}
	else if (Input::keyCodeDown == Input::enum_KeyCode::Enter) {

		if (selectId == 0) {
			currentScene->clear();
			currentScene->addBehavior(new UI_LevelSelect(currentScene));
		}
		else {
		

			sceneControll::removeView(currentScene);
		}

	}
}

void UI_Fail::Destroy()
{
}

