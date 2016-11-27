#include "Player.h"

// Figure out the default potionEffect.
Player::Player(int x, int y, int a, int b, int c): Character(x,y,a,b,c){
    setsym('@');
    floor = 1;
}

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

Shade::Shade(int x, int y): Player(-1,-1,125,25,25){
    race = "Shade";
    maxhp = 125;
    maxatk = 25;
    maxdef = 25;
    potionEffect = 1;
}

Drow::Drow(int x, int y): Player(x,y,150,25,15){
    race = "Drow";
    maxhp = 150;
    maxatk = 25;
    maxdef = 25;
    potionEffect = 1.5;
}

Vampire::Vampire(int x, int y): Player(x,y,50,25,25){
    race = "Vampire";
    maxatk = 25;
    maxdef = 25;
    potionEffect = 1;
}

Troll::Troll(int x, int y): Player(x,y,120,25,15){
    race = "Troll";
    maxhp = 120;
    maxatk = 25;
    maxdef = 15;
}

Goblin::Goblin(int x, int y): Player(x,y,110,15,20){
    race = "Goblin";
    maxhp = 110;
    maxatk = 15;
    maxdef = 20;
}

