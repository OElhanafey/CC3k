#ifndef Player_h
#define Player_h

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include "Character.h"
#include "GameObject.h"
#include "Enemy.h"

class Potion;
class Enemy;

class Player: public Character{
protected:
    bool merchantHostile;
    bool enemyMovable;
    int level;
    int maxhp, origAtk, origDef;
    std::string message;
    std::string race;
    int potionEffect;
public:
    Player(int x, int y, int health, int attack, int defense, std::string race, int potionEffect = 1);
    std::string getRace();
    void setLevel(int floor);
    int getLevel();
    bool getEnemyMovable() override;
    void setEnemyMovable() override;
    int getMaxHp() override;
    std::string getMessage() override;
    void setMessage(std::string) override;
    int getPotionEffect() override;
    bool getMerchantHostile() override;
    void setMerchantHostile() override;
    void callAction(Floor *g);
    std::vector<std::pair<std::string,int>> potionsNearby(Floor *g) override;
   /* virtual*/ ~Player();
};

class Shade: public Player{
public:
    Shade(int x, int y);
};

class Drow: public Player{
public:
    Drow(int x, int y);
//    void usePotion(Potion& );
};

class Vampire: public Player{
public:
    Vampire(int x, int y);
//    void strike(Npc &) override;
};

class Troll: public Player{
public:
    Troll(int x, int y);
//    void strike(Character &) override;
};

class Goblin: public Player{
public:
    Goblin(int x, int y);
//    void strike(Character &) override;
};

#endif /* Player_h */
