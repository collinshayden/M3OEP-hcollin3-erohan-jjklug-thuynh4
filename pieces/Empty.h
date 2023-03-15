//
// Created by Hayden Collins on 2/21/23.
//

#ifndef M1OEP_HCOLLIN3_EMPTY_H
#define M1OEP_HCOLLIN3_EMPTY_H

#include "../Piece.h"

//Piece class to represent empty squares
class Empty : public Piece {
public:
    /**
     * constructor
     * creates an empty square
     * @param side
     */
    Empty(bool side);
    /**
     * gets attacked squares - does nothing
     * @param initial_pos
     * @param board
     * @return empty vector
     */
    vector<int> getAttackedSquares(int initial_pos, vector<unique_ptr<Piece>> &board) override;
};


#endif //M1OEP_HCOLLIN3_EMPTY_H
