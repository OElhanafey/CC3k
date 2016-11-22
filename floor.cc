#include <ifstream>
#include "floor.h"

Floor::Floor() {
  Cell grid [79][25];
  ifstream layout;
  layout.open("floorLayout.txt");
  while(!layout.eof()) {
    
  }
}
