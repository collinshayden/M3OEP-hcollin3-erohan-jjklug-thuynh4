//
// Created by Hayden Collins on 2/21/23.
//

#ifndef M1OEP_HCOLLIN3_ROOK_H
#define M1OEP_HCOLLIN3_ROOK_H

#include "../Piece.h"

class Rook : public Piece {
public:
    /**
     * constructor
     * creates rook object
     * @param side
     */
    Rook(bool side);
    /**
     * gets attacked squares for the piece
     * @param initial_pos
     * @param board
     * @return vector of attacked squares
     */
    vector<int> getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) override;
};

#endif //M1OEP_HCOLLIN3_ROOK_H
