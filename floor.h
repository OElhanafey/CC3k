#include <vector>

class Cell;
class Floor {
    std::vector<std::vector<Cell> > grid;
  public:
    Floor();
    ~Floor();
    print();
}
