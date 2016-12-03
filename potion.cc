#include "potion.h"

Potion::Potion(int x, int y, Floor *grid): 
	GameObject(x , y, 'P', grid) {
	   usedRH = "unknown potion";
	   usedBA = "unknown potion";
	   usedBD = "unknown potion";
	   usedPH = "unknown potion";
	   usedWA = "unknown potion";
	   usedWD = "unknown potion";
	}

// Boosts up the health
RestoreHp::Restore(int x, int y, Floor * grid):
	Potion(x,y,grid) {}

void RestoreHp::usePotion(Player& player) {
   // Change bool if potion used for the first time
   if (usedRH == "unknown potion") usedRH = "RH"; 
   
   // Calculate the amount of boost in health received by a player
   int diff = player.getMaxHp() - player.getHP();
   int boost = 10;
   if((player.getRace() != "Vampire") && (boost > diff)) boost = diff;

   player.setHP(player.getHP() + boost);
}

// Increases the attack points
BoostAtk::BoostAtk(int x, int y, Floor *grid):
	Potion(x,y,grid) {}

void BoostAtk::usePotion(Player& player) {
   if (usedBA == "unknown potion") usedBA = "BA";
   player.setAtk(player.getAtk() + 5);
}

// Increases the defense points
BoostDef::BoostDef(int x, int y, Floor *grid):
	Potion(x,y,grid) {}

void BoostDef::usePotion(Player& player) {
   if (usedBD == "unknown potion") usedBA = "BD";
   player.setDef(player.getDef() + 5);
}

// Decreases the health points. Cannot fall before 0.
PotionHp::PotionHp(int x, int y, Floor *grid):
	Potion(x,y,grid) {}

void PoisonHp::usePotion(Player& player) {
   if (usedPH == "unknown potion") usedPH = "PH";

    // Calculate the amount of boost in health received by a player
    int damage = 10;
    if ((player.getHP() - 10) < 0) damage = player.getHP();
    
    player.setHP(player.getHP() - damage);  

    // Throw game over exception if health goes down to 0
    if(player.getHP() == 0) throw "Game Over";
}

// Decreases the attack points.
void WoundAtk::usePotion(GameObject& player) {
	if(player.getAtk() < 5) {
		player.setAtk(0);
	}
	else {
		player.setAtk(player.getAtk()-5);
	}
}

// Decreases the defense points.
void WoundDef::usePotion(GameObject& player) {
	if(player.getDef() < 5) {
		player.setDef(0);
	}
	else {
		player.setDef(player.getDef()-5);
	}
}
