#include <iostream>
#include "floor.h"
#include "GameObject.h"
#include "Character.h"
#include "cell.h"
#include "Player.h"
#include "Enemy.h"

int main() {
	Floor *theFloor = new Floor();
//	theFloor.print()
	GameObject *obj = new Shade(1,2,theFloor);
	GameObject *e = new Elf(1,3, theFloor);
	if (obj->getSymbol() != 'P' || obj->getSymbol() != 'G' ) {
	   //Character *c = dynamic_cast<Character *> (obj);
	   std::cout << obj->getHP() << std::endl;
	}
	theFloor->objectAdd(1,2,obj);
	theFloor->objectAdd(1,3,e);
	obj->beStruckBy(*e);
	std::cout << e->getHP() << std::endl;
	//theFloor->objectRemove(theFloor->getObj(obj->getx(), obj->gety())->getx(), theFloor->getObj(obj->getx(), obj->gety())->gety());
	//obj->shift("so");
	//theFloor->objectAdd(obj->getx(), obj->gety(), obj);
	theFloor->print();
//	theFloor.setCell(1, 2, '@');
//	theFloor.print();
//	GameObject *obj = new Character(1,1,'@', 125,25,25,0);
//	theFloor.objectAdd(1,1,obj);
//	theFloor.print();	
}
