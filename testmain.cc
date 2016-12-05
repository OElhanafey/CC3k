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
		player->setx(3);
		player->sety(10);
		
		int floorLevel = 0;
		while(1) {
                        floors[floorLevel].print();
                        std::cout << "Race : " << player->getRace() << " Gold: " << player->getGold() << std::endl;
                        std::cout << "HP : " << player->getHP() << std::endl;
                        std::cout << "Atk : " << player->getAtk() << std::endl;
                        std::cout << "Def : " << player->getDef() << std::endl;

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
				if(s == "no") --newX;
				else if(s == "so") ++newX;
				else if(s == "ea") ++newY;
				else if(s == "we") --newY;
				else if(s == "ne") {
					++newY;
					--newX;
				}
				else if(s == "nw") {
					--newY;
					--newX;
				}
				else if(s == "se") {
					++newY;
					++newX;
				}
				else if(s == "sw") {
					--newY;
					++newX;
				}
				Cell potionCell = floors[floorLevel].getGrid()[newX][newY];
				potionCell.getObject()->usePotion(*player);
			}
			else if(s == "a") {
				std::cin >> s;
				int x = player->getx();
				int y = player->gety();
				std::cout << x << " " << y << std::endl;
				if(s == "no") --x;
				else if(s == "so") ++x;
				else if(s == "ea") ++y;
				else if(s == "we") --y;
				else if(s == "ne") {
					++y;
					--x;
				}
				else if(s == "nw") {
					--y;
					--x;
				}
				else if(s == "se") {
					++y;
					++x;
				}
				else if(s == "sw")  {
					--y;
					++x;
				}
				Cell enemyCell = floors[floorLevel].getGrid()[x][y];
				std::cout << enemyCell.getSymbol() << enemyCell.getx() << enemyCell.gety() << std::endl;
				player->strike(*(enemyCell.getObject()), &floors[floorLevel]);
			}
			else {
				player->shift(s, &floorLevel, &floors[floorLevel]);
			}
		}
	}
}
