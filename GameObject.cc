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

//int GameObject::getHP(){}
