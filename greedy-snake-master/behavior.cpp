#include "behavior.h"



void behavior::Start() {


}

void behavior::Loop(double time) {


}

void behavior::Destroy() {

}

void behavior::Print() {

	if (point)
		point->Print();

}

void behavior::Clear() {
	if (point)
		point->Clear();
}