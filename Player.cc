#include "Player.h"

// Figure out the default potionEffect.
Player::Player(int x, int y, Floor *grid, int health, int attack, int defense, std::string race, int potionEffect):
	Character(x,y,'@', grid, health, attack, defense, 1),
	merchantHostile(false),
	level(1),
	maxhp(health),
	origAtk(attack),
	origDef(defense),
	race(race),
	potionEffect(potionEffect)
{}

Player::~Player() {}

std::string Player::getRace(){
	return race;
}
/*
int Player::getMaxHp() {
	return maxhp;
}
*/
bool Player::getMerchantHostile(){
	return merchantHostile;
}

void Player::setMerchantHostile(){
	merchantHostile = true;
}

Shade::Shade(int x, int y, Floor *grid): Player(x,y,grid,125,25,25,"Shade"){}

Drow::Drow(int x, int y, Floor *grid): Player(x,y,grid,150,25,15,"Drow",1.5){}

Vampire::Vampire(int x, int y, Floor *grid): Player(x,y,grid,50,25,25,"Vampire"){}

Troll::Troll(int x, int y, Floor *grid): Player(x,y,grid,120,25,15,"Troll"){}

Goblin::Goblin(int x, int y, Floor *grid): Player(x,y,grid,110,15,20,"Goblin"){}
