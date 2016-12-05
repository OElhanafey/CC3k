#ifndef Chamber_h
#define Chamber_h
#include "floor.h"
#include <vector>

class Chamber{
    std::vector <std::pair<int,int>> possibleCell;
public:
    Chamber();
    std::vector <std::pair<int, int>> getCells();
    void buildChamber(int initX, int initY, int lastX, int lastY);
};
#endif /* Chamber_h */

