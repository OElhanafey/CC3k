#include "gold.h"

Gold::Gold(int value): value(value), symbol('G') {
	if(value == 6) {
		pickable = false;
	}
	else {
		pickable = true;
	}
}

Gold::~Gold(){}

void Gold::setGold(int gold) {
	value = gold;
}
int Gold::getGold() {
	return value;
}
void Gold::setPickable(bool value) {
	pickable = value;
}
bool Gold::getPickable() {
	return pickable;
}
