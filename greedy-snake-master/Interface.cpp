#include "Interface.h"
#include "tools.h"
#include "Interface_Menu.h"
#include "snake.h"
#include "gameControll.h"
#include "food.h"

enum  enum_wallDir
{
	Up,
	Down,
	Left,
	Right,
	Finshe,
};


int width = 30;
int height = 30;
int _x, _y;

enum_wallDir wallDir;

Interface_Menu* menu;
snake* snakeBody;

void Interface::AddPoint() {
	Point* p = new Point(_x, _y);
	p->Print();

	SetCursorPosition(0, 31);
	Interface::wall.emplace_back(p);
}

void Interface::Start()
{
	system("cls");//清屏
	SetColor(3);

	_x = 1;
	_y = 1;
	wallDir = enum_wallDir::Right;

	AddPoint();
}


void Interface::Loop(double time)
{
	timer += time;
	if (timer >= currentTime) {
		timer = 0;

		if (wallDir == enum_wallDir::Finshe) {
			return;
		}

		switch (wallDir)
		{
		case Right:
		{_x++;

		if (_x >= width) {
			_x = width;
			wallDir = enum_wallDir::Down;
		}

		break;
		}
		case Down:
		{
			_y++;
			if (_y >= height) {
				_y = height;

				wallDir = enum_wallDir::Left;
			}

			break;
		}
		case Left:
		{
			_x--;
			if (_x <= 1) {
				_x = 1;
				wallDir = enum_wallDir::Up;
			}
			break;
		}
		case Up:
		{
			_y--;
			if (_y <= 1) {
				wallDir = enum_wallDir::Finshe;

				gameControll::state = gameControll::gameState::Run;

				// 菜单
				menu = new Interface_Menu(currentScene);
				// 食物
				food* _food = new food(currentScene);
				// 蛇
				snakeBody = new snake(currentScene, _food);

				_food->_snake = snakeBody;
		

				currentScene->addBehavior(snakeBody);
				currentScene->addBehavior(_food);
				currentScene->addBehavior(menu);
			}
			break;
		}

		default:
			return;
		}

		AddPoint();
	}

}

void Interface::Destroy()
{

	for (auto& item : wall) {
		item->Clear();

		delete item;
	}

	wall.clear();
}

bool Interface::HitWall(Point* p)
{
	for (auto& item : wall) {

		if (item->X() == p->X() && item->Y() == p->Y()) {
			return true;
		}

	}
	return false;
}
