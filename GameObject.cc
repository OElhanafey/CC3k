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
virtual int GameObject::getGold() { return 0; }
virtual void GameObject::setGold() { }

// Default definitions for functions specific to the Character class
virtual int getHP() { return 0; }
virtual int getAtk() { return 0; }
virtual int getDef() { return 0; }
virtual int getMaxHP() { return 0; }
virtual int getMaxAtk() { return 0; }
virtual int getMaxDef() { return 0; }
virtual void setHP(int) { }
virtual void setAtk(int) { }
virtual void setDef(int) { }
virtual std::string getRace() { return ""; }
virtual void setMerchantHostile() { }
virtual bool getMerchantHostile() { return false; }
virtual void shift(std::string dir) { }
virtual void playerMove(std::string dir) { }
virtual void strike(GameObject &c) { }
virtual void beStruckBy(GameObject &c) { }
virtual void enemyReaction(GameObject &p) { }
virtual void enemyDeath(GameObject &p) { }
