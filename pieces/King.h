//
// Created by Hayden Collins on 2/21/23.
//

#ifndef M1OEP_HCOLLIN3_KING_H
#define M1OEP_HCOLLIN3_KING_H

#include "../Piece.h"

class King : public Piece {
public:
    /**
     * constructor
     * creates king object
     * @param side
     */
    King(bool side);
    /**
     * get attacked squares of the piece
     * @param initial_pos
     * @param board
     * @return vector of possible squares to move to
     */
    vector<int> getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) override;
};
/**
 * checks if a castle is possible
 * @param side
 * @param board
 * @param opp_attacked_squares
 * @return vector of boolean for king and queenside
 */
vector<bool> castleAvailability(bool side, vector<unique_ptr<Piece>> &board, vector<int> opp_attacked_squares);

#endif //M1OEP_HCOLLIN3_KING_H
