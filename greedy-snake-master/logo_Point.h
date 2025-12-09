#pragma once
#include "behavior.h"
#include <string>

class logo_Point :
	public behavior
{

public:
	logo_Point(const int _x, const int _y, const int heihgt, scene* _scene) :behavior(_scene) {
		isDown = true;
		logoHeight = heihgt;
		x = _x;
		y = _y;

		Awake();
	}
	void Move();
	virtual void Awake();
	virtual void Destroy();

	int x, y;
	int logoHeight, offsetH, offsetW;
	bool isDown;
};

