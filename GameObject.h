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
    virtual void shift(std::string dir) = 0;
    //virtual void strike(GameObject &c) = 0;
    //virtual void beStruckBy(GameObject &c) = 0;
    virtual ~GameObject() =0;
};

#endif
