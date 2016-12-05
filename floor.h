#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <vector>
#include <sstream>
#include "cell.h"
#include "Chamber.h"

class GameObject;

class Floor {
    std::vector<std::vector<Cell>> grid;
public:
    Floor(std::ifstream& layout, GameObject& player);
    void setGrid(int y, int x, Cell set);
    Cell* getGrid(int x, int y);
    void setDragonHoard(int r, int c, bool status);
    bool getDragonHoard(int r, int c);
    void objectAdd(int r, int c, GameObject *obj);
    void objectRemove(int r, int c);
    char getSymbol(int r, int c);
    GameObject* getObj(int r, int c);
    bool isCellValid(int r, int c, bool isPlayer);
    void generate(std::vector<Chamber> chambers, GameObject* player);
    void print(GameObject& player);
};

#endif
