#pragma once
#include "behavior.h"
#include "point.h"
#include <list>


class UI_SnakeText :
	public behavior
{
public:
	UI_SnakeText(scene* _scene) :behavior(_scene) {

		textsnake.emplace_back(new Point(-26, 14));//S
		textsnake.emplace_back(new Point(-25, 14));
		textsnake.emplace_back(new Point(-27, 15));
		textsnake.emplace_back(new Point(-26, 16));
		textsnake.emplace_back(new Point(-25, 17));
		textsnake.emplace_back(new Point(-27, 18));
		textsnake.emplace_back(new Point(-26, 18));

		textsnake.emplace_back(new Point(-23, 14));//N
		textsnake.emplace_back(new Point(-23, 15));
		textsnake.emplace_back(new Point(-23, 16));
		textsnake.emplace_back(new Point(-23, 17));
		textsnake.emplace_back(new Point(-23, 18));
		textsnake.emplace_back(new Point(-22, 15));
		textsnake.emplace_back(new Point(-21, 16));
		textsnake.emplace_back(new Point(-20, 17));
		textsnake.emplace_back(new Point(-19, 14));
		textsnake.emplace_back(new Point(-19, 15));
		textsnake.emplace_back(new Point(-19, 16));
		textsnake.emplace_back(new Point(-19, 17));
		textsnake.emplace_back(new Point(-19, 18));

		textsnake.emplace_back(new Point(-17, 18));//A
		textsnake.emplace_back(new Point(-16, 17));
		textsnake.emplace_back(new Point(-15, 16));
		textsnake.emplace_back(new Point(-14, 15));
		textsnake.emplace_back(new Point(-14, 16));
		textsnake.emplace_back(new Point(-13, 14));
		textsnake.emplace_back(new Point(-13, 16));
		textsnake.emplace_back(new Point(-12, 15));
		textsnake.emplace_back(new Point(-12, 16));
		textsnake.emplace_back(new Point(-11, 16));
		textsnake.emplace_back(new Point(-10, 17));
		textsnake.emplace_back(new Point(-9, 18));

		textsnake.emplace_back(new Point(-7, 14));//K
		textsnake.emplace_back(new Point(-7, 15));
		textsnake.emplace_back(new Point(-7, 16));
		textsnake.emplace_back(new Point(-7, 17));
		textsnake.emplace_back(new Point(-7, 18));
		textsnake.emplace_back(new Point(-6, 16));
		textsnake.emplace_back(new Point(-5, 15));
		textsnake.emplace_back(new Point(-5, 17));
		textsnake.emplace_back(new Point(-4, 14));
		textsnake.emplace_back(new Point(-4, 18));

		textsnake.emplace_back(new Point(-2, 14));//E
		textsnake.emplace_back(new Point(-2, 15));
		textsnake.emplace_back(new Point(-2, 16));
		textsnake.emplace_back(new Point(-2, 17));
		textsnake.emplace_back(new Point(-2, 18));
		textsnake.emplace_back(new Point(-1, 14));
		textsnake.emplace_back(new Point(-1, 16));
		textsnake.emplace_back(new Point(-1, 18));
		textsnake.emplace_back(new Point(0, 14));
		textsnake.emplace_back(new Point(0, 16));
		textsnake.emplace_back(new Point(0, 18));

		currentTime = 1 / 30.0;
		timer = 0;
	}

	virtual void Start();
	virtual void Loop(double time);
	virtual void Destroy();

protected:
	double currentTime, timer;
	std::list<Point*> textsnake;
};
//#ifndef BEHAVIOR_H
//#define BEHAVIOR_H
//
//#endif // !BEHAVIOR_H