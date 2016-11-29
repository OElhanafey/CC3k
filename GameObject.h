#ifndef GameObject_h
#define GameObject_h

#include "floor.h"
#include <string>

class Floor;
class GameObject{
protected:
    int x;
    int y;
    char symbol;
    Floor *grid;
public:
    GameObject(int x, int y, char symbol, Floor *grid);
    int getx();
    int gety();
    char getSymbol() const;
    void setx(int n);
    void sety(int n);
    void setsym(char s);
    virtual int getHP() = 0;
    virtual int getAtk() = 0;   
    virtual int getDef() = 0;
    virtual int getGold() = 0;
    virtual void setHP(int) = 0;
    virtual void setAtk(int) = 0;
    virtual void setDef(int) = 0;
    virtual void setGold(int) = 0;
    virtual std::string getRace() = 0;
    virtual void setMerchantHostile() = 0;
    virtual bool getMerchantHostile() = 0;
    virtual void enemyDeath(GameObject &p) = 0; 
    virtual void shift(std::string dir) = 0;
    virtual void strike(GameObject &c) = 0;
    virtual void beStruckBy(GameObject &c) = 0;
     ~GameObject();
};

#endif
