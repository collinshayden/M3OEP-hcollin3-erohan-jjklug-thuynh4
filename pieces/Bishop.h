//
// Created by Hayden Collins on 2/21/23.
//

#ifndef M1OEP_HCOLLIN3_BISHOP_H
#define M1OEP_HCOLLIN3_BISHOP_H

#include "../Piece.h"

class Bishop : public Piece {
public:
    Bishop(bool side);
    vector<int> getAttackedSquares(int initial_pos);

};


#endif //M1OEP_HCOLLIN3_BISHOP_H
