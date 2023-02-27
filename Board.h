//
// Created by Hayden Collins on 2/3/23.
//

#ifndef M1OEP_HCOLLIN3_BOARD_H
#define M1OEP_HCOLLIN3_BOARD_H

#include "vector"
#include "Piece.h"

class Board {
public:
    // Constructor
    Board(bool setup);

    //Setter
    void move();

    int getKingIndex(bool side);

    vector<int> getAttackedSquares(bool side);

    vector<vector<int>> getLegalMoves(bool side);

    void printBoard();

    void printAttackedSquares(bool side);

private:
    vector<unique_ptr<Piece>> board;
};


#endif //M1OEP_HCOLLIN3_BOARD_H
