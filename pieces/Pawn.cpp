//
// Created by Hayden Collins on 2/21/23.
//

#include "Pawn.h"

vector<int> Pawn::getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) {
    vector<int> attacked_squares;
    //white pawns
    if (!side) {
        if (!((initial_pos + 17) & 0x88)) {
            attacked_squares.push_back(initial_pos + 17);
        }
        if (!((initial_pos + 15) & 0x88)) {
            attacked_squares.push_back(initial_pos + 15);
        }
    }
        //black pawns
    else {
        if (!((initial_pos - 17) & 0x88)) {
            attacked_squares.push_back(initial_pos - 17);
        }
        if (!((initial_pos - 15) & 0x88)) {
            attacked_squares.push_back(initial_pos - 15);
        }
    }
    return attacked_squares;
}

Pawn::Pawn(bool side) : Piece(side) {
    side ? value = 1 : value = 7;
    unicode = "♙";
}
