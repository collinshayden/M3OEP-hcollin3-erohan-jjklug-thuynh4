//
// Created by Hayden Collins on 2/21/23.
//

#include "Bishop.h"

vector<int> Bishop::getAttackedSquares(int initial_pos) {
    vector<int> possible_moves;
    int bishop_offsets[4] = {15, -15, 17, -17};
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 8; j++) {
            int target_sq = initial_pos + bishop_offsets[i] * j;
            if (!(target_sq & 0x88)) {
                possible_moves.push_back(target_sq);
            }
        }
    }
    return possible_moves;
}

Bishop::Bishop(int side) : Piece(side) {
    side ? value = 4 : value = 10;
    unicode = "♗";
}
