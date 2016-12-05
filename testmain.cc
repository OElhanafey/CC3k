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
                //Race Choice
                std::cout << "Welcome to ChamberCrawler3000! Please choose a race." << std::endl;
                std::cin >> s;
		GameObject* player;
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
		std::cout << "Press 'f' to generate a floor from a file or any other key to randomly generate it." << std::endl;
		std::cin >> s;
		if(std::cin.eof() || s == "q") {
			return 0;
		}
		std::ifstream layout;
		std::string read;
		read = s;
		std::vector<Floor> floors;
		while(1) {
		if(read == "f") {
			if(player->getLevel() == 0) {
				std::cout << "Please enter the file name.";
				std::cin >> s;
				layout.open(s);
				Floor board(layout, *player);
				floors.emplace_back(board);
			}
			else {
				Floor board(layout, *player);
				floors[0] = board;
			}
		}
		else {
			int floorCount = 0;
			while(floorCount < 5) {
				layout.open("floorLayout.txt");
				Floor board(layout, *player);
				floors.emplace_back(board);
				layout.close();
				++floorCount;
			}
		}
		int playerLevel = player->getLevel();
		while(playerLevel == player->getLevel()) {
			std::cout << "Player Coordinates : " << player->getx() << " " << player->gety() << std::endl;
                        floors[0].print();
			std::cout << "Floor : " << player->getLevel() + 1;
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
				player->setEnemyMovable();
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
				Cell potionCell = floors[0].getGrid()[newX][newY];
				potionCell.getObject()->usePotion(*player);
			}
			else if(s == "a") {
				std::cin >> s;
				int x = player->getx();
				int y = player->gety();
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
				Cell enemyCell = floors[0].getGrid()[x][y];;
				player->strike(*(enemyCell.getObject()), &floors[0]);
			}
			else {
				player->shift(s, &floors[0]);
			}
		}
		}
	}
}
