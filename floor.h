#include <vector>
#include "cell.h"

class Floor {
    		std::vector< std::vector<Cell> > grid;
  	public:
    		Floor();
    		void print();
};
