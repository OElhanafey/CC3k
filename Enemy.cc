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

// Helper functions to check if the Player is within one block radius or not.

// If the cell is player, then the player is within one block, so strike, by checking if the bool within_radius is true.
// If the bool radius is false, then you need to move.
// You need to randomly generate a position where enemy can move, so before doing that you need to store the valid enemy cells
// in a vector, and then randomnly generate and make the enemy move there. You can do object add/remove for enemy.

bool validRadius(int x, int y, Floor *grid){
    bool within_radius = false;
    if(((grid->getSymbol(x+1, y)) == '@') ||
       ((grid->getSymbol(x-1, y)) == '@') ||
       ((grid->getSymbol(x, y+1)) == '@') ||
       ((grid->getSymbol(x, y-1)) == '@') ||
       ((grid->getSymbol(x+1, y+1)) == '@') ||
       ((grid->getSymbol(x-1, y-1)) == '@') ||
       ((grid->getSymbol(x+1, y-1)) == '@') ||
       ((grid->getSymbol(x-1, y+1)) == '@')) {
        within_radius = true;
    }
    return within_radius;
}

std::vector<std::string> validCellEnemy(int x, int y, Floor *g){
    std::vector<std::string> validDir;
    if(g->isCellValid(x - 1, y, false)) validDir.emplace_back("no");
    if(g->isCellValid(x + 1, y, false)) validDir.emplace_back("so");
    if(g->isCellValid(x, y + 1, false)) validDir.emplace_back("ea");
    if(g->isCellValid(x, y - 1, false)) validDir.emplace_back("we");
    if(g->isCellValid(x + 1, y -1, false)) validDir.emplace_back("sw");
    if(g->isCellValid(x - 1, y + 1, false)) validDir.emplace_back("ne");
    if(g->isCellValid(x - 1, y - 1, false)) validDir.emplace_back("nw");
    if(g->isCellValid(x + 1, y + 1, false)) validDir.emplace_back("se");
    return validDir;
}

// Action function, if the player is within one block radius of the enemy or the dragon Hoard
// then the enemy strikes.
// But if the player is not within one block radius of the enemy or the dragon hoard, then the
// enemy moves randomly within the one block radius (Note only, where the enemy cell is valid).
void Enemy::action(GameObject &p){
    Floor *g = this->getGrid();
    int e_x = this->getx();
    int e_y = this->gety();
    int dX, dY; //Dragon hoardx, hoardy location.
    if(getSymbol() == 'D'){
        dX = getHoardX();
        dY = getHoardY();
    }
    bool oneBlock = validRadius(e_x, e_y, g);
    bool dragonGoldBlock = validRadius(dX, dY, g);
    if(oneBlock || dragonGoldBlock){
        p.beStruckBy(*this);
    }
    else{
        std::vector <std::string> moveEnemy = validCellEnemy(e_x, e_y, g);
        if(moveEnemy.size() != 0){
            std::srand(time(NULL));
            int i = std::rand() % moveEnemy.size();
            this->shift(moveEnemy[i]);
        }
    }
}

Human::Human(int x, int y, Floor *grid):
Enemy(x,y,'H',grid,140,20,20) {}

Dwarf::Dwarf(int x, int y, Floor *grid):
Enemy(x,y,'W',grid,100,20,30) {}

Elf::Elf(int x, int y, Floor *grid):Enemy(x,y,'E',grid,140,30,10) {}

Orc::Orc(int x, int y, Floor *grid):
Enemy(x,y,'O',grid,180,30,25) {}

Merchant::Merchant(int x, int y, Floor *grid):
Enemy(x,y,'M',grid,30,70,5) {}

Dragon::Dragon(int x, int y, Floor *grid, int hoardX, int hoardY):
Enemy(x,y,'D',grid,150,20,20,false) {}

Halfling::Halfling(int x, int y, Floor *grid):
Enemy(x,y,'L',grid,100,15,20) {}


