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

void Floor::generate() {
	//Player
	bool generated = false;
	int playerChamber = std::rand() % 5;
	while(!generated) {
		int array = std::rand() % chamber[playerChamber].size();
		if(chamber[playerChamber]./*Access array*/.isPlayerValid()) {
			//Generate Player
			generated = true;
		}
	}
	//Stairs
	generated = false;
	while(!generated) {
		int chamber = std::rand() % 5;
		if(chamber != playerChamber) {
			generated = true;
		}
	}
	generated = false;
	while(!generated) {
		array = std::rand() % chamber[chamber].size();
		if(chamber[chamber]./*Access array*/.isPlayerValid()) {
			//Generate stairs
			generated = true;
		}
	}
	//Potions
	int amountGen = 0;
	while(amountGen < 10) {
		int type = std::rand() % 6 + 1;
		chamber = std::rand() % 5;
		array = std::rand() % chamber[chamber].size();
		if(chamber[chamber]/*Access array*/.isEnemyValid()) {
			if(type == 1) {
				//Restore Health
			}
			else if(type == 2) {
				//Boost Atk
			}
			else if(type == 3) {
				//Boost Def
			}
			else if(type == 4) {
				//Poison health
			}
			else if(type == 5) {
				//Wound Atk
			}
			else {
				//Wound Def
			}
			++amountGen;
		}
	}
	//Gold
	amountGen = 0;
	while(amountGen < 10) {
		type = std::rand() % 8 + 1;
		chamber = std::rand() % 5;
		array = std::rand() % chamber[chamber].size();
		if(chamber[chamber]/*Access array*/.isEnemyValid()) {
			if(type >= 1 && type <= 5) {
				GameObject* gold = new Gold(2);
			}
			else if(type == 6) {
				GameObject* gold = new Gold(6);
			}
			else {
				GameObject* gold = new Gold(1);
			}
			int x,y; //GET Coordinates
			objectAdd(x,y,gold);
			// setting the dragonhoard to true if the gold type is dragon gold.
			if(gold->getGold() == 6){
				setDragonHoard(x,y,true);
			}
			++amountGen
		}
	}
	//Enemy
	amountGen = 0;
	while(amountGen < 20) {
		type = std::rand() % 18 + 1;
		chamber = std::rand() % 5;
		array = std::rand() % chamber[chamber].size();
		if(chamber[chamber]/*Access array*/.isEnemyValid()) {
			if(type >= 1 && type <= 4) {
				//std::shared_ptr<Human> human(new Human(x,y));
			}
			else if(type >= 5 <= 7) {
				//Dwarf
			}
			else if(type >= 8 && type <= 12) {
				//Halfling
			}
			else if(type >= 13 && type <= 14) {
				//Elf
			}
			else if(type >= 15 && type <= 16) {
				//Orc
			}
			else if(type >= 17 && type <= 18) {
				//Merchant
			}
			++amountGen;
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

void Floor::generate(Floor* g, std::vector<Chamber> chambers) {
	//Player
	bool generated = false;
	int playerChamber = std::rand() % 5;
	while(!generated) {
		int array = std::rand() % chamber[playerChamber].getCells().size();
    std::pair<int,int> coor = chambers[playerChamber].getCells()[array];
    int x = coor.first;
    int y = coor.second;
		if(g->getGrid()[x][y].isPlayerValid()) {
			g->getGrid()[x][y].setSymbol('@');
			generated = true;
		}
	}
	//Stairs
	generated = false;
	while(!generated) {
		int chamber = std::rand() % 5;
		if(chamber != playerChamber) {
			generated = true;
		}
	}
	generated = false;
	while(!generated) {
		array = std::rand() % chamber[chamber].size();
    std::pair<int,int> coor = chambers[chamber].getCells()[array];
    int x = coor.first;
    int y = coor.second;
		if(g->getGrid()[x][y].isPlayerValid()) {
			g->getGrid[x][y].setSymbol('@');
			generated = true;
		}
	}
#ifndef DEBUG
  //Potions
	int amountGen = 0;
	while(amountGen < 10) {
		int type = std::rand() % 6 + 1;
		chamber = std::rand() % 5;
		array = std::rand() % chamber[chamber].size();
		if(chamber[chamber]/*Access array*/.isEnemyValid()) {
			if(type == 1) {
				//Restore Health
			}
			else if(type == 2) {
				//Boost Atk
			}
			else if(type == 3) {
				//Boost Def
			}
			else if(type == 4) {
				//Poison health
			}
			else if(type == 5) {
				//Wound Atk
			}
			else {
				//Wound Def
			}
			++amountGen;
		}
	}
	//Gold
	amountGen = 0;
	while(amountGen < 10) {
		type = std::rand() % 8 + 1;
		chamber = std::rand() % 5;
		array = std::rand() % chamber[chamber].size();
		if(chamber[chamber]/*Access array*/.isEnemyValid()) {
			if(type >= 1 && type <= 5) {
				GameObject* gold = new Gold(2);
			}
			else if(type == 6) {
				GameObject* gold = new Gold(6);
			}
			else {
				GameObject* gold = new Gold(1);
			}
			int x,y; //GET Coordinates
			objectAdd(x,y,gold);
			// setting the dragonhoard to true if the gold type is dragon gold.
			if(gold->getGold() == 6){
				setDragonHoard(x,y,true);
			}
			++amountGen
		}
	}
	//Enemy
	amountGen = 0;
	while(amountGen < 20) {
		type = std::rand() % 18 + 1;
		chamber = std::rand() % 55;
		array = std::rand() % chamber[chamber].size();
		if(chamber[chamber]/*Access array*/.isEnemyValid()) {
			if(type >= 1 && type <= 4) {
				//Human
			}
			else if(type >= 5 <= 7) {
				//Dwarf
			}
			else if(type >= 8 && type <= 12) {
				//Halfling
			}
			else if(type >= 13 && type <= 14) {
				//Elf
			}
			else if(type >= 15 && type <= 16) {
				//Orc
			}
			else if(type >= 17 && type <= 18) {
				//Merchant
			}
			++amountGen;
		}
	}
  #endif
}

void Floor::print() {
   for(unsigned int i=0; i<grid.size(); ++i) {
      for(unsigned int j=0; j<grid[i].size(); ++j) {
	 std::cout << grid[i][j].getSymbol();
      }
      std::cout << std::endl;
   }
}
