#include <fstream>
#include <iostream>
#include "floor.h"
#include "gold.h"
#include "potion.h"
#include "Enemy.h"

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

Cell* Floor::getGrid(int x, int y) {
	return &grid[x][y];
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
//FUCK YOU GITHUB
void Floor::generate(std::vector<Chamber> chambers, GameObject* player) {
	//Player
	std::srand(time(0));
	bool generated = false;
	int playerChamber = std::rand() % 5;
	while(!generated) {
		int array = std::rand() % chambers[playerChamber].getCells().size();
    std::pair<int,int> coor = chambers[playerChamber].getCells()[array];
    int x = coor.first;
    int y = coor.second;
		if(getGrid(x,y)->getPlayerValid()) {
			getGrid(x,y)->setSymbol('@');
			getGrid(x,y)->setPlayerValid(false);
			getGrid(x,y)->setEnemyValid(false);
			player->setx(x);
			player->sety(y);
			generated = true;
			
		}
	}
	//Stairs
	generated = false;
	int chamber = 0;
	int array;
	while(!generated) {
		chamber = std::rand() % 5;
		if(chamber != playerChamber) {
			generated = true;
		}
	}
	generated = false;
	while(!generated) {
		array = std::rand() % chambers[chamber].getCells().size();
    std::pair<int,int> coor = chambers[chamber].getCells()[array];
    int x = coor.first;
    int y = coor.second;
		if(getGrid(x,y)->getPlayerValid()) {
			getGrid(x,y)->setSymbol('\\');
			getGrid(x,y)->setEnemyValid(false);
			generated = true;
		}
	}
  //Potions
	int amountGen = 0;
	while(amountGen < 10) {
		int type = std::rand() % 6 + 1;
		chamber = std::rand() % 5;
		array = std::rand() % chambers[chamber].getCells().size();
		std::pair<int,int> coor = chambers[chamber].getCells()[array];
		int x = coor.first;
		int y = coor.second;
		if(getGrid(x,y)->getEnemyValid()) {
			GameObject* potion;
			if(type == 1) {
				potion = new RestoreHp(x,y);
			}
			else if(type == 2) {
				potion = new BoostAtk(x,y);
			}
			else if(type == 3) {
				potion = new BoostDef(x,y);
			}
			else if(type == 4) {
				potion = new PoisonHp(x,y);
			}
			else if(type == 5) {
				potion = new WoundAtk(x,y);
			}
			else {
				potion = new WoundDef(x,y);
			}
			getGrid(x,y)->add(potion);
			++amountGen;
		}
	}
	//Gold
	amountGen = 0;
	while(amountGen < 10) {
		int type = std::rand() % 8 + 1;
		chamber = std::rand() % 5;
		array = std::rand() % chambers[chamber].getCells().size();
		std::pair<int,int> coor = chambers[chamber].getCells()[array];
		int x = coor.first;
		int y = coor.second;
		if(getGrid(x,y)->getEnemyValid()) {
			GameObject* gold;
			if(type >= 1 && type <= 5) {
				gold = new Gold(x,y,2);
			}
			else if(type == 6) {
				gold = new Gold(x,y,6);
			}
			else {
				gold = new Gold(x,y,1);
			}
			getGrid(x,y)->add(gold);
			// setting the dragonhoard to true if the gold type is dragon gold.
			if(gold->getGold() == 6){
				setDragonHoard(x,y,true);
			}
			++amountGen;
		}
	}	//Enemy
	amountGen = 0;
	while(amountGen < 20) {
		int type = std::rand() % 18 + 1;
		chamber = std::rand() % 5;
		array = std::rand() % chambers[chamber].getCells().size();
		std::pair<int,int> coor = chambers[chamber].getCells()[array];
		int x = coor.first;
		int y = coor.second;
		if(getGrid(x,y)->getEnemyValid()) {
			GameObject* enemy;
			if(type >= 1 && type <= 4) {
				enemy = new Human(x,y);
			}
			else if(type >= 5 && type <= 7) {
				enemy = new Dwarf(x,y);
			}
			else if(type >= 8 && type <= 12) {
				enemy = new Halfling(x,y);
			}
			else if(type >= 13 && type <= 14) {
				enemy = new Elf(x,y);
			}
			else if(type >= 15 && type <= 16) {
				enemy = new Orc(x,y);
			}
			else if(type >= 17 && type <= 18) {
				enemy = new Merchant(x,y);
			}
			getGrid(x,y)->add(enemy);
			++amountGen;
		}
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
