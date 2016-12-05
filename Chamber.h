#ifndef Chamber_h
#define Chamber_h
#include "floor.h"
#include <vector>

class Chamber{
    std::vector <std::pair<int,int>> possibleCell;
public:
    Chamber();
    void buildChamber(int initX, int initY, int lastX, int lastY)
    ~Chamber();
};
#endif /* Chamber_h */

