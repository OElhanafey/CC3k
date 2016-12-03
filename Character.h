#ifndef Character_h
#define Character_h

#include "GameObject.h"
#include <iostream>
#include <string>

class Character:public GameObject{
protected:
    int health, attack, defense;
    double accuracy;
    int gold;
public:
    Character(int x, int y, char symbol, Floor *grid,int health, int attack, int defense, double accuracy, int gold = 0);
    int getHP() override;
    int getAtk() override;
    int getDef() override;
    int getGold() override;
    void setHP(int hp) override;
    void setAtk(int at) override;
    void setDef(int def) override;
    void setGold(int g) override;
    void shift(std::string dir); // If player, check 1 block radius and output all potions in the 1 block radius
    void strike(GameObject &c) override;
    void beStruckBy(GameObject &c) override;
    ~Character();
};

#endif /* Character_h */
