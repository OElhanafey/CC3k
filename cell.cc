//INCOMPLETE

#include "cell.h"

Cell::Cell(int x, int y, char point): x(x), y(y), point(point), item(-1) {
	if(point == '.') {
		valid = true;
	}
	else {
		valid = false;
	}
}
Cell::Cell(int x, int y, int item): x(x), y(y), item(item), valid(false) {
	if(item >= 0 && item <= 5) {
		point = 'P';
	}
	else if(item == 10) {
		point = 'H';
	}
	else if(item == 11) {
		point = 'W';
	}
	else if(item == 12) {
		point = 'L';
	}
	else if(item == 13) {
		point = 'E';
	}
	else if(item == 14) {
		point = 'O';
	}
	else if(item == 15) {
		point = 'M';
	}
	else if(item == 16) {
		point = 'D';
	}
	else {
		point = 'G';
		valid = true;
	}
}
Cell::remove() {
	item = -1;
	point = '.';
}
