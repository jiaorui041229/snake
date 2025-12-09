
// 每一个游戏物体都是由一个点 绘制而成得
// 

#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "IView.h"
#include "scene.h"
#include "point.h"
#include <list>

class scene;

class behavior :
	public IView
{

public:
	behavior(scene* _scene) { currentScene = _scene; }

	virtual void Start();
	virtual void Loop(double time);
	virtual void Destroy();
	Point* GetPoint() {
		return point;
	}


protected:

	virtual void Print();
	virtual void Clear();

	scene* currentScene;
	Point* point;



};
#endif // !BEHAVIOR_H
