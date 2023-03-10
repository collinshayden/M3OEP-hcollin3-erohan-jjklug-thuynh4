//
// Created by Hayden Collins on 2/21/23.
//

#ifndef M1OEP_HCOLLIN3_PAWN_H
#define M1OEP_HCOLLIN3_PAWN_H

#include "../Piece.h"

class Pawn : public Piece {
public:
    Pawn(bool side);

    vector<int> getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) override;
};

vector<int> getPawnPushes(int initial_pos, bool side, vector<unique_ptr<Piece>> &board);


#endif //M1OEP_HCOLLIN3_PAWN_H
