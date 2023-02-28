//
// Created by Hayden Collins on 2/21/23.
//

#ifndef M1OEP_HCOLLIN3_ROOK_H
#define M1OEP_HCOLLIN3_ROOK_H

#include "../Piece.h"

class Rook : public Piece {
public:
    Rook(bool side);

    vector<int> getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) override;
};

#endif //M1OEP_HCOLLIN3_ROOK_H
