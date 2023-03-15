//
// Created by Hayden Collins on 2/21/23.
//

#include "Knight.h"

Knight::Knight(bool side) : Piece(side) {
    piece_type = 'N';
    unicode = "♘";
}

vector<int> Knight::getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) {
    //index offsets for knight moves in 1x128 board representation
    vector<int> attacked_squares;
    int knight_offsets[8] = {33, 31, 18, 14, -33, -31, -18, -14};
    for (int i = 0; i < 8; i++) {
        int target_sq = initial_pos + knight_offsets[i];
        //is the square on the board
        if (!(target_sq & 0x88)) {
            if (board.at(target_sq)->unicode != ".") {
                if (board.at(initial_pos)->side != board.at(target_sq)->side) {
                    attacked_squares.push_back(target_sq);
                }
            } else {
                attacked_squares.push_back(target_sq);
            }
        }
    }
    return attacked_squares;
}

