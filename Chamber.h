#ifndef Chamber_h
#define Chamber_h
#include "floor.h"
#include <vector>

class Chamber{
    std::vector <std::pair<int,int>> possibleCell;
public:
    Chamber();
    void buildChamber(int initX, int initY, int width, int height)
    ~Chamber();
};
#endif /* Chamber_h */

