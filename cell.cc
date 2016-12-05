#include <iostream>
#include "cell.h"
#include "Enemy.h"
#include "gold.h"
#include <memory>
Cell::Cell(): x(-1), y(-1), symbol(' '), isPlayerValid(false), isEnemyValid(false), dragonHoard(false), obj(nullptr) {}

Cell::Cell(int x, int y, char sym, GameObject& player): x(x), y(y), symbol(sym), origSym(sym), isPlayerValid(false), isEnemyValid(false), dragonHoard(false), obj(nullptr) {
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
        GameObject* human = new Human(x,y);
        obj = human;
   }
   else if(sym == 'W') {
        symbol = 'W';
        origSym = '.';
        GameObject* dwarf = new Dwarf(x,y);
        obj = dwarf;
   }
   else if(sym == 'E') {
        symbol = 'E';
        origSym = '.';
       	GameObject* elf = new Elf(x,y);
        obj = elf;
   }
   else if(sym == 'O') {
        symbol = 'O';
        origSym = '.';
        GameObject* orc = new Orc(x,y);
        obj = orc;
  }/*
   else if(sym == 'M') {
        symbol = 'M';
        origSym = ',';
        std::shared_ptr<Merchant> merchant(new Merchant(x,y));
        obj = merchant.get();
   }
   else if(sym == 'D') {
        symbol = 'D';
        origSym = '.';
        std::shared_ptr<Dragon> dragon(new Dragon(x,y));
        obj = dragon.get();
   }
   else if(sym == 'L') {
        symbol = 'L';
        origSym = '.';
        std::shared_ptr<Halfling> halfling(new Halfling(x,y));
        obj = halfling.get();
   }

   else if(sym == '0') {
	       symbol = 'P';
	       origSym = '.';
         std::shared_ptr<RestoreHp> restoreHp(new RestoreHp(x,y));
         obj = restoreHp;
   }
   else if(sym == '1') {
        symbol = 'P';
        origSym = '.';
        std::shared_ptr<RestoreHp> restoreHp(new RestoreHp(x,y));
        obj = restoreHp;
   }
   else if(sym == '2') {
        symbol = 'P';
        origSym = '.';
        std::shared_ptr<BoostDef> boostDef(new BoostDef(x,y));
        obj = boostDef;
   }
   else if(sym == '3') {
        symbol = 'P';
        origSym = '.';
        std::shared_ptr<PoisonHp> poisonHp(new PosionHp(x,y));
        obj = posionHp;
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
	    obj = &player;
   }
   else if(sym == '\\') {
	symbol = '\\';
	origSym = '\\';
   }*/
	else {}
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
