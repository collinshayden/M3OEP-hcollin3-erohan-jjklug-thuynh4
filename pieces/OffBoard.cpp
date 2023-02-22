//
// Created by Hayden Collins on 2/22/23.
//

#include "OffBoard.h"

OffBoard::OffBoard() : Piece() {
    value = 0x88;
    unicode = "";
}

vector<int> OffBoard::getAttackedSquares(int initial_pos) {
    return vector<int>{};
}
