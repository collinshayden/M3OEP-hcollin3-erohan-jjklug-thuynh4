//
// Created by Hayden Collins on 2/21/23.
//

#include "Queen.h"

vector<int> Queen::getAttackedSquares(int initial_pos) {
    vector<int> possible_moves;
    //index offsets for queen moves in 1x128 board representation
    int queen_offsets[8] = {16, -16, 1, -1, 15, -15, 17, -17};
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            int target_sq = initial_pos + queen_offsets[i] * j;
            //if the square is on the board
            if (!(target_sq & 0x88)) {
                possible_moves.push_back(target_sq);
            }
        }
    }
    return possible_moves;
}

Queen::Queen(bool side) : Piece(side) {
    side ? value = 5 : value = 11;
    unicode = "♕";
}
