#ifndef _GOLD_H_
#define _GOLD_H_
#include "GameObject.h"

class Gold: public GameObject {
	int value;
	bool pickable;

	public:
	Gold(int x, int y, int value);
	bool getPickable() override;
	void setPickable(bool status) override;
	void setGold(int gold) override;
	int getGold() override;
	~Gold();	
};

#endif
