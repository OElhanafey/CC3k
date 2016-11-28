#include <fstream>
#include <iostream>
#include "floor.h"
Floor::Floor() {
    grid.resize(25, std::vector<Cell>(79));
    std::ifstream layout;
    int xRead = 0;
    int yRead = 0;
    layout.open("floorLayout.txt");
    while(!layout.eof()) {
        char read;
        layout >> std::noskipws >> read;
        if(read != '\n') {
            Cell cellRead(xRead, yRead, read);
            grid[xRead][yRead] = cellRead;
            if(yRead == 78) {
                yRead = 0;
                ++xRead;
            }
            else {
                ++yRead;
       		   }
            
        }
    }
}

void Floor::objectAdd(int r, int c, GameObject *obj) {
    grid[r][c].add(obj);
}

void Floor::objectRemove(int r, int c){
    grid[r][c].remove();
}

GameObject* Floor::getObj(int r, int c) {
    return grid[r][c].getObject();
}

/*bool isCellValid(Floor &f, int r, int c, char sym) {
 return f.grid[r][c].isValid();
 }*/

void Floor::print() {
    for(unsigned int i=0; i<grid.size(); ++i) {
        for(unsigned int j=0; j<grid[i].size(); ++j) {
            std::cout << grid[i][j].getSymbol();
        }
        std::cout << std::endl;
    }
}

