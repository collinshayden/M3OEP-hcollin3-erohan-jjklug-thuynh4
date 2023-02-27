//
// Created by Hayden Collins on 2/21/23.
//

#include "Bishop.h"

Bishop::Bishop(bool side) : Piece(side) {
    side ? value = 4 : value = 10;
    unicode = "♗";
}


vector<int> Bishop::getAttackedSquares(int initial_pos) {
    vector<int> possible_moves;
    //index offsets for bishop moves in 1x128 board representation
    int bishop_offsets[4] = {15, -15, 17, -17};
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 8; j++) {
            int target_sq = initial_pos + bishop_offsets[i] * j;
            //in a 1x128 board representation, below is a quick way to check if a square is on the board
            if (!(target_sq & 0x88)) {
                possible_moves.push_back(target_sq);
            }
        }
    }
    return possible_moves;
}

