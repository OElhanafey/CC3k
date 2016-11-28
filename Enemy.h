#ifndef Enemy_h
#define Enemy_h

#include <string>
#include <iostream>
#include "Character.h"
#include "Player.h"

class Potion;
class Player;

class Enemy: public Character{
    bool canMove;
public:
    Enemy(int x, int y, char symbol, Floor *grid, int health, int attack, int defense, int accuracy, bool canMove = true);
    // virtual void move(std::string dir);
    //virtual void strike(Npc &);
    //virtual void beStruckBy(Npc &);
    // virtual void action();
    // virtual void death();
   /* virtual*/ ~Enemy();
};

/*class Human: public Enemy{
public:
    Human(int x, int y, Floor *grid);
    void death();
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
    Dragon(int x, int y, Floor *grid, int hX, int hY);
};

class Halfling: public Enemy{
public:
    Halfling(int x, int y, Floor *grid);
};
*/
#endif /* Enemy_h */
