//
// Created by Hayden Collins on 2/3/23.
//

#ifndef M1OEP_HCOLLIN3_PIECE_H
#define M1OEP_HCOLLIN3_PIECE_H
#include "string"
#include "vector"

using namespace std;

class Piece {

public:
    Piece(int side);

    virtual vector<int> getAttackedSquares(int index);

    int side; // 1 for white, 0 for black, -1 for empty/offboard
    bool hasMoved;
    int value;
    string unicode;
};


#endif //M1OEP_HCOLLIN3_PIECE_H
