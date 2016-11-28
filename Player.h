
#ifndef Player_h
#define Player_h

#include <string>
#include <iostream>
#include "Character.h"
#include "Npc.h"

class Potion;
class Npc;

class Player: public Character{
protected:
    int level;
    int maxhp, maxatk, maxdef;
    std::string race;
    int potionEffect;
public:
    Player(int x, int y, Floor *grid, int health, int attack, int defense, int accuracy, std::string race, int potionEffect = 1);
    virtual void strike(Npc &);
    virtual void beStruckBy(Npc &);
    virtual void usePotion(Potion& );
    virtual void checkPotion(Potion& );
    virtual ~Player();
};

class Shade: public Player{
public:
    Shade(int x, int y);
};

class Drow: public Player{
public:
    Drow(int x, int y);
    void usePotion(Potion& );
};

class Vampire: public Player{
public:
    Vampire(int x, int y);
    void strike(Npc &) override;
};

class Troll: public Player{
public:
    Troll(int x, int y);
    void strike(Character &) override;
};

class Goblin: public Player{
public:
    Goblin(int x, int y);
    void strike(Character &) override;
};

#endif /* Player_h */
