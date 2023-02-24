//
// Created by Hayden Collins on 2/3/23.
//
#include "Board.h"
#include <stdio.h>
#include "pieces/pieceClasses.h"
#include "string"
#include <iostream>

using namespace std;

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

Board::Board() {
//    board = {
//        Rook(false), Knight(false), Bishop(false), Queen(false), King(false), Bishop(false), Knight(false), Rook(false), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(),
//        Pawn(false), Pawn(false), Pawn(false), Pawn(false), Pawn(false), Pawn(false), Pawn(false), Pawn(false), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(),
//        Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(),
//        Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(),
//        Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(),
//        Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), Empty(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(),
//        Pawn(true), Pawn(true), Pawn(true), Pawn(true), Pawn(true), Pawn(true), Pawn(true), Pawn(true), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(),
//        Rook(true), Knight(true), Bishop(true), Queen(true), King(true), Bishop(true), Knight(true), Rook(true), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard(), OffBoard()
//    };

    board = {
            Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2),
            Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2),
            Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2),
            Empty(-1), Empty(-1), Empty(-1), Knight(1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2),
            Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2),
            Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2),
            Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2),
            Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), Empty(-1), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2), OffBoard(-2),

    };

}

vector<Piece> Board::getBoardState() {
    return board;
}

void Board::move() {

}

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
                    cout << board[square].unicode << " ";
            }
        }
        printf("\n");
    }
    printf("\n    a b c d e f g h\n");
}

void Board::printAttackedSquares(bool side) {
    vector<int> attacked_squares = getAttackedSquares(side);
    printf("\n");

    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;

            if (file == 0) {
                printf(" %d  ", 8 - rank);
            }
            if (find(attacked_squares.begin(), attacked_squares.end(), square) != attacked_squares.end()) {
                printf("x");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n    a b c d e f g h\n");
}

vector<int> Board::getAttackedSquares(bool side) {
    vector<int> all_attacked_squares;
    vector<int> piece_attacked_squares;

    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;
            if (!(square & 0x88)){
                if (board.at(square).side == side) {
                    cout << board.at(square).unicode << endl;
                    piece_attacked_squares = board.at(square).getAttackedSquares(square);
                    all_attacked_squares.insert(end(all_attacked_squares), begin(piece_attacked_squares),
                                                end(piece_attacked_squares));
                }
            }
        }
    }
    return all_attacked_squares;
}
