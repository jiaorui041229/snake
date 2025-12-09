#pragma once
#include "behavior.h"
#include "logo_Point.h"

class UI_Logo :
	public behavior
{

public:
	UI_Logo(scene* _scene) :behavior(_scene) {
		currentTime = 1 / 30.0;
		timer = 0;
		logoHeight = 4;
		maxPointCount = logoHeight * 4;

	}
	virtual void Start();
	virtual void Loop(double time);
	virtual void Destroy();


private:
	void NextStep();
	void addPoint();

	double currentTime, timer;
	int logoHeight, start_x, start_y;
	int maxPointCount;
	std::list<logo_Point*> lsPoints;
};

