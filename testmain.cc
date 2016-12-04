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
				Floor board(layout);
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
				Floor board(layout);
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
			player = new Drow(0,0);
		}
		else if(s == "vampire") {
			player = new Vampire(0,0);
		}
		else if(s == "troll") {
			player = new Troll(0,0);
		}
		else if(s == "goblin") {
			player = new Goblin(0,0);
		}
		else {
			player = new Shade(0,0);
		}
		floors[0].print();
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
				player->strike(*(enemyCell.getObject()), &floors[floorLevel]);
			}
			else {
				player->shift(s, &floors[floorLevel]);
			}
			floors[floorLevel].print();
		}
	}
}
