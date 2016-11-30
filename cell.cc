//INCOMPLETE

#include "cell.h"

Cell::Cell(): x(-1), y(-1), symbol(' '), isPlayerValid(false), isEnemyValid(false), dragonHoard(false), obj(nullptr) {}
Cell::Cell(int x, int y, char sym): x(x), y(y), symbol(sym), origSym(sym), dragonHoard(dragonHoard), obj(nullptr) {
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

bool Cell::getDragonHoard(){
    return dragonHoard;
}

void Cell::setDragonHoard(bool status){
    dragonHoard = status;
}

GameObject* Cell::getObject() {
   	return obj;
}

void Cell::add(GameObject* object) {
    if(dragonHoard == true){
        delete obj;
    }
    obj = object;
    symbol = obj->getSymbol();
    isEnemyValid = false;
    isPlayerValid = false;
    if((symbol == 'G')||(symbol == '\\')) {
        isPlayerValid = true;
    }
}

void Cell::remove() {
    obj = nullptr;
    symbol = origSym;
    if(dragonHoard == true){
        GameObject *p = new Gold();
        obj=p; //Fix the gold constructor.
    }
    isEnemyValid = true;
    if(symbol == '+' || symbol == '#') {
	isEnemyValid = false;
    }
    isPlayerValid = true;
}

bool Cell::getPlayerValid() {
    return isPlayerValid;
}

bool Cell::getEnemyValid() {
    return isEnemyValid;
}
