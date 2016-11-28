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
    Character(int x, int y, char symbol, Floor *grid,int health, int attack, int defense, int accuracy, int gold = 0);
    int getHP() const;
    int getAtk() const;
    int getDef() const;
    int getgold();
    void setHP(int hp);
    void setAtk(int at);
    void setDef(int def);
    void setgold(int g);
    void shift(std::string dir) override;
    //    virtual void strike(Character &) = 0;
    //    virtual void beStruckBy(Character &) = 0;
    //    virtual void moveChar(std::string dir) = 0;
    ~Character();
};

#endif /* Character_h */
