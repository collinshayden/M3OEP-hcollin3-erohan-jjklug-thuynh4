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
    Board();

    //Getter
    vector<int> getBoardState();

    //Setter
    void move();

    void printBoard();


private:
    vector<int> board;

    void printAttackedSquares(bool side);
};


#endif //M1OEP_HCOLLIN3_BOARD_H
