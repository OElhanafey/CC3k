#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <vector>
#include "cell.h"
#include "GameObject.h"

class Cell;
class GameObject;

class Floor {
    std::vector<std::vector<Cell>> grid;
public:
    Floor();
    void objectAdd(int r, int c, GameObject *obj);
    void objectRemove(int r, int c);
    GameObject* getObj(int r, int c);
    //	bool isCellValid(int r, int c, char sym);
    void print();
};

#endif
