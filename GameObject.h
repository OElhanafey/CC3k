#ifndef GameObject_h
#define GameObject_h

#include <string>
#include <vector>
#include <utility>

class Player;
class Floor;
class GameObject{
protected:
    int x;
    int y;
    char symbol;
//    Floor *grid;
public:
    // Functions specific to GameObject
    GameObject(int x, int y, char symbol);
    int getx();
    int gety();
    char getSymbol() const;
   // Floor *getGrid();
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
    virtual int getMaxHp();
//    virtual int getMaxAtk();
//    virtual int getMaxDef();
    virtual void setHP(int);
    virtual void setAtk(int);
    virtual void setDef(int);
    virtual std::string getRace();
    virtual void setLevel(int);
    virtual int getLevel();
    virtual int getPotionEffect();
    virtual void setMerchantHostile();
    virtual bool getMerchantHostile();
    virtual void shift(std::string dir, Floor *g);
    virtual void strike(GameObject &c, Floor *g);
    virtual void beStruckBy(GameObject &c, Floor *g);
    virtual void callAction(Floor *g);
    virtual void action(GameObject &p, Floor *g);
    virtual void enemyDeath(GameObject &p, Floor *g);
    virtual int getHoardX();
    virtual int getHoardY();
    virtual bool getEnemyMovable();
    virtual void setEnemyMovable();
    virtual std::vector<std::pair<std::string,int>> potionsNearby(Floor *g);

    // Functions specific to Gold
    virtual bool getPickable();
    virtual void setPickable(bool status);

    // Functions specific to Potion
    virtual std::string potionType();
    virtual void usePotion(GameObject &p, Floor* g);

    virtual ~GameObject() = 0;
};

#endif
