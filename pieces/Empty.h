//
// Created by Hayden Collins on 2/21/23.
//

#ifndef M1OEP_HCOLLIN3_EMPTY_H
#define M1OEP_HCOLLIN3_EMPTY_H

#include "../Piece.h"

//Piece class to represent empty squares
class Empty : public Piece {
public:
    Empty(bool side);
    vector<int> getAttackedSquares(int initial_pos) override;
};


#endif //M1OEP_HCOLLIN3_EMPTY_H
