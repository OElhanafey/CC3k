#include "Character.h"
#include <string>
#include "floor.h"
using namespace std;

// Character Constructor, has the cell's location, the symbol, to represent

Character::Character(int x, int y, char symbol, int health, int attack, int defense, int gold):GameObject(x,y,symbol), health(health), attack(attack), defense(defense), gold(gold){}

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

/*
    floor[newx][newy].getIsValid() {
        floor[newx][newy].add(this);
        floor[x][y].remove();
    }
}
*/

//
void Character::moveChar(std::string dir){
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
    if(this->getSymbol() == '@'){
        if(grid[new_x][new_y].getPlayerValid()){
        grid[new_x][new_y].add(*this);
        grid[getx()][gety()].remove();
        }
    }
    else{
        if(grid[new_x][new_y].getEnemyValid()){
            grid[new_x][new_y].add(this);
            grid[getx()][gety()].remove();
        }
    }
}

