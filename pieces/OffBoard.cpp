//
// Created by Hayden Collins on 2/22/23.
//

#include "OffBoard.h"

OffBoard::OffBoard(int color) : Piece(color) {
    value = 0x88;
    unicode = "";
    side = color;
}

vector<int> OffBoard::getAttackedSquares(int initial_pos) {
    return vector<int>{};
}
