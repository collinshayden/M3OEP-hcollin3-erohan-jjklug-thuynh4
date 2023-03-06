//
// Created by Hayden Collins on 2/21/23.
//

#include "King.h"

vector<int> King::getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) {
    vector<int> attacked_squares;
    //index offsets for king moves in 1x128 board representation
    int king_offsets[8] = {16, -16, 1, -1, 15, -15, 17, -17};
    for (int i = 0; i < 8; i++) {
        int target_sq = initial_pos + king_offsets[i];
        //if the square is on the board
        if (!(target_sq & 0x88)) {
            attacked_squares.push_back(target_sq);
        }
    }
    return attacked_squares;
}

King::King(bool side) : Piece(side) {
    pieceType = 'K';
    unicode = "♔";
}
