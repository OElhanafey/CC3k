//INCOMPLETE:

#include "cell.h"

Cell::Cell(): x(-1), y(-1), symbol(' '), isPlayerValid(false), isEnemyValid(false), dragonHoard(false), obj(nullptr) {}
Cell::Cell(int x, int y, char sym): x(x), y(y), symbol(sym), origSym(sym), dragonHoard(false), obj(nullptr) {
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

int Cell::getx() { return x; }
int Cell:: gety() { return y; }

char Cell::getOrigSym() { return origSym; }

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
   if(dragonHoard == true){
      GameObject *p = new Gold(getx(), gety(), obj->getGrid(), 6);
      obj=p;
      symbol = obj->getSymbol();
      isEnemyValid = false;
   }
   else {
      obj = nullptr;
      symbol = getOrigSym();
      isEnemyValid = true;

      if(symbol == '+' || symbol == '#') {
	 isEnemyValid = false;
      }
   }
   isPlayerValid = true;
}

bool Cell::getPlayerValid() {
   return isPlayerValid;
}

bool Cell::getEnemyValid() {
   return isEnemyValid;
}

