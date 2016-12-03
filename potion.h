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
	virtual void usePotion(GameObject& player) = 0;
}

class RestoreHp: public Potion {
	void usePotion(GameObject& player);
}
class BoostAtk: public Potion {
	void usePotion(GameObject& player);
}
class BoostDef: public Potion {
	void usePotion(GameObject& player);
}
class PoisonHp: public Potion {
	void usePotion(GameObject& player);
}
class WoundAtk: public Potion {
	void usePotion(GameObject& player);
}
class WoundDef: public Potion {
	void usePotion(GameObject& player);
}
