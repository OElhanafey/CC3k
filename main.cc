#include <iostream>
#include "floor.h"
#include "GameObject.h"
#include "Character.h"
#include "potion.h"
#include "cell.h"
#include "Player.h"
#include "Enemy.h"

int main() {
	Floor *theFloor = new Floor();
//	theFloor.print()
	GameObject *obj = new Vampire(3,8);
	GameObject *e = new Human(4,9);
	GameObject *pot = new RestoreHp(4,8);
	if (obj->getSymbol() != 'P' || obj->getSymbol() != 'G' ) {
	   //Character *c = dynamic_cast<Character *> (obj);
	std::cout << obj->getHP() /*<< " "<< e->getHP()*/ << std::endl;
	}
	theFloor->objectAdd(3,8,obj);
	theFloor->objectAdd(4,9,e);
	theFloor->print();
	obj->shift("sw",theFloor);
//	e->beStruckBy(*obj, theFloor);
//	e->beStruckBy(*obj, theFloor);

	pot->usePotion(*obj);
	std::cout << obj->getHP() /*<< " "<< e->getHP() */<< std::endl;
	//theFloor->objectRemove(theFloor->getObj(obj->getx(), obj->gety())->getx(), theFloor->getObj(obj->getx(), obj->gety())->gety());
	//obj->shift("so");
	//theFloor->objectAdd(obj->getx(), obj->gety(), obj);
	theFloor->print();

	e->action(*obj,theFloor);
	theFloor->print();
//	theFloor.setCell(1, 2, '@');
//	theFloor.print();
//	GameObject *obj = new Character(1,1,'@', 125,25,25,0);
//	theFloor.objectAdd(1,1,obj);
//	theFloor.print();
	delete e;
	delete obj;	
}
