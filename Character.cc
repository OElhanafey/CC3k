#include "Character.h"
#include <string>
#include "floor.h"
using namespace std;

// Character Constructor, has the cell's location, the symbol, to represent

Character::Character(int x, int y, char symbol, Floor *grid,int health, int attack, int defense, int accuracy, int gold):
    GameObject(x,y,symbol, grid),
    health(health),
    attack(attack),
    defense(defense),
    accuracy(accuracy),
    gold(gold){}

Character::~Character() {}

int Character::getHP() const {
    return health;
}

int Character::getAtk() const{
    return attack;
}

int Character::getDef() const{
    return defense;
}

int Character::getgold(){
    return gold;
}

void Character::setHP(int hp){
    health = hp;
}

void Character::setAtk(int at){
    attack = at;
}

void Character::setDef(int def){
    defense = def;
}

void Character::setgold(int g){
    gold = g;
}

void Character::shift(std::string dir){
    int new_x,new_y;
    if(dir == "no"){
        new_x = getx()-1;
        new_y = gety();
    }
    else if(dir == "so"){
        new_x = getx()+1;
        new_y = gety();
    }
    else if(dir == "ea"){
        new_x = getx();
        new_y = gety()+1;
    }
    else if(dir == "we"){
        new_x = getx();
        new_y = gety()-1;
    }
    else if(dir == "ne"){
        new_x = getx()-1;
        new_y = gety()+1;
    }
    else if(dir == "nw"){
        new_x = getx()-1;
        new_y = gety()-1;
    }
    else if(dir == "se"){
        new_x = getx()+1;
        new_y = gety()+1;
    }
    else if(dir == "sw"){
        new_x = getx()+1;
        new_y = gety()-1;
    }
    /*    Floor *g = this->getGrid();
     bool valid = g->isCellValid(new_x, new_y, getSymbol());
     /  if (valid) {
     */
    setx(new_x);
    sety(new_y);
}


void Character::strike(Character& c){
    int damage = ((100/(100+c.getDef()))*(this->getAtk()));
    if((c.getHP() - damage) < 0) {
        c.setHP(0);
    }
    else {
        c.setHP(n.getHP() - damage);
    }
}

void Character::beStruckBy(Character &c){
    c.strike(*this);
}









