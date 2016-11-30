#include "gameObject.h"

class Gold: public GameObject {
	int value;
	bool pickable;

	public:
	Gold();
	bool getPickable();
	void setPickable(bool status);
	void setGold();
	int getGold();
	~Gold();	
}
