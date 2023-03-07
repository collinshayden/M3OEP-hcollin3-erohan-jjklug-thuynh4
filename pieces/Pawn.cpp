//
// Created by Hayden Collins on 2/21/23.
//

#include "Pawn.h"
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

Pawn::Pawn(bool side) : Piece(side) {
    pieceType = 'P';
    unicode = "♙";
}

vector<int> Pawn::getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) {
    vector<int> attacked_squares;
    //white pawns
    if (!side) {
        if (!((initial_pos + 17) & 0x88)) {
            attacked_squares.push_back(initial_pos + 17);
        }
        if (!((initial_pos + 15) & 0x88)) {
            attacked_squares.push_back(initial_pos + 15);
        }
    }
        //black pawns
    else {
        if (!((initial_pos - 17) & 0x88)) {
            attacked_squares.push_back(initial_pos - 17);
        }
        if (!((initial_pos - 15) & 0x88)) {
            attacked_squares.push_back(initial_pos - 15);
        }
    }
    return attacked_squares;
}

vector<int> getPawnPushes(int initial_pos, bool side, vector<unique_ptr<Piece>> &board) {
    vector<int> pawn_pushes;
    if (side) {//white
        int target_sq = initial_pos - 16;//pawn moves up one square
        if (!(target_sq & 0x88) && board.at(target_sq)->unicode == ".") {
                pawn_pushes.push_back(target_sq);
            }
            //if pawn hasn't moved, it can move two squares
            if (!board.at(initial_pos)->hasMoved) {
                target_sq -= 16; //two squares
                //if the pawn is on the second rank, target square is on board, and the squares in front are empty
                //pawn can move two squares
                if (initial_pos >= a2 && initial_pos <= h2 && !(target_sq & 0x88) &&
                    board.at(target_sq)->unicode == ".") {
                    pawn_pushes.push_back(target_sq);
                }
            }
        }
     else {//black
        int target_sq = initial_pos + 16;//pawn moves up one square
        if (!(target_sq & 0x88) && board.at(target_sq)->unicode == ".") {
            pawn_pushes.push_back(target_sq);
            //if pawn hasn't moved, it can move two squares
            if (!board.at(initial_pos)->hasMoved) {
                target_sq += 16; //two squares
                //if the pawn is on the second rank, target square is on board, and the squares in front are empty
                //pawn can move two squares
                if (initial_pos >= a7 && initial_pos <= h7 && !(target_sq & 0x88) &&
                    board.at(target_sq)->unicode == ".") {
                    pawn_pushes.push_back(target_sq);
                }
            }
        }
    }
    return pawn_pushes;
}
