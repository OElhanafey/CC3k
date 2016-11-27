
#ifndef Character_h
#define Character_h

#include "GameObject.h"
#include <iostream>
#include <string>

class Character:public GameObject{
protected:
    int health, attack, defense;
    int accuracy;
    int gold;
public:
    Character(int x, int y, char symbol, int health, int attack, int defense, int gold);
    int getHP() const;
    int getAtk() const;
    int getDef() const;
    int getgold();
    void setHP(int hp);
    void setAtk(int at);
    void setDef(int def);
    void setgold(int g);
    virtual void strike(Character &) = 0;
    virtual void beStruckBy(Character &) = 0;
    void moveChar(std::string dir);
    virtual ~Character() = 0;
};

#endif /* Character_h */
