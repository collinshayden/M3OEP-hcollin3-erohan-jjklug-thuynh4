//
// Created by Hayden Collins on 2/21/23.
//

#ifndef M1OEP_HCOLLIN3_PAWN_H
#define M1OEP_HCOLLIN3_PAWN_H

#include "../Piece.h"

class Pawn : public Piece {
public:
    /**
     *constructor
     * creates pawn object
     * @param side
     */
    Pawn(bool side);
    /**
     * for captures with pawns
     * @param initial_pos
     * @param board
     * @return vector of possible squares attacked
     */
    vector<int> getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) override;
};
/**
 * for moving pawns forward
 * @param initial_pos
 * @param side
 * @param board
 * @return moves of possible moves forward - 1 or 2 squares
 */
vector<int> getPawnPushes(int initial_pos, bool side, vector<unique_ptr<Piece>> &board);


#endif //M1OEP_HCOLLIN3_PAWN_H
