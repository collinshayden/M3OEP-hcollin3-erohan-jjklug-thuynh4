//
// Created by Hayden Collins on 2/21/23.
//

#include "King.h"

// enum that lets us easily convert between algebraic coordinates and indices
enum squares {
    a8 = 0,   b8, c8, d8, e8, f8, g8, h8,
    a7 = 16,  b7, c7, d7, e7, f7, g7, h7,
    a6 = 32,  b6, c6, d6, e6, f6, g6, h6,
    a5 = 48,  b5, c5, d5, e5, f5, g5, h5,
    a4 = 64,  b4, c4, d4, e4, f4, g4, h4,
    a3 = 80,  b3, c3, d3, e3, f3, g3, h3,
    a2 = 96,  b2, c2, d2, e2, f2, g2, h2,
    a1 = 112, b1, c1, d1, e1, f1, g1, h1, no_sq
};

King::King(bool side) : Piece(side) {
    piece_type = 'K';
    unicode = "♔";
}

vector<int> King::getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) {
    vector<int> attacked_squares;
    //index offsets for king moves in 1x128 board representation
    int king_offsets[8] = {16, -16, 1, -1, 15, -15, 17, -17};
    for (int i = 0; i < 8; i++) {
        int target_sq = initial_pos + king_offsets[i];
        //if the square is on the board
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

vector<bool> castleAvailability(bool side, vector<unique_ptr<Piece>> &board, vector<int> opp_attacked_squares) {
    //index 0 for kingside, index 1 for queenside
    vector<bool> castles = {false,false};
    //note, we don't need to check if the destination king squares (g1,c1 for white) because it will be done when checking legality
    //white
    if (side) {
        //if the king has not moved, and is not in check
        if (board.at(e1)->piece_type == 'K' && !board.at(e1)->has_moved && board.at(e1)->side == side && find(opp_attacked_squares.begin(), opp_attacked_squares.end(), e1) == opp_attacked_squares.end()) {
            //kingside
            //if the rook hasn't moved and f1 is not attacked
            if (board.at(h1)->piece_type == 'R' && !board.at(h1)->has_moved && find(opp_attacked_squares.begin(), opp_attacked_squares.end(), f1) == opp_attacked_squares.end()) {
                castles.at(0) = true;
            }
            //queenside
            //if the rook hasn't moved and c1 is not attacked
            if (board.at(a1)->piece_type == 'R' && !board.at(a1)->has_moved && find(opp_attacked_squares.begin(), opp_attacked_squares.end(), c1) == opp_attacked_squares.end()) {
                castles.at(1) = true;
            }
        }
    }
    //black
    else {
        if (board.at(e8)->piece_type == 'K' && !board.at(e8)->has_moved && board.at(e8)->side == side && find(opp_attacked_squares.begin(), opp_attacked_squares.end(), e8) == opp_attacked_squares.end()) {
            //kingside
            //if the rook hasn't moved and f8 is not attacked
            if (board.at(h8)->piece_type == 'R' && !board.at(h8)->has_moved && find(opp_attacked_squares.begin(), opp_attacked_squares.end(), f8) == opp_attacked_squares.end()) {
                castles.at(0) = true;
            }
            //queenside
            //if the rook hasn't moved and c8 is not attacked
            if (board.at(a8)->piece_type == 'R' && !board.at(a8)->has_moved && find(opp_attacked_squares.begin(), opp_attacked_squares.end(), c8) == opp_attacked_squares.end()) {
                castles.at(1) = true;
            }
        }
    }
    return castles;
}
