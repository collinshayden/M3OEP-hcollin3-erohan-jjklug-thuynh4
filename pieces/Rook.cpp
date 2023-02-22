//
// Created by Hayden Collins on 2/21/23.
//

#include "Rook.h"

vector<int> Rook::getAttackedSquares(int initial_pos) {
    vector<int> possibleMoves;
    int rook_offsets[4] = {16, -16, 1, -1};
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 8; j++) {
            int target_sq = initial_pos + rook_offsets[i] * j;
            //if the square is on the board
            if (!(target_sq & 0x88)) {
                possibleMoves.push_back(target_sq);
            }
        }
    }
    return possibleMoves;
}
