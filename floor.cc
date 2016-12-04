#include <fstream>
#include <iostream>
#include "floor.h"
#include "gold.h"


Floor::Floor(std::ifstream& layout, GameObject& player) {
   grid.resize(25, std::vector<Cell>(79));
   int xRead = 0;
   int yRead = 0;
   while(yRead < 25) {
      char read;
      layout >> std::noskipws >> read;
      if(read != '\n') {
	 Cell cellRead(yRead, xRead, read, player);
	 grid[yRead][xRead] = cellRead;
	 if(xRead == 78) {
	    xRead = 0;
	    ++yRead;
	 }
	 else {
	    ++xRead;
	 }
      }
   }
}

void Floor::setGrid(int y, int x, Cell set) {
   grid[y][x] = set;
}

std::vector<std::vector <Cell> > Floor::getGrid() {
	return grid;
}     	                       


void Floor::objectAdd(int r, int c, GameObject *obj) {
   grid[r][c].add(obj);
}

void Floor::objectRemove(int r, int c){
   grid[r][c].remove();
}

char Floor::getSymbol(int r, int c){
   return grid[r][c].getSymbol();
}

void Floor::setDragonHoard(int r, int c, bool status){
   grid[r][c].setDragonHoard(status);
}

bool Floor::getDragonHoard(int r, int c){
   return grid[r][c].getDragonHoard();
}

GameObject* Floor::getObj(int r, int c) {
   return grid[r][c].getObject();
}

bool Floor::isCellValid(int r, int c, bool isPlayer) {
   if(isPlayer) {
      return grid[r][c].getPlayerValid();
   }
   else {
      return grid[r][c].getEnemyValid();
   }
}

void Floor::print() {
   for(unsigned int i=0; i<grid.size(); ++i) {
      for(unsigned int j=0; j<grid[i].size(); ++j) {
	 std::cout << grid[i][j].getSymbol();
      }
      std::cout << std::endl;
   }
}
