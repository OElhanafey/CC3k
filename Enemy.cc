#include "Enemy.h"

Enemy::Enemy(int x, int y, char symbol, Floor *grid, int health, int attack, int defense, bool canMove):
   Character(x,y,symbol,grid,health,attack,defense,0.5),
   canMove(canMove)
{}

Enemy::~Enemy() {}

int Dragon::getHoardX() { return hoardX; }
int Dragon::getHoardY() { return hoardY; }

void Enemy::enemyDeath(GameObject& p) {
   int e_x = this->getx();
   int e_y = this->gety();
   Floor *g = this->getGrid();
   // If Elf, Halfling, Orc or Dwarf die, the player gets either a small or normal pile of gold
   if(getSymbol() == 'E' || 
	 getSymbol() == 'L' || 
	 getSymbol() == 'O' ||
	 getSymbol() == 'W'
     ) {
      std::srand(time(NULL));
      int gPile = (std::rand() % 2) + 1;
      p.setGold(p.getGold() + gPile);
      g->objectRemove(e_x, e_y);
   }
   // If a merchant dies, a gold object with value 4 is left replaces merchant
   // In the coordinates for Merchant on floor, change pointer pointing to Merchant to a new Gold object with value 4
   else if(getSymbol() == 'M') {
      GameObject *gold = new Gold(e_x, e_y, g, 4);
      g->objectRemove(e_x, e_y);
      g->objectAdd(e_x, e_y, gold);
   }
   // If a Human dies:
   else if(getSymbol() == 'H') {
      std::vector<std::pair<int,int>> validDir;
      if(g->isCellValid(e_x - 1, e_y, false)){
	 validDir.emplace_back(std::make_pair (e_x - 1, e_y));
      }
      if(g->isCellValid(e_x + 1, e_y, false)){
	 validDir.emplace_back(std::make_pair (e_x + 1, e_y));
      }
      if(g->isCellValid(e_x, e_y + 1, false)){
	 validDir.emplace_back(std::make_pair (e_x, e_y + 1));
      }
      if(g->isCellValid(e_x, e_y - 1, false)) {
	 validDir.emplace_back(std::make_pair (e_x, e_y - 1));
      }
      if(g->isCellValid(e_x + 1, e_y -1, false)){
	 validDir.emplace_back(std::make_pair (e_x + 1, e_y - 1));
      }
      if(g->isCellValid(e_x - 1, e_y + 1, false)){
	 validDir.emplace_back(std::make_pair (e_x - 1, e_y + 1));
      }
      if(g->isCellValid(e_x - 1, e_y - 1, false)){
	 validDir.emplace_back(std::make_pair (e_x - 1, e_y - 1));
      }
      if(g->isCellValid(e_x + 1, e_y + 1, false)){
	 validDir.emplace_back(std::make_pair (e_x + 1, e_y + 1));
      }
      int goldVal = 4;
      if (validDir.size() != 0) {
	 goldVal = 2;
	 std::srand(time(NULL));
	 int i = std::rand() % validDir.size();
	 GameObject *gold = new Gold(validDir[i].first, validDir[i].second, g, goldVal);
	 g->objectAdd(validDir[i].first, validDir[i].second, gold);
      }
      GameObject *gold = new Gold(e_x, e_y, g, goldVal);
      g->objectRemove(e_x, e_y);
      g->objectAdd(e_x, e_y, gold);

      // In the coordinates for Human on floor
      // Check which cells around human are empty and are "enemy valid"
      // Change the pointer pointing to Human to a new Gold object with value 4 if no other cell around it is empty - otherwise value 2
      // if value 2 then - randomly generate among empty cells
   }
   else {
      GameObject *gold = g->getObj(getHoardX(), getHoardY());
      gold->setPickable(true);
      g->objectRemove(e_x, e_y);
      // Go into cell with coordinates HoardX HoardY on the floor
      // Switch on bool for "pickMeUp" in gold object on that cell in floor
   }
}

Human::Human(int x, int y, Floor *grid):
   Enemy(x,y,'H',grid,140,20,20) {}

   Dwarf::Dwarf(int x, int y, Floor *grid):
      Enemy(x,y,'W',grid,100,20,30) {}

      Elf::Elf(int x, int y, Floor *grid):
	 Enemy(x,y,'E',grid,140,30,10) {}

	 Orc::Orc(int x, int y, Floor *grid):
	    Enemy(x,y,'O',grid,180,30,25) {}

	    Merchant::Merchant(int x, int y, Floor *grid):
	       Enemy(x,y,'M',grid,30,70,5) {}

	       Dragon::Dragon(int x, int y, Floor *grid, int hoardx, int hoardy):
		  Enemy(x,y,'D',grid,150,20,20,false) {}

		  Halfling::Halfling(int x, int y, Floor *grid):
		     Enemy(x,y,'L',grid,100,15,20) {}


