#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <vector>
#include "cell.h"

class GameObject;

class Floor {
    std::vector<std::vector<Cell>> grid;
public:
    Floor(std::ifstream& layout);
    void setGrid(int y, int x, Cell set);
    std::vector<std::vector<Cell> > getGrid();
    void setDragonHoard(int r, int c, bool status);
    bool getDragonHoard(int r, int c);
    void objectAdd(int r, int c, GameObject *obj);
    void objectRemove(int r, int c);
    char getSymbol(int r, int c);
    GameObject* getObj(int r, int c);
    bool isCellValid(int r, int c, bool isPlayer);
    void generate();
    void print();
};

#endif
