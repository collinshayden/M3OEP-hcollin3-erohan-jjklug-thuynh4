//
// Created by Hayden Collins on 2/21/23.
//

#include "Empty.h"


Empty::Empty() : Piece() {
    value = 0;
    unicode = ".";
}

vector<int> Empty::getAttackedSquares(int initial_pos) {
    return vector<int>{};
}
