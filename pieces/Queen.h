//
// Created by Hayden Collins on 2/21/23.
//

#ifndef M1OEP_HCOLLIN3_QUEEN_H
#define M1OEP_HCOLLIN3_QUEEN_H

#include "../Piece.h"

class Queen : public Piece {
public:
    Queen(bool side);

    vector<int> getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) override;
};

#endif //M1OEP_HCOLLIN3_QUEEN_H
