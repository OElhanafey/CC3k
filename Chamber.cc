#include "Chamber.h"
Chamber::Chamber(){}

std::vector <std::pair<int, int>> Chamber::getCells() {
	return possibleCell;
}

void Chamber::buildChamber(int initX, int initY, int lastX, int lastY){
        for(int i = initX; i <= lastX; i++){
                for(int j = initY; j <= lastY; j++){
                        possibleCell.emplace_back(std::make_pair(i,j));
                }
        }
}
