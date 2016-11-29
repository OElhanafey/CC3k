#include "Character.h"
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "floor.h"
using namespace std;

// Character Constructor, has the cell's location, the symbol, to represent

Character::Character(int x, int y, char symbol, Floor *grid, int health, int attack, int defense, double accuracy, int gold):
	GameObject(x,y,symbol, grid),
	health(health),
	attack(attack),
	defense(defense),
	accuracy(accuracy),
	gold(gold){}

	Character::~Character() {}

	int Character::getHP() {
		return health;
	}

int Character::getAtk() {
	return attack;
}

int Character::getDef() {
	return defense;
}

int Character::getgold(){
	return gold;
}

void Character::setHP(int hp){
	health = hp;
}

void Character::setAtk(int at){
	attack = at;
}

void Character::setDef(int def){
	defense = def;
}

void Character::setgold(int g){
	gold = g;
}

void Character::shift(std::string dir){
	int new_x,new_y;
	if(dir == "no"){
		new_x = getx()-1;
		new_y = gety();
	}
	else if(dir == "so"){
		new_x = getx()+1;
		new_y = gety();
	}
	else if(dir == "ea"){
		new_x = getx();
		new_y = gety()+1;
	}
	else if(dir == "we"){
		new_x = getx();
		new_y = gety()-1;
	}
	else if(dir == "ne"){
		new_x = getx()-1;
		new_y = gety()+1;
	}
	else if(dir == "nw"){
		new_x = getx()-1;
		new_y = gety()-1;
	}
	else if(dir == "se"){
		new_x = getx()+1;
		new_y = gety()+1;
	}
	else if(dir == "sw"){
		new_x = getx()+1;
		new_y = gety()-1;
	}
	/*    Floor *g = this->getGrid();
	      bool valid = g->isCellValid(new_x, new_y, getSymbol());
	      /  if (valid) {
	 */
	setx(new_x);
	sety(new_y);
}


void Character::strike(GameObject &c){
	//std::cout <<  <<std::endl; 
	if(this->getRace() == "Troll"){
		if(((this->getHP()) + 5) > 120){
			this->setHP(120);
		}
		else{
			this->setHP((this->getHP()) + 5);
		}
	}
	double temp = c.getDef(); 
	double damage = ceil((100/(100+temp))*(this->getAtk()));
	std::cout << damage << std::endl;
	if((c.getHP() - damage) < 0) {
		c.setHP(0);
	}
	else {
		c.setHP(c.getHP() - damage);
		std::cout << c.getHP() << std::endl;
	}
}

// Generate the chance of being hit.
/*
static int generateHit(){
	std::srand(time(NULL));
	int hit = std::rand() % 2;
	return hit;
}
*/
void Character::beStruckBy(GameObject &c){
	int hit = 1;
	if((this->getSymbol() == '@') || (this->getSymbol() == 'H')){
		//hit = generateHit();
		std::srand(time(NULL));
		 hit = std::rand() % 2;
	}
	if(hit == 1){
		c.strike(*this);
		if(this->getSymbol() == 'M'){
			c.setMerchantHostile();
		}
		else if((c.getSymbol()) == 'E'){
			std::srand(time(NULL)+1);
			 hit = std::rand() % 2;
			//hit = generateHit();
			if(!(this->getRace() == "Drow") && (hit == 1)){
				c.strike(*this);
			}
		}
	}
}









