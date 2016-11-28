#ifndef GameObject_h
#define GameObject_h

#include "floor.h"

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
    virtual ~GameObject() =0;
};

#endif
