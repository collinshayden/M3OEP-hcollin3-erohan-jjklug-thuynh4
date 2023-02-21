//
// Created by Hayden Collins on 2/3/23.
//

#include "Piece.h"

using namespace std;

Piece::Piece(bool white) {
    hasMoved = false;
    isWhite = white;
}

vector<int> Piece::getMoves(int index) {
    return vector<int>{-1};
}

