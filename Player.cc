#include "Player.h"

// Figure out the default potionEffect.
Player::Player(int x, int y, int health, int attack, int defense, std::string race, int potionEffect):
	Character(x,y,'@',health, attack, defense),
	merchantHostile(false),
	enemyMovable(true),
	level(0),
	maxhp(health),
	origAtk(attack),
	origDef(defense),
        message(""),
	race(race),
	potionEffect(potionEffect)
{}

Player::~Player() {}

std::string Player::getRace(){
	return race;
}

std::string Player::getMessage(){
    return message;
}

void Player::setMessage(std::string exp){
    message = exp;
}


void Player::setLevel(int floor) {
	level = floor;
}

int Player::getLevel() {
	return level;
}

bool Player::getEnemyMovable() { return enemyMovable; }
void Player::setEnemyMovable() {
    if (enemyMovable) enemyMovable = false;
    else enemyMovable = true;
}

// Calls action on all the enemies on the floor.
void Player::callAction(Floor *g){
    std::vector <GameObject*> myenemies;
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 79; j++){
        GameObject *e = g->getObj(i,j);    
	char s = g->getSymbol(i,j);
            if(s == 'H' || s == 'L' || s == 'W' ||
               s == 'O' || s == 'E' || s == 'M'){
                myenemies.emplace_back(e);
            }
        }
    }
    int size = myenemies.size();
    for(int i = 0; i < size; i++){
	       myenemies[i]->action(*this, g);
    }
}

// Checks all the potions near a player
std::vector<std::pair<std::string,int>> Player::potionsNearby(Floor *g) {
    int e_x = getx();
    int e_y = gety();
    
    std::vector<std::pair<std::string,int>> pTypes;
    
    for(int i = 0; i < 8; ++i) {
        int rX = e_x + radius[i].first;
        int rY = e_y + radius[i].second;
        
        if(g->getSymbol(rX, rY) == 'P'){
            GameObject *potion = g->getObj(rX,rY);
            bool emplaced = false;
            int size = pTypes.size();
            for (int j = 0; j < size; ++j){
                if (potion->potionType() == pTypes[j].first) {
                    pTypes[j].second += 1;
                    emplaced = true;
                }
            }
            if (!emplaced) {
                pTypes.emplace_back(std::make_pair(potion->potionType(), 1));
            }
        }
    }
    return pTypes;
}


int Player::getMaxHp() {
	return maxhp;
}

int Player::getOrigAtk() {
	return origAtk;
}

int Player::getOrigDef() {
	return origDef;
}

int Player::getPotionEffect(){
    return potionEffect;
}

bool Player::getMerchantHostile(){
	return merchantHostile;
}

void Player::setMerchantHostile(){
	merchantHostile = true;
}

Shade::Shade(int x, int y): Player(x,y,125,25,25,"Shade"){}

Drow::Drow(int x, int y): Player(x,y,150,25,15,"Drow",1.5){}

Vampire::Vampire(int x, int y): Player(x,y,50,25,25,"Vampire"){}

Troll::Troll(int x, int y): Player(x,y,120,25,15,"Troll"){}

Goblin::Goblin(int x, int y): Player(x,y,110,15,20,"Goblin"){}
