//
// Created by Hayden Collins on 2/21/23.
//

#include "King.h"

vector<int> King::getAttackedSquares(int initial_pos) {
    vector<int> possible_moves;
    int king_offsets[8] = {16, -16, 1, -1, 15, -15, 17, -17};
    for (int i = 0; i < 8; i++) {
        int target_sq = initial_pos + king_offsets[i];
        if (!(target_sq) & 0x88) {
            possible_moves.push_back(target_sq);
        }
    }
    return possible_moves;
}

King::King(int side) : Piece(side) {
    side ? value = 6 : value = 12;
    unicode = "♔";
}
