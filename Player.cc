#include "Player.h"

// Figure out the default potionEffect.
Player::Player(int x, int y, Floor *grid, int health, int attack, int defense, std::string race, int potionEffect):
    Character(x,y,'@', grid, health, attack, defense, 1),
    level(1),
    maxhp(health),
    maxatk(attack),
    maxdef(defense),
    race(race),
    potionEffect(potionEffect)
    {}

Player::~Player() {}

// If you are not using the smart pointer, you need to delete the enemy if the hp drops to 0.
// Print Action
// Include the gold, once the hp is 0 for npc.
// Notify enemies to make a move
void Player::strike(Npc &n){
    int damage = ((100/(100+n.getDef()))*(this->getAtk()));
    if((n.getHP() - damage) < 0) {
        n.setHP(0);
    }
    else {
        n.setHP(n.getHP() - damage);
    }
}

void Player::beStruckBy(Npc &n){
    n.strike(*this);
}

Shade::Shade(int x, int y, Floor *grid): Player(x,y,grid,125,25,25,"Shade"){}

Drow::Drow(int x, int y, Floor *grid): Player(x,y,grid,150,25,15,"Drow",1.5){}

Vampire::Vampire(int x, int y, Floor *grid): Player(x,y,grid,50,25,25,"Vampire"){}

Troll::Troll(int x, int y, Floor *grid): Player(x,y,grid,120,25,15,"Troll"){}

Goblin::Goblin(int x, int y, Floor *grid): Player(x,y,grid,110,15,20,"Goblin"){}

