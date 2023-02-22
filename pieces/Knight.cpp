//
// Created by Hayden Collins on 2/21/23.
//

#include "Knight.h"

vector<int> Knight::getAttackedSquares(int initial_pos) {
    // in a 1x128, knights move up two ranks/files and over one (16*2 +-1 or 16 +- 2)
    vector<int> possible_moves;
    int knight_offsets[8] = {33, 31, 18, 14, -33, -31, -18, -14};
    for (int i = 0; i < 8; i++) {
        int target_sq = initial_pos + knight_offsets[i];
        //if the square is on the board
        if (!(target_sq & 0x88)) {
            possible_moves.push_back(target_sq);
        }
    }
    return possible_moves;
}

Knight::Knight(bool side) : Piece(side) {

}
