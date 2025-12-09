#include "snake.h"
#include "tools.h"
#include "Input.h"
#include "gameControll.h"

#include "UI_Fail.h"

enum  enum_moveDir
{
	Down = 0,
	Left,
	Right,
	Up,
};

enum_moveDir moveDir;


void snake::addBody(const int x, const int y) {


	Point* newP;

	if (x == 0 || y == 0) {
		Point* p = body.back();
		switch (moveDir)
		{
		case Down:
			newP = new Point(p->X(), p->Y() - 1);
			break;
		case Up:
			newP = new Point(p->X(), p->Y() + 1);
			break;
		case Left:
			newP = new Point(p->X() + 1, p->Y());
			break;
		case Right:
			newP = new Point(p->X() - 1, p->Y());
			break;
		}
	}
	else {
		newP = new Point(x, y);
	}

	body.emplace_back(newP);
	newP->PrintCircular(false);


}
bool snake::HitSlef()
{
	int count = body.size();

	Point* head = body.front();

	for (int i = count - 1; i > 0; i--)
	{
		Point* bodyPoint = body.at(i);

		if (bodyPoint->X() == head->X() && bodyPoint->Y() == head->Y()) {
			return true;
		}
	}

	return false;
}



void snake::Start()
{
	menu = (Interface_Menu*)currentScene->find(typeid(Interface_Menu).name());

	moveDir = enum_moveDir::Down;
	body.emplace_back(new Point(15, 15));
	body.back()->PrintCircular(true);
	addBody(0, 0);
	addBody(0, 0);
}

/// <summary>
/// ²½Êý
/// </summary>
/// <param name="time"></param>
void snake::Step(double time)
{
	int count = body.size();

	Point* lastPoint = body.at(count - 1);
	int temp_x = lastPoint->X();
	int temp_y = lastPoint->Y();

	lastPoint->Clear();

	for (int i = count - 1; i > 0; i--)
	{
		Point* front = body.at(i - 1);
		Point* last = body.at(i);
		last->ChangePosition(front->X(), front->Y());
	}


	Point* p = body.at(0);
	switch (moveDir)
	{
	case Down:
		p->SetY(p->GetY() + 1);
		break;
	case Up:
		p->SetY(p->GetY() - 1);
		break;
	case Left:
		p->SetX(p->GetX() - 1);
		break;
	case Right:
		p->SetX(p->GetX() + 1);
		break;
	}

	body.at(1)->PrintCircular(false);
	p->PrintCircular(true);
	SetCursorPosition(0, 31);

	if (wall->HitWall(p) || HitSlef()) {
		gameControll::state = gameControll::gameState::Fail;
		currentScene->addBehavior(new UI_Fail(currentScene));
	}
	else {

		if (_food->OnTrigger(p->X(), p->Y())) {
			addBody(temp_x, temp_y);

			if (menu)
				menu->UpdateScore();

		}
	}
}


void snake::Loop(double time)
{
	if (gameControll::state != gameControll::gameState::Run)
		return;

	if (Input::keyCodeDown == Input::enum_KeyCode::Arrow_Down) {

		if (moveDir != enum_moveDir::Up) {
			moveDir = enum_moveDir::Down;
		}

	}
	else if (Input::keyCodeDown == Input::enum_KeyCode::Arrow_Up) {
		if (moveDir != enum_moveDir::Down) {
			moveDir = enum_moveDir::Up;
		}
	}
	else if (Input::keyCodeDown == Input::enum_KeyCode::Arrow_Left) {
		if (moveDir != enum_moveDir::Right) {
			moveDir = enum_moveDir::Left;
		}
	}
	else if (Input::keyCodeDown == Input::enum_KeyCode::Arrow_Right) {
		if (moveDir != enum_moveDir::Left) {
			moveDir = enum_moveDir::Right;
		}
	}
	else if (Input::keyCodeDown == Input::enum_KeyCode::ESC) {

		gameControll::state = gameControll::gameState::Pause;



		if (menu) {
			menu->PauseMenu();
		}
	}

	timer += time;
	if (timer >= currentTime) {
		timer = 0;
		Step(time);
	}
}

void snake::Destroy()
{
}
