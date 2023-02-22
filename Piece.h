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
    Piece(bool side);

    virtual vector<int> getMoves(int index);

private:
    bool side; // 1 for white, 0 for black
    bool hasMoved;
    vector<int> moves;


};


#endif //M1OEP_HCOLLIN3_PIECE_H
