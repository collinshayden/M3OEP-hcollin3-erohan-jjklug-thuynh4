//
// Created by Hayden Collins on 2/3/23.
//

#ifndef M1OEP_HCOLLIN3_PIECE_H
#define M1OEP_HCOLLIN3_PIECE_H

#include "string"
#include "vector"
#include <memory>

using namespace std;

class Piece {

public:
    /**
     * constructor
     * parent class
     * creates piece object
     * @param side
     */
    Piece(int side);
    /**
     * purely virtual method for attacked squares
     * @param index
     * @param board
     * @return vector of possible squares to move to
     */
    virtual vector<int> getAttackedSquares(int index, vector<unique_ptr<Piece>> &board);

    int side; // 1 for white, 0 for black, -1 for empty/offboard
    bool has_moved;
    string unicode;
    char piece_type; // P, K (king), Q, R, N (knight), B
};


#endif //M1OEP_HCOLLIN3_PIECE_H
