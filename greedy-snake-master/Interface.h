#pragma once
#include "behavior.h"
#include "point.h"
#include <list>


class Interface :
	public behavior
{
public:
	Interface(scene* _scene) : behavior(_scene) {

		currentTime = 1.0 / 120.0;
		timer = 0;
	}

	virtual void Start();
	virtual void Loop(double time);
	virtual void Destroy();

	virtual bool HitWall(Point* p);

	

protected:
	void AddPoint();
	double currentTime, timer;
	std::list<Point*> wall;
	


};

