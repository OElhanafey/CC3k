#include "GameObject.h"

GameObject::GameObject(int x, int y, char symbol, Floor *grid): x(x), y(y), symbol(symbol), grid(grid){}

GameObject::~GameObject(){}

int GameObject::getx(){
    return x;
}

int GameObject::gety(){
    return y;
}

char GameObject::getSymbol() const{
    return symbol;
}

Floor* GameObject::getGrid() {
   return grid;
}

void GameObject::setx(int n){
    x = n;
}

void GameObject::sety(int n){
    y = n;
}

void GameObject::setsym(char s){
    symbol = s;
}

// Virtual function definitions
int GameObject::getGold() { return 0; }
void GameObject::setGold(int g) { }

// Default definitions for functions specific to the Character class
int GameObject::getHP() { return 0; }
int GameObject::getAtk() { return 0; }
int GameObject::getDef() { return 0; }
int GameObject::getMaxHP() { return 0; }
int GameObject::getMaxAtk() { return 0; }
int GameObject::getMaxDef() { return 0; }
void GameObject::setHP(int) { }
void GameObject::setAtk(int) { }
void GameObject::setDef(int) { }
std::string GameObject::getRace() { return ""; }
void GameObject::setMerchantHostile() { }
bool GameObject::getMerchantHostile() { return false; }
void GameObject::shift(std::string dir) { }
void GameObject::playerMove(std::string dir) { }
void GameObject::strike(GameObject &c) { }
void GameObject::beStruckBy(GameObject &c) { }
void GameObject::action(GameObject &p) { }
void GameObject::enemyDeath(GameObject &p) { }
int GameObject::getHoardX() { return -1; }
int GameObject::getHoardY() { return -1; }
bool GameObject::getEnemyMovable() { return false; }
void GameObject::setEnemyMovable() { }

// Default definitions for functions specific to the Gold class
bool GameObject::getPickable() { return false; }
void GameObject::setPickable(bool status) { }
