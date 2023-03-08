//
// Created by Hayden Collins on 2/21/23.
//

#include "Rook.h"

vector<int> Rook::getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) {
    vector<int> attacked_squares;
    //index offsets for rook moves in 1x128 board representation
    int rook_offsets[4] = {16, -16, 1, -1};
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 8; j++) {
            int target_sq = initial_pos + rook_offsets[i] * j;
            //if the square is on the board
            if (!(target_sq & 0x88)) {
                if (board.at(target_sq)->unicode != ".") {
                    if (board.at(initial_pos)->side != board.at(target_sq)->side) {
                        attacked_squares.push_back(target_sq);
                        break;
                    } else {
                        break;
                    }
                } else {
                    attacked_squares.push_back(target_sq);
                }
            }
        }
    }
    return attacked_squares;
}

Rook::Rook(bool side) : Piece(side) {
    piece_type = 'R';
    unicode = "♖";
}
