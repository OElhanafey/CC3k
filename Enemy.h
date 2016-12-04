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
public:
    Enemy(int x, int y, char symbol, int health, int attack, int defense);
    void enemyDeath(GameObject &p, Floor *g) override;
    void action(GameObject &p, Floor *g) override;
   /* virtual*/ ~Enemy();
};

class Human: public Enemy{
public:
    Human(int x, int y);
    void enemyDeath(GameObject &p, Floor *g) override;
};

class Dwarf: public Enemy{
public:
    Dwarf(int x, int y);
};

class Elf: public Enemy{
public:
    Elf(int x, int y);
};

class Orc: public Enemy{
public:
    Orc(int x, int y);
};

class Merchant: public Enemy{
public:
    Merchant(int x, int y);
    void enemyDeath(GameObject &p, Floor *g) override;
};

class Dragon: public Enemy{
    int hoardX, hoardY;
public:
    int getHoardX() override;
    int getHoardY() override;
    void enemyDeath(GameObject &p, Floor *g) override;
    Dragon(int x, int y, int hoardX, int hoardY);
};

class Halfling: public Enemy{
public:
    Halfling(int x, int y);
};

#endif /* Enemy_h */
