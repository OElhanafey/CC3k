#ifndef GameObject_h
#define GameObject_h

#include <string>
//#include "floor.h"

class Floor;
class GameObject{
protected:
    int x;
    int y;
    char symbol;
    Floor *grid;
public:
    // Functions specific to GameObject
    GameObject(int x, int y, char symbol, Floor *grid);
    int getx();
    int gety();
    char getSymbol() const;
    Floor *getGrid();
    void setx(int n);
    void sety(int n);
    void setsym(char s);
    
    // Functions specific to Character and Gold
    virtual int getGold();
    virtual void setGold(int);
    
    // Functions Specific to Character
    virtual int getHP();
    virtual int getAtk();
    virtual int getDef();
    virtual int getMaxHP();
    virtual int getMaxAtk();
    virtual int getMaxDef();
    virtual void setHP(int);
    virtual void setAtk(int);
    virtual void setDef(int);
    virtual std::string getRace();
    virtual void setMerchantHostile();
    virtual bool getMerchantHostile();
    virtual void shift(std::string dir);
    virtual void playerMove(std::string dir);
    virtual void strike(GameObject &c);
    virtual void beStruckBy(GameObject &c);
    virtual void enemyReaction(GameObject &p);
    virtual void enemyDeath(GameObject &p);
    virtual int getHoardX();
    virtual int getHoardY();

    // Functions specific to Gold
    virtual bool getPickable();
    virtual void setPickable(bool status);

    virtual ~GameObject() = 0;
};

#endif
