#include "Enemy.h"

Enemy::Enemy(int x, int y, char symbol, Floor *grid, int health, int attack, int defense, bool canMove):
    Character(x,y,symbol,grid,health,attack,defense,0.5),
    canMove(canMove)
    {}

std::string Enemy::getRace(){
	return "";
}

bool Enemy::getMerchantHostile(){
	return 0;
}
void Enemy::setMerchantHostile(){}

Human::Human(int x, int y, Floor *grid):
    Enemy(x,y,'H',grid,140,20,20) {}

Dwarf::Dwarf(int x, int y, Floor *grid):
Enemy(x,y,'W',grid,100,20,30) {}

Elf::Elf(int x, int y, Floor *grid):
Enemy(x,y,'E',grid,140,30,10) {}

Orc::Orc(int x, int y, Floor *grid):
Enemy(x,y,'O',grid,180,30,25) {}

Merchant::Merchant(int x, int y, Floor *grid):
Enemy(x,y,'M',grid,30,70,5) {}

Dragon::Dragon(int x, int y, Floor *grid, int hoardx, int hoardy):
Enemy(x,y,'D',grid,150,20,20,false) {}

Halfling::Halfling(int x, int y, Floor *grid):
Enemy(x,y,'L',grid,100,15,20) {}


