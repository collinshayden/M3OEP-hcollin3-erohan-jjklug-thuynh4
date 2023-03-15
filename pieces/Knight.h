//
// Created by Hayden Collins on 2/21/23.
//

#ifndef M1OEP_HCOLLIN3_KNIGHT_H
#define M1OEP_HCOLLIN3_KNIGHT_H

#include "../Piece.h"

class Knight : public Piece {
public:
    /**
     * Knight constructor
     * creates knight piece
     * @param side
     */
    Knight(bool side);
    /**
     * gets attacked squares for the piece
     * @param initial_pos
     * @param board
     * @return vector of attacked squares
     */
    vector<int> getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) override;

};

#endif //M1OEP_HCOLLIN3_KNIGHT_H
