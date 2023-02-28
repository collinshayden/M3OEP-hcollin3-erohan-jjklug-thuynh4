//
// Created by Hayden Collins on 2/21/23.
//

#include "Empty.h"

Empty::Empty(bool color) : Piece(color) {
    value = 0;
    unicode = ".";
    side = color;
}

vector<int> Empty::getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) {
    return vector<int>{};
}
