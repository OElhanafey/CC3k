#include "potion.h"

void RestoreHp::usePotion(Player& player) {
	//Will need to change for vampire which have no maxhp
	if(player.getMaxHp() < (player.getHP() + 10)) {
		player.setHP(player.getMaxHp());
	}
	else {
		player.setHP(player.getHP+10);
	}
}

void BoostAtk::usePotion(Player& player) {
	player.setAtk(player.getAtk()+5);
}
void BoostDef::usePotion(Player& player) {
	player.setDef(player.getDef()+5);
}
void PoisonHp::usePotion(Player& player) {
	if(player.getHP() < 10) {
		player.setHP(0);
	}
	else {
		player.setHP(player.getHP()-10);
	}
}
void WoundAtk::usePotion(Player& player) {
	if(player.getAtk() < 5) {
		player.setAtk(0);
	}
	else {
		player.setAtk(player.getAtk()-5);
	}
}
void WoundDef::usePotion(Player& player) {
	if(player.getDef() < 5) {
		player.setDef(0);
	}
	else {
		player.setDef(player.getDef()-5);
	}
}
