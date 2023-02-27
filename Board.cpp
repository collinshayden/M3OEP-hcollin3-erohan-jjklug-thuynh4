//
// Created by Hayden Collins on 2/3/23.
//
#include "Board.h"
#include <stdio.h>
#include "pieces/pieceClasses.h"
#include "string"
#include <iostream>
#include <map>

using namespace std;

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


Board::Board(bool setup) {
    //starting with empty board
    for (int j = 0; j < 128; j++) {
        board.push_back(std::unique_ptr<Piece>(make_unique<Empty>(true)));
    }

    //setting squares to proper pieces, otherwise empty (useful for debugging)
    if (setup) {
        //black
        for (int i = a7; i <= h7; i++) {
            board.at(i) = unique_ptr<Piece>(make_unique<Pawn>(false));
        }
        board.at(a8) = unique_ptr<Piece>(make_unique<Rook>(false));
        board.at(b8) = unique_ptr<Piece>(make_unique<Knight>(false));
        board.at(c8) = unique_ptr<Piece>(make_unique<Bishop>(false));
        board.at(d8) = unique_ptr<Piece>(make_unique<Queen>(false));
        board.at(e8) = unique_ptr<Piece>(make_unique<King>(false));
        board.at(f8) = unique_ptr<Piece>(make_unique<Bishop>(false));
        board.at(g8) = unique_ptr<Piece>(make_unique<Knight>(false));
        board.at(h8) = unique_ptr<Piece>(make_unique<Rook>(false));

        //white
        for (int i = a2; i <= h2; i++) {
            board.at(i) = unique_ptr<Piece>(make_unique<Pawn>(false));
        }
        board.at(a1) = unique_ptr<Piece>(make_unique<Rook>(true));
        board.at(b1) = unique_ptr<Piece>(make_unique<Knight>(true));
        board.at(c1) = unique_ptr<Piece>(make_unique<Bishop>(true));
        board.at(d1) = unique_ptr<Piece>(make_unique<Queen>(true));
        board.at(e1) = unique_ptr<Piece>(make_unique<King>(true));
        board.at(f1) = unique_ptr<Piece>(make_unique<Bishop>(true));
        board.at(g1) = unique_ptr<Piece>(make_unique<Knight>(true));
        board.at(h1) = unique_ptr<Piece>(make_unique<Rook>(true));
    }
}

//finds the king location
int Board::getKingIndex(bool side) {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;
            if (!(square & 0x88)) {
                if (board.at(square)->side == side && board.at(square)->unicode == "♔") {
                    return square;
                }
            }
        }
    }
    return -1;
}

//not yet implemented
void Board::move(int init_pos, int target_pos) {
    //set piece of target square to piece of initial square
    *board.at(target_pos) = *board.at(init_pos);
    //alter hasMoved value
    board.at(target_pos)->hasMoved = true;
    //set initial position to empty
    board.at(init_pos) = unique_ptr<Piece>(make_unique<Empty>(true));
}

//prints unicode representation of board
void Board::printBoard() {
    // print new line
    printf("\n");

    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;

            if (file == 0) {
                printf(" %d  ", 8 - rank);
            }
            // if square is on board
            if (!(square & 0x88)) {
                cout << board[square]->unicode << " ";
            }
        }
        printf("\n");
    }
    printf("\n    a b c d e f g h\n");
}

//prints attacked squares of a side as x
void Board::printAttackedSquares(bool side) {
    vector<int> attacked_squares = getAttackedSquares(side);
    printf("\n");

    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;

            if (file == 0) {
                printf(" %d  ", 8 - rank);
            }
            if (!(square & 0x88)) {
                if (find(attacked_squares.begin(), attacked_squares.end(), square) != attacked_squares.end()) {
                    printf("x ");
                } else {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
    printf("\n    a b c d e f g h\n");
}

//find the attacked squares of a side
vector<int> Board::getAttackedSquares(bool side) {
    vector<int> all_attacked_squares;
    vector<int> piece_attacked_squares;
//
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;
            if (!(square & 0x88)) {
                if (board.at(square)->side == side) {
                    piece_attacked_squares = board.at(square)->getAttackedSquares(square);
                    all_attacked_squares.insert(end(all_attacked_squares), begin(piece_attacked_squares),
                                                end(piece_attacked_squares));
                }
            }
        }
    }
    return all_attacked_squares;
}

//determines legal moves for given side
map<int, vector<int>> Board::getLegalMoves(bool side) {
    map<int, vector<int>> legal_moves;
    vector<int> opp_attacked_squares = getAttackedSquares(!side);
    int king_index = getKingIndex(side);

    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;
            if (!(square & 0x88)) {
                if (board.at(square)->side == side) {
                    unique_ptr<Piece> &temp = board.at(square);

                }
            }
        }
    }

    return legal_moves;
}



