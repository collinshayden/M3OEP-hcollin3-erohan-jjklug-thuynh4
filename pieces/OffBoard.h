//
// Created by Hayden Collins on 2/22/23.
//

#ifndef M1OEP_HCOLLIN3_OFFBOARD_H
#define M1OEP_HCOLLIN3_OFFBOARD_H


#include "../Piece.h"

class OffBoard : public Piece {
public:
    OffBoard();
    vector<int> getAttackedSquares(int initial_pos);
};


#endif //M1OEP_HCOLLIN3_OFFBOARD_H
