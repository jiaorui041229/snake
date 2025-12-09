#include "UI_Logo.h"
#include "gameInit.h"
#include "UI_SnakeText.h"

#include <iostream>



void UI_Logo::addPoint() {

	logo_Point* p = new	 logo_Point(start_x, start_y, logoHeight, currentScene);
	lsPoints.emplace_back(p);
}

void UI_Logo::Destroy() {

	for (auto& item : lsPoints)
	{
		item->Destroy();
		delete item;
	}


	lsPoints.clear();
}

/// <summary>
/// ÏÂÒ»²½
/// </summary>
void UI_Logo::NextStep() {

	if (lsPoints.size() > 0) {
		int beginx = lsPoints.back()->GetPoint()->GetX();
		if (beginx >= gameInit::Width) {
			currentScene->removeBehavior(this);
			currentScene->addBehavior(new UI_SnakeText(currentScene));
			return;
		}
	}

	if (lsPoints.size() <= maxPointCount)
		addPoint();
	for (auto& item : lsPoints) {
		item->Move();
	}
}

void UI_Logo::Loop(double time) {
	timer += time;
	if (timer >= currentTime) {
		timer = 0;
		NextStep();
	}
}

void UI_Logo::Start() {
	start_y = gameInit::Height / 2 - logoHeight;
	start_x = 0;
}