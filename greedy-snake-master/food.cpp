#include "food.h"
#include "tools.h"


#include <cstdlib>
#include <iostream>

void food::Start()
{
	RandowPosition();

	if (Timerlimit()) {
		DrawFood_Timerlimit();
	}
	else {
		DrawFood();
	}
}

bool isBloc = false;
bool isCreate = false;

void food::Loop(double time)
{
	if (gameControll::state != gameControll::gameState::Run)
		return;

	if (isCreate) {
		isCreate = false;
		Start();
	}

	if (isTimerlimit) {
		timer += time;
		if (timer >= currentTime) {
			timer = 0;

			// 定位进度条最后的位置
			SetCursorPosition(26, 0);
			SetColor(11);

			for (int i = 42; i >= progress_bar; --i)//进度条缩短
				std::cout << "\b \b";

			if (progress_bar <= 0) {

				SetCursorPosition(x, y);
				std::cout << "  ";

				Start();
				return;
			}
			progress_bar--;

			if (isBloc) {

				draw("★");
			}
			else {
				draw("■");
			}
			isBloc = !isBloc;

			SetCursorPosition(0, 31);
		}
	}
}

bool food::OnTrigger(const int _x, const int _y)
{
	if (_x == x && _y == y) {
		isCreate = true;

		if (isTimerlimit) {
			SetCursorPosition(26, 0);
			SetColor(11);
			for (int i = 42; i >= progress_bar; --i)//清空进度条
				std::cout << "\b \b";

			gameControll::score += 20 * gameControll::model;
		}
		else {
			gameControll::score += 10 * gameControll::model;
		}
		return true;
	}
	return false;
}

void food::draw(string content) {
	SetCursorPosition(x, y);
	SetColor(13);
	std::cout << content;
}

void food::DrawFood()
{
	draw("★");
}

void food::DrawFood_Timerlimit()
{
	SetCursorPosition(5, 0);
	SetColor(11);
	std::cout << "------------------------------------------";//进度条
	progress_bar = 42;
	draw("★");
	isBloc = true;
}

bool food::Timerlimit()
{
	isTimerlimit = count % 5 == 0;
	return isTimerlimit;
}

/// <summary>
/// 随机位置
/// </summary>
void food::RandowPosition()
{
	while (true) {

		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;

		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;

		if (_snake->Contain(tmp_x, tmp_y)) {
			continue;
		}

		x = tmp_x;
		y = tmp_y;
		break;
	}

	count++;
}
