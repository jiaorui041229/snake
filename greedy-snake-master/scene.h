#pragma once

#ifndef  SCENE_H
#define SCENE_H

#include <list>
#include "IView.h"
#include "sceneControll.h"
#include "behavior.h"

class behavior;
class scene :
	public IView
{

public:
	
	scene() { runState = sceneControll::Enum_RunState::None; }

	virtual void Start();
	virtual void Loop(double time);
	virtual void Destroy();
	virtual void Init();
	void addBehavior(behavior* be);
	void removeBehavior(behavior* be);

	behavior* find(const char* p);
	void clear();

protected:
	std::list<behavior*> behaviors;
	std::list<behavior*> delBehaviors;
	std::list<behavior*> addBehaviors;
	sceneControll::Enum_RunState runState;

};
#endif // ! SCENE_H

