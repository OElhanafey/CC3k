#ifndef _POTION_H_
#define _POTION_H_

#include <string>
#include "GameObject.h"

class Potion: public GameObject {
	static std::string usedRH;
	static std::string usedBA;
	static std::string usedBD;
	static std::string usedPH;
	static std::string usedWA;
	static std::string usedWD;

public:
  	Potion(int x, int y, Floor *grid);
	~Potion();
};

class RestoreHp: public Potion {
   	RestoreHp(int x, int y, Floor *grid);
    std::string potionType() override;
	void usePotion(GameObject& player) override;
};

class BoostAtk: public Potion {
   	BoostAtk(int x, int y, Floor *grid);
    std::string potionType() override;
	void usePotion(GameObject& player) override;
};

class BoostDef: public Potion {
   	BoostDef(int x, int y, Floor *grid);
    std::string potionType() override;
	void usePotion(GameObject& player) override;
};

class PoisonHp: public Potion {
   	PoisonHp(int x, int y, Floor *grid);
    std::string potionType() override;
	void usePotion(GameObject& player) override;
};

class WoundAtk: public Potion {
   	WoundAtk(int x, int y, Floor *grid);
    std::string potionType() override;
	void usePotion(GameObject& player) override;
};

class WoundDef: public Potion {
   	WoundDef(int x, int y, Floor *grid);
    std::string potionType() override;
	void usePotion(GameObject& player) override;
};

