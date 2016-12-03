#ifndef Player_h
#define Player_h

#include <string>
#include <iostream>
#include "Character.h"
#include "GameObject.h"
#include "Enemy.h"

class Potion;
class Enemy;

class Player: public Character{
protected:
    bool merchantHostile;
    int level;
    int maxhp, origAtk, origDef;
    std::string race;
    int potionEffect;
public:
    Player(int x, int y, int health, int attack, int defense, std::string race, int potionEffect = 1);
    std::string getRace();
    int getMaxHp() override;
    int getPotionEffect() override;
    bool getMerchantHostile() override;
    void setMerchantHostile() override;
//    virtual void usePotion(Potion& );
//    virtual void checkPotion(Potion& );
   /* virtual*/ ~Player();
};

class Shade: public Player{
public:
    Shade(int x, int y);
};

class Drow: public Player{
public:
    Drow(int x, int y;
//    void usePotion(Potion& );
};

class Vampire: public Player{
public:
    Vampire(int x, int y);
//    void strike(Npc &) override;
};

class Troll: public Player{
public:
    Troll(int x, int y;
//    void strike(Character &) override;
};

class Goblin: public Player{
public:
    Goblin(int x, int y);
//    void strike(Character &) override;
};

#endif /* Player_h */
