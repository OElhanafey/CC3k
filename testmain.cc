#include <iostream>
#include <vector>
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
		if(s.eof() || s == "q") {
			return;
		}
		else if(s == 'F') {
			std::cout << "Please enter the file name."
			std::cin >> s;
			std::ifstream layout;
			layout.open(s);
			std::vector<Floor> floors;
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
				layout.close("floorLayout.txt");
				++floorCount;
			}
			layout.open("floorLayout.txt");
		}
		//Race Choice
		std::cout << "Please choose a race." << std::endl;
		std::cin >> s;
		if(s.eof() || s == "q") {
			return;
		}
		else if(s == "drow") {
			GameObject* player = new Drow(x,y,grid);
		}
		else if(s == "vampire") {
			GameObject* player = new Vampire(x,y,grid);
		}
		else if(s == "troll") {
			GameObject* player = new Troll(x,y,grid);
		}
		else if(s == "goblin") {
			GameObject* player = new Goblin(x,y,grid);
		}
		else {
			GameObject* player = new Shade(x,y,grid);
		}
		while(1) {
			int floorLevel = 0;
			std::cin >> s;
			if(s.eof() || s == "q") {
				//Exit
			}
			else if(s == "r") {
				delete player;
				break;
			}
			else if(s == "f") {
				//NEED TO CHANGE ENEMY MOVABLE TO STATIC
				//Stops enemies from moving
			}
			else if(s == "u") {
				std::cin >> s;
				if(s == "no") ;
				else if(s == "so") ;
				else if(s == "ea") ;
				else if(s == "we") ;
				else if(s == "ne") ;
				else if(s == "nw") ;
				else if(s == "se") ;
				else if(s == "sw") ;
			}
			else if(s == "a") {
				std::cin >> s;
				int x = player.getx();
				int y = player.gety();
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
				Cell enemyCell = floors[floorLevel].getGrid(x,y);
				player.strike(enemyCell.getObj());
			}
			else {
				player.shift(s);
			}

			//Enemy's turn
			for(int i=0; i<25; ++i) {
				for(int j=0; j<79 ++j) {
					Cell enemy = floors[floorLevel].getGrid(j,i);
					if(enemy.getSymbol() == 'H' ||
					   enemy.getSymbol() == 'W' ||
   			   		   enemy.getSymbol() == 'E' ||
					   enemy.getSymbol() == 'O' ||
				        enemy.getSymbol() == 'M' ||
					   enemy.getSymbol() == 'D' ||
				        enemy.getSymbol() == 'L') {
						   //Strike or Move
					   }
				}
			}
		}
	}
}
