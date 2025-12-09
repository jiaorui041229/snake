#pragma once
#include "behavior.h"

//”Œœ∑”“≤‡≤Àµ•

class Interface_Menu :
	public behavior
{
public:
	Interface_Menu(scene* _scene) :behavior(_scene) {

	}

	virtual void Start();
	void DrawTitle();
	void ClearTitle();
	void UpdateScore();

	virtual void Loop(double time);
	virtual void Destroy();
	/// <summary>
	/// ‘›Õ£≤Àµ•
	/// </summary>
	void PauseMenu();

};

