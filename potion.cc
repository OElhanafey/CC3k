#include "potion.h"

// Boosts up the health
void RestoreHp::usePotion(Player& player) {
	//Will need to change for vampire which have no maxhp
    //Drow potion effects are 1.5
    if(player.getRace() == "Vampire"){
        player.setHP(player.getHP() + 10);
    }
    else{
        if(player.getMaxHp() < (player.getHP() + 10)) {
            player.setHP(player.getMaxHp());
        }
        else {
            player.setHP(player.getHP+10);
        }
    }
}

// Increases the attack points
void BoostAtk::usePotion(Player& player) {
	player.setAtk(player.getAtk()+5);
}

// Increases the defense points
void BoostDef::usePotion(Player& player) {
	player.setDef(player.getDef()+5);
}

// Decreases the health points. Cannot fall before 0.
void PoisonHp::usePotion(Player& player) {
	if(player.getHP() < 10) {
		player.setHP(0);
	}
	else {
		player.setHP(player.getHP()-10);
	}
}

// Decreases the attack points.
void WoundAtk::usePotion(Player& player) {
	if(player.getAtk() < 5) {
		player.setAtk(0);
	}
	else {
		player.setAtk(player.getAtk()-5);
	}
}

// Decreases the defense points.
void WoundDef::usePotion(Player& player) {
	if(player.getDef() < 5) {
		player.setDef(0);
	}
	else {
		player.setDef(player.getDef()-5);
	}
}
