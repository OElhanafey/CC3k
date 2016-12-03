#include "GameObject.h"

class Potion: public GameObject {
	static bool usedRH;
	static bool usedBA;
	static bool usedBD;
	static bool usedPH;
	static bool usedWA;
	static bool usedWD;

public:
  //  Potion(){};
	virtual void usePotion(Player& player) = 0;
}

class RestoreHp: public Potion {
	void usePotion(Player& player);
}
class BoostAtk: public Potion {
	void usePotion(Player& player);
}
class BoostDef: public Potion {
	void usePotion(Player& player);
}
class PoisonHp: public Potion {
	void usePotion(Player& player);
}
class WoundAtk: public Potion {
	void usePotion(Player& player);
}
class WoundDef: public Potion {
	void usePotion(Player& player);
}
