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
    Piece();
    Piece(bool side);

    virtual vector<int> getMoves(int index);

    bool side; // 1 for white, 0 for black
    bool hasMoved;
    int value;
    string unicode;
};


#endif //M1OEP_HCOLLIN3_PIECE_H
