//INCOMPLETE
//Error: Enemies can walk on gold (Make validPlayer, validEnemy?)

class GameObject;
class Cell {
		char symbol;
		//-1 - No item 0 - RH, 1 - BA, 2 - BD, 3 - PH, 4 - WA, 5 - WD
		//6 normal gold pile, 7 - small hoard, 8 - merchant hoard
		//9 - dragon hoard. 10 - Human 11 - Dwarf 12 - Halfling 13 - Elf
		//14 - Orc 15 - Merchant 16 - Dragon
		GameObject* obj;
		int x,y;
		bool isPlayerValid;
		bool isEnemyValid;
	public:
		Cell();
		Cell(int x, int y, char sym);
		char getSymbol();
		void add(GameObject* object);
		void remove();
};
