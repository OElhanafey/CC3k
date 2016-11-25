#include "gold.h"

Gold::Gold(int value): value(value), symbol('G') {
	if(value == 6) {
		pickedUp = false;
	}
	else {
		pickedUp = true;
	}
}
void Gold::setGold(int gold) {
	value = gold;
}
int Gold::getGold() {
	return value;
}
void Gold::setPickedUp(bool value) {
	pickedUp = value;
}
bool Gold::getPickedUp() {
	return pickedUp;
}

