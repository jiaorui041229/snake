#pragma once

#ifndef FOOD_H
#define FOOD_H



#include "behavior.h"
#include "snake.h"
#include "gameControll.h"

#include <string>

class snake;



class food :
	public behavior
{
public:
	food(scene* _scene) :behavior(_scene) {
		//_snake = (snake*)_scene->find(typeid(snake).name());
		count = 0;
		progress_bar = 42;

		currentTime = 1.0 / (5 + ((int)gameControll::model) * 5);
	}

	virtual void Start();
	virtual void Loop(double time);
	bool OnTrigger(const int x, const int y);
	snake* _snake;


protected:

	void DrawFood();
	void DrawFood_Timerlimit();
	void draw(string content);


	bool Timerlimit();
	bool isTimerlimit;

	void RandowPosition();
	int x, y, count, progress_bar;

	double currentTime, timer;

};

#endif // !FOOD_H