#include "Enemy.h"

Enemy::Enemy(int x, int y, char symbol, int health, int attack, int defense):
	Character(x,y,symbol,health,attack,defense){}

Enemy::~Enemy() {}

Human::Human(int x, int y):
Enemy(x,y,'H',140,20,20) {}

Dwarf::Dwarf(int x, int y):
Enemy(x,y,'W',100,20,30) {}

Elf::Elf(int x, int y):
Enemy(x,y,'E',140,30,10) {}

Orc::Orc(int x, int y):
Enemy(x,y,'O',180,30,25) {}

Merchant::Merchant(int x, int y):
Enemy(x,y,'M',30,70,5) {}

Dragon::Dragon(int x, int y, int hoardX, int hoardY):
Enemy(x,y,'D',150,20,20) {}

Halfling::Halfling(int x, int y):
Enemy(x,y,'L',100,15,20) {}


int Dragon::getHoardX() { return hoardX; }
int Dragon::getHoardY() { return hoardY; }

// If Elf, Halfling, Orc or Dwarf die, the player gets either a small or normal pile of gold
void Enemy::enemyDeath(GameObject& p, Floor *g) {
    int e_x = this->getx();
    int e_y = this->gety();
    // If Elf, Halfling, Orc or Dwarf die, the player gets either a small or normal pile of gold
    std::srand(time(NULL));
    int gPile = (std::rand() % 2) + 1;
    p.setGold(p.getGold() + gPile);
    g->objectRemove(e_x, e_y);
}

// If a merchant dies, a gold object with value 4 is left replaces merchant
// In the coordinates for Merchant on floor, change pointer pointing to Merchant to a new Gold object with value 4
void Merchant::enemyDeath(GameObject& p, Floor *g) {
    int e_x = this->getx();
    int e_y = this->gety();
    
    Gold* gold = new Gold(e_x, e_y, 4);
    
    g->objectRemove(e_x, e_y);
    g->objectAdd(e_x, e_y, gold);
}

// If a Human dies (MODIFY THIS LATER TO REDUCE REPEATING CODE):
// In the coordinates for Human on floor
// Check which cells around human are empty and are "enemy valid"
// Change the pointer pointing to Human to a new Gold object with value 4 if no other cell around it is empty - otherwise value 2
// if value 2 then - randomly generate among empty cells
void Human::enemyDeath(GameObject& p, Floor *g) {
    int e_x = this->getx();
    int e_y = this->gety();
    
    std::vector<std::pair<int,int>> validDir;
    
    for(int i = 0; i < 8; ++i) {
        int rX = e_x + radius[i].first;
        int rY = e_y + radius[i].second;
        if(g->isCellValid(rX, rY, false)){
            validDir.emplace_back(std::make_pair(rX, rY));
        }
    }
    
    int goldVal = 4;
    if (validDir.size() != 0) {
        goldVal = 2;
        std::srand(time(NULL));
        int i = std::rand() % validDir.size();
        Gold* gold = new Gold(validDir[i].first, validDir[i].second, goldVal);
        g->objectAdd(validDir[i].first, validDir[i].second, gold);
    }
    
    Gold* gold = new Gold(e_x, e_y, goldVal);
    g->objectRemove(e_x, e_y);
    g->objectAdd(e_x, e_y, gold);
}

// Go into cell with coordinates HoardX HoardY on the floor
// Switch on bool for "pickMeUp" in gold object on that cell in floor
void Dragon::enemyDeath(GameObject& p, Floor *g) {
    int e_x = this->getx();
    int e_y = this->gety();
    GameObject *gold = g->getObj(getHoardX(), getHoardY());
    gold->setPickable(true);
    g->objectRemove(e_x, e_y);
}

// Helper function to check if a player is within a 1 block radius of an enemy
static bool isNearby(GameObject &enemy, GameObject &player) {
    bool playerNearby = false;
    
    // Enemy's coordinates
    int eX = enemy.getx();
    int eY = enemy.gety();
    
    // Player's coordinates
    int pX = player.getx();
    int pY = player.gety();
    
    // Check if player is within a 1 block radius of the Enemy
    if ( (abs(pX - eX) <= 1) && (abs(pY - eY) <= 1) ) {
        playerNearby = true;
    }
    
    if( (enemy.getSymbol() == 'D') && !playerNearby ) {
        int dX = enemy.getHoardX();
        int dY = enemy.getHoardY();
        // Check if player is within a 1 block radius of the dragon hoard
        if ( (abs(pX - dX) <= 1) && (abs(pY - dY) <= 1) ){
            playerNearby = true;
        }
    }
    return playerNearby;
}


// Action function, if the player is within one block radius of the enemy or the dragon Hoard then the enemy strikes. But if the player is not within one block radius of the enemy or the dragon hoard, then the enemy moves randomly within the one block radius (Note only, where the enemy cell is valid).

void Enemy::action(GameObject &p,Floor *g){
    bool playerNearby = isNearby(*this, p);
    bool canAttack = true;
    
    if (getSymbol() == 'M' && !p.getMerchantHostile()) {
        canAttack = false;
    }
 
    // If player is nearby strike the player
    if(playerNearby && canAttack){
        p.beStruckBy(this,g);
    }
    
    else{
        if (p.getEnemyMovable() && getSymbol() != 'D') {
            std::string directions[8] = {"no", "so", "ea", "we", "ne", "nw", "se", "sw"};
            std::srand(time(NULL));
            int i = std::rand() % 8;
            shift(directions[i], g);
        }
    }
}

