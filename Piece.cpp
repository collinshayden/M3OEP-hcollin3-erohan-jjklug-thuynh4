//
// Created by Hayden Collins on 2/3/23.
//

#include "Piece.h"

using namespace std;

Piece::Piece(bool side) {
    hasMoved = false;
    side = side;
}

vector<int> Piece::getMoves(int index) {
    return vector<int>{-1};
}

