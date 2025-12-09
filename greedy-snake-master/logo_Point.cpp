#include "logo_Point.h"
#include "point.h"

void logo_Point::Awake() {

	point = new Point(x, y);
	point->Print();
}

void logo_Point::Destroy() {
	delete point;
}

void logo_Point::Move() {

	point->Clear();
	point->ChangePosition(x + offsetW++, y + offsetH);
	point->Print();

	if (isDown) {
		offsetH++;

		if (offsetH >= logoHeight) {
			offsetH = logoHeight;
			isDown = false;
		}
	}
	else {
		offsetH--;
		if (offsetH <= 0) {
			offsetH = 0;
			isDown = true;
		}

	
	}


}