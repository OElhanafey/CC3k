#include "Enemy.h"

Enemy::Enemy(int x, int y, char symbol, Floor *grid, int health, int attack, int defense, bool canMove):
    Character(x,y,symbol,grid,health,attack,defense,0.5),
    canMove(canMove)
    {}

Enemy::~Enemy() {}

void Enemy::enemyDeath(GameObject& p) {
   // If Elf, Halfling, Orc or Dwarf die, the player gets either a small or normal pile of gold
   if(getSymbol() == 'E' || 
      getSymbol() == 'L' || 
      getSymbol() == 'O' ||
      getSymbol() == 'W'
      ) {
      std::srand(time(NULL));
      int gPile = (std::rand() % 2) + 1;
      p.setGold(p.getGold() + gPile);
   }
   // If a merchant dies, a gold object with value 4 is left replaces merchant
   else if(getSymbol() == 'M') {
      // In the coordinates for Merchant on floor
      // Change pointer pointing to Merchant to a new Gold object with value 4
   }
   // If a Human dies:
            // 1. One Gold item with value 2 replaces the human object at that cell
            // 2. A second gold object near the first one if there is an empty cell available
   else if(getSymbol() == 'H') {
      // In the coordinates for Human on floor
      // Check which cells around human are empty and are "enemy valid"
      // Change the pointer pointing to Human to a new Gold object with value 4 if no other cell around it is empty - otherwise value 2
      // if value 2 then - randomly generate among empty cells
   }
   else {
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


