//INCOMPLETE

#include "cell.h"

Cell::Cell(): x(-1), y(-1), symbol(' '), isEnemyValid(false), isPlayerValid(false), obj(nullptr) {
	
}
Cell::Cell(int x, int y, char sym): x(x), y(y), symbol(sym), obj(nullptr) {
	if(sym == '.') {
		isEnemyValid = true;
		isPlayerValid = true;
	}
	else if(sym == '#' || sym == '+') {
		isPlayerValid = true;
		isEnemyValid = false;
	}
	else {
		isPlayerValid = false;
		isEnemyValid = false;
	}
}
char Cell::getSymbol() {
	return symbol;
}
void Cell::add(GameObject* object) {
	obj = object;
	sym = obj->getSymbol();
}
void Cell::remove() {
	obj = nullptr;
	sym = '.';
}
