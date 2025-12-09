#pragma once

#ifndef SNAKE_H
#define SNAKE_H


#include "behavior.h"
#include "point.h"
#include "gameControll.h"
#include "Interface.h"
#include "food.h"
#include "Interface_Menu.h"

#include <vector>


class food;
class snake :
	public behavior
{

public:
	snake(scene* _scene,food* food) :behavior(_scene) {

		_food = food;
		currentTime = 1.0 / (5 + ((int)gameControll::model) * 5);
		timer = 0;
		wall = (Interface*)_scene->find(typeid(Interface).name());
	}

	virtual void Start();
	virtual void Step(double time);
	virtual void Loop(double time);
	virtual void Destroy();
	virtual bool Contain(const int x, const int y) {

		for (auto& item : body)
		{
			if (item->X() == x && item->Y() == y)
				return true;
		}
		return false;
	}


protected:
	void addBody(const int x, const int y);
	bool HitSlef();// ×²×Ô¼º
	Interface_Menu* menu;
	double currentTime, timer;
	std::vector<Point*> body;
	Interface* wall;
	food* _food;


};

#endif // !SNAKE_H

