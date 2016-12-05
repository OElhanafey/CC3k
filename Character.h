#ifndef Character_h
#define Character_h

#include "GameObject.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Character:public GameObject{
protected:
    int health, attack, defense;
    std::string race;
    int gold;    
public:
    static std::pair<int,int> radius[8];
    Character(int x, int y, char symbol,int health, int attack, int defense, std::string race = "", int gold = 0);
    int getHP() override;
    int getAtk() override;
    int getDef() override;
    int getGold() override;
    std::string getRace() override;
    void setHP(int hp) override;
    void setAtk(int at) override;
    void setDef(int def) override;
    void setGold(int g) override;
    void shift(std::string dir, Floor *g); // If player, check 1 block radius and output all potions in the 1 block radius
    void strike(GameObject *c, Floor *g) override;
    void beStruckBy(GameObject *c, Floor *g) override;
    ~Character();
};

#endif /* Character_h */
