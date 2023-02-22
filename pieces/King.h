//
// Created by Hayden Collins on 2/21/23.
//

#ifndef M1OEP_HCOLLIN3_KING_H
#define M1OEP_HCOLLIN3_KING_H

#include "../Piece.h"

class King : public Piece{
public:
    King(bool side);
    vector<int> getAttackedSquares(int initial_pos);
};


#endif //M1OEP_HCOLLIN3_KING_H
