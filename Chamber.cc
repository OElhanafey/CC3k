#include "Chamber.h"

Chamber::Chamber(){}

Chamber::~Chamber(){}

void Chamber::buildChamber(int initX, int initY, int row, int column){
        for(int i = initX; i < row; i++){
                for(int j = initY; j < column; j++){
                        possibleCell.emplace_back(std:make_pair(i,j));
                }
        }
}
