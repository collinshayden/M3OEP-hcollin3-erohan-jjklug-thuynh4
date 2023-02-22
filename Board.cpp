//
// Created by Hayden Collins on 2/3/23.
//
#include "Board.h"
#include <stdio.h>
#include "pieces/pieceClasses.h"

using namespace std;

//enum Pieces {e, P, R, N, B, Q, K, p, r, n, b, q, k};

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
char *unicode_pieces[] = {".", "♙", "♘", "♗", "♖", "♕", "♔", "♟︎", "♞", "♝", "♜", "♛", "♚"};

int o = 0x88;

Board::Board() {
//    board = {
//      r, n, b, q, k, b, n, r, o, o, o, o, o, o, o, o,
//      p, p, p, p, p, p, p, p, o, o, o, o, o, o, o, o,
//      e, e, e, e, e, e, e, e, o, o, o, o, o, o, o, o,
//      e, e, e, e, e, e, e, e, o, o, o, o, o, o, o, o,
//      e, e, e, e, e, e, e, e, o, o, o, o, o, o, o, o,
//      e, e, e, e, e, e, e, e, o, o, o, o, o, o, o, o,
//      P, P, P, P, P, P, P, P, o, o, o, o, o, o, o, o,
//      R, N, B, Q, K, B, N, R, o, o, o, o, o, o, o, o,
//    };
        board = {
            Rook(false), Knight(false), Bishop(false), Queen(false), King(false), Bishop(false), Knight(false), Rook(false), Empty,
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
                printf(" %s", unicode_pieces[board[square]]);
            }
        }
        printf("\n");
    }
    printf("\n     a b c d e f g h\n");
}

void Board::printAttackedSquares(bool side) {
    
}

vector<int> Board::getAttackedSquares(bool side) {
    return vector<int>();
}
