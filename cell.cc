//INCOMPLETE:

#include "cell.h"
#include "gold.h"
#include <memory>
Cell::Cell(): x(-1), y(-1), symbol(' '), isPlayerValid(false), isEnemyValid(false), dragonHoard(false), obj(nullptr) {}

Cell::Cell(int x, int y, char sym, GameObject& player): x(x), y(y), symbol(sym), origSym(sym), dragonHoard(false), obj(nullptr), isPlayerValid(false), isEnemyValid(false) {
   if(sym == '.') {
	isEnemyValid = true;
	isPlayerValid = true;
   }
   else if(sym == '#' || sym == '+') {
	isPlayerValid = true;
	isEnemyValid = false;
   }
   else if(sym == 'H') {
	symbol = 'H';
	origSym = '.';
	//obj = new Human();
   }
   else if(sym == 'W') {
        symbol = 'W';
        origSym = '.';
        //obj = new Dwarf();
   }
   else if(sym == 'E') {
        symbol = 'E';
        origSym = '.';
        //obj = new Elf();
   }
   else if(sym == 'O') {
        symbol = 'O';
        origSym = '.';
        //obj = new Orc();
   }
   else if(sym == 'M') {
        symbol = 'M';
        origSym = ',';
        //obj = new Merchant();
   }
   else if(sym == 'D') {
        symbol = 'D';
        origSym = '.';
        //obj = new Dragon();
   }
   else if(sym == 'L') {
        symbol = 'L';
        origSym = '.';
        //obj = new Halfling();
   }

   else if(sym == '0') {
	symbol = 'P';
	origSym = '.';
	//obj = new RestoreHp();
   }
   else if(sym == '1') {
        symbol = 'P';
        origSym = '.';
	//obj = new BoostAtk();
   }
   else if(sym == '2') {
        symbol = 'P';
        origSym = '.';
	//obj = new BoostDef();
   }
   else if(sym == '3') {
        symbol = 'P';
        origSym = '.';
	//obj = new PoisonHp();
   }
   else if(sym == '4') {
        symbol = 'P';
        origSym = '.';
	//obj = new WoundAtk();
   }
   else if(sym == '5') {
        symbol = 'P';
        origSym = '.';
	//obj = new WoundDef();
   }
   else if(sym == '6') {
        symbol = 'G';
        origSym = '.';
	//obj = new Gold(x,y,2);
   }
   else if(sym == '7') {
        symbol = 'G';
        origSym = '.';
	//obj = new Gold(x,y,1);
   }
   else if(sym == '8') {
        symbol = 'G';
        origSym = '.';
	//obj = new Gold(x,y,4);
   }
   else if(sym == '9') {
        symbol = 'G';
        origSym = '.';
	//obj = new Gold(x,y,6);
   }
   else if(sym == '@') {
	    origSym = '.';
      obj = *player;
   }
   else if(sym == '\\') {
	symbol = '\\';
	origSym = '\\';
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
      GameObject *p = new Gold(getx(), gety(), 6);
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
