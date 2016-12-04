#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "cell.h"
#include "floor.h"
#include "Enemy.h"
#include "Character.h"
#include "Player.h"
#include "GameObject.h"
#include "gold.h"

int main() {
	//Generate from file or randomly
	std::string s;
	while(1) {
		std::cout << "Welcome to ChamberCrawler3000! Press 'F' to generate a floor from a file or 'G' to randomly generate it." << std::endl;
		std::cin >> s;
		std::vector<Floor> floors;
		GameObject* player;
		if(std::cin.eof() || s == "q") {
			return 0;
		}
		else if(s == "F") {
			std::cout << "Please enter the file name.";
			std::cin >> s;
			std::ifstream layout;
			layout.open(s);
			int floorCount = 0;
			while(floorCount < 5) {
				Floor board(layout, *player);
				floors.emplace_back(board);
				++floorCount;
			}
		}
		else {
			std::ifstream layout;
			std::vector<Floor> floors;
			int floorCount = 0;
			while(floorCount < 5) {
				layout.open("floorLayout.txt");
				Floor board(layout, *player);
				floors.emplace_back(board);
				layout.close();
				++floorCount;
			}
			layout.open("floorLayout.txt");
		}
		//Race Choice
		std::cout << "Please choose a race." << std::endl;
		std::cin >> s;
		if(std::cin.eof() || s == "q") {
			return 0;
		}
		else if(s == "drow") {
			player = new Drow(0,0,&floors[0]);
		}
		else if(s == "vampire") {
			player = new Vampire(0,0,&floors[0]);
		}
		else if(s == "troll") {
			player = new Troll(0,0,&floors[0]);
		}
		else if(s == "goblin") {
			player = new Goblin(0,0,&floors[0]);
		}
		else {
			player = new Shade(0,0,&floors[0]);
		}
		while(1) {
			int floorLevel = 0;
			std::cin >> s;
			if(std::cin.eof() || s == "q") {
				return 0;
			}
			else if(s == "r") {
				delete player;
				break;
			}
			else if(s == "f") {
				//NEED TO CHANGE ENEMY MOVABLE TO STATIC
				//When it is static flipping the switch of movable will change all Enemies movable field to false
				//Stops enemies from moving
			}
			else if(s == "u") {
				std::cin >> s;
				int newX = player->getx();
				int newY = player->gety();
				if(s == "no") ++newY;
				else if(s == "so") --newY;
				else if(s == "ea") ++newX;
				else if(s == "we") --newX;
				else if(s == "ne") {
					++newX;
					++newY;
				}
				else if(s == "nw") {
					--newX;
					++newY;
				}
				else if(s == "se") {
					++newX;
					--newY;
				}
				else if(s == "sw") {
					--newX;
					--newY;
				}
				Cell potionCell = floors[floorLevel].getGrid()[newY][newX];
				potionCell.getObject()->usePotion(*player);
			}
			else if(s == "a") {
				std::cin >> s;
				int x = player->getx();
				int y = player->gety();
				if(s == "no") ++y;
				else if(s == "so") --y;
				else if(s == "ea") ++x;
				else if(s == "we") --x;
				else if(s == "ne") {
					++x;
					++y;
				}
				else if(s == "nw") {
					--x;
					++y;
				}
				else if(s == "se") {
					++x;
					--y;
				}
				else if(s == "sw")  {
					--x;
					--y;
				}
				Cell enemyCell = floors[floorLevel].getGrid()[y][x];
				player->strike(*(enemyCell.getObject()));
			}
			else {
				player->shift(s);
			}

			//Enemy's turn
			for(int i=0; i<25; ++i) {
				for(int j=0; j<79; ++j) {
					Cell enemy = floors[floorLevel].getGrid()[i][j];
					if(enemy.getSymbol() == 'H' ||
					   enemy.getSymbol() == 'W' ||
   			   		   enemy.getSymbol() == 'E' ||
					   enemy.getSymbol() == 'O' ||
				           enemy.getSymbol() == 'M' ||
					   enemy.getSymbol() == 'D' ||
				           enemy.getSymbol() == 'L') {
 						   //First check if movable

						   //Check if player nearby, using *player
						   if(true) {
							enemy.getObject()->strike(*player);
						   }
						   else {
							int direction = rand() % 8 + 1;
							if(direction == 1) enemy.getObject()->shift("no");
							else if(direction == 2) enemy.getObject()->shift("so");
							else if(direction == 3) enemy.getObject()->shift("ea");
							else if(direction == 4) enemy.getObject()->shift("we");
							else if(direction == 5) enemy.getObject()->shift("ne");
							else if(direction == 6) enemy.getObject()->shift("nw");
							else if(direction == 7) enemy.getObject()->shift("se");
							else if(direction == 8) enemy.getObject()->shift("sw");
                          }
                     }
				}
			}
		}
	}
}
