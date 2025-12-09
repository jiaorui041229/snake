#include "UI_SnakeText.h"
#include "tools.h"
#include "Input.h"
#include "UI_LevelSelect.h"
#include <iostream>

enum textState
{

	Snake = 0,
	Tips,
	WaitKey,
	Level,
};


textState state;

void UI_SnakeText::Start()
{
	state = textState::Snake;

	for (auto& item : textsnake) {
		item->Print();
	}
}

void UI_SnakeText::Loop(double time) {

	switch (state)
	{
	case Snake: {
		timer += time;
		if (timer >= currentTime) {
			timer = 0;

			for (auto& item : textsnake) {
				item->Clear();
			}

			// 文字移动一格
			for (auto& item : textsnake) {

				int x = item->AddX(1);
				item->Print();
				if (x > 32) {
					state = textState::Tips;
				}
			}
		}
		break;
	}

	case Tips: {

		/*设置关标位置，并输出提示语，等待任意键输入结束*/
		SetCursorPosition(13, 26);
		std::cout << "Press any key to start... ";
		SetCursorPosition(13, 27);
		std::cout << "按任意键继续... ";
	
		
		state = textState::WaitKey;
	}
	case  WaitKey:
	{
		if (Input::keyCodeDown != 0) {
			state = textState::Level;
			currentScene->addBehavior(new UI_LevelSelect(currentScene));
		}
	}
	break;
	default:
		break;
	}



}

void UI_SnakeText::Destroy()
{
	for (auto& item : textsnake) {
		item->Clear();
		delete item;
	}
	textsnake.clear();
}
