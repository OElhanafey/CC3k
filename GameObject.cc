#include "GameObject.h"

GameObject::GameObject(int x, int y, char symbol): x(x), y(y), symbol(symbol){}

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

/*
Floor* GameObject::getGrid() {
   return grid;
}
*/

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
void GameObject::setHP(int) { }
void GameObject::setAtk(int) { }
void GameObject::setDef(int) { }
void GameObject::setMessage(std::string){ }
std::string GameObject::getMessage(){ return "";}
std::string GameObject::getRace() { return ""; }
void GameObject::setLevel(int) { }
int GameObject::getLevel() { return 0; }
int GameObject::getMaxHp(){ return 0;}
int GameObject::getPotionEffect(){return 0;}
void GameObject::setMerchantHostile() { }
bool GameObject::getMerchantHostile() { return false; }
void GameObject::shift(std::string dir,Floor *g) { }
void GameObject::strike(GameObject &c, Floor *g) { }
void GameObject::beStruckBy(GameObject &c, Floor *g) { }
void GameObject::callAction(Floor *g){ }
void GameObject::action(GameObject &p, Floor *g) { }
void GameObject::enemyDeath(GameObject &p, Floor *g) { }
int GameObject::getHoardX() { return -1; }
int GameObject::getHoardY() { return -1; }
bool GameObject::getEnemyMovable() { return false; }
void GameObject::setEnemyMovable() { }
std::vector<std::pair<std::string,int>> GameObject::potionsNearby(Floor *g) {
    std::vector<std::pair<std::string,int>> p;
    return p;
};

// Default definitions for functions specific to the Gold class
bool GameObject::getPickable() { return false; }
void GameObject::setPickable(bool status) { }

// Default definitions for functions specific to the Potion class
std::string GameObject::potionType() { return ""; }
void GameObject::usePotion(GameObject &p, Floor* g) { }
