//
// Created by Hayden Collins on 2/3/23.
//

#ifndef M1OEP_HCOLLIN3_PIECE_H
#define M1OEP_HCOLLIN3_PIECE_H
#include "string"

using namespace std;

class Piece {

public:
    Piece();

    virtual vector<int> getMoves(int index);

private:
    bool isWhite;
    bool hasMoved;


};


#endif //M1OEP_HCOLLIN3_PIECE_H
