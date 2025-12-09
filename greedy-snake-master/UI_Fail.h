#pragma once
#include "behavior.h"
class UI_Fail :
	public behavior
{
public:
	UI_Fail(scene* _scene) :behavior(_scene) {

	}

	virtual void Start();
	virtual void Loop(double time);
	virtual void Destroy();

protected:
	void DispalyOption();
	int selectId = 0;
};

