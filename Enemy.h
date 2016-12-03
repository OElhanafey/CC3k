#ifndef Enemy_h
#define Enemy_h

#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include "Character.h"
#include "Player.h"
#include "gold.h"
#include "floor.h"

class Potion;
class Player;

class Enemy: public Character{
    bool movable;
public:
    Enemy(int x, int y, char symbol, Floor *grid, int health, int attack, int defense, bool movable = true);
    bool getEnemyMovable() override;
    void setEnemyMovable() override;
    void enemyDeath(GameObject &p) override;
    void action(GameObject &p) override;
   /* virtual*/ ~Enemy();
};

class Human: public Enemy{
public:
    Human(int x, int y, Floor *grid);
};

class Dwarf: public Enemy{
public:
    Dwarf(int x, int y, Floor *grid);
};

class Elf: public Enemy{
public:
    Elf(int x, int y, Floor *grid);
};

class Orc: public Enemy{
public:
    Orc(int x, int y, Floor *grid);
};

class Merchant: public Enemy{
public:
    Merchant(int x, int y, Floor *grid);
};

class Dragon: public Enemy{
    int hoardX, hoardY;
public:
    int getHoardX() override;
    int getHoardY() override;
    Dragon(int x, int y, Floor *grid, int hoardX, int hoardY);
};

class Halfling: public Enemy{
public:
    Halfling(int x, int y, Floor *grid);
};

#endif /* Enemy_h */
