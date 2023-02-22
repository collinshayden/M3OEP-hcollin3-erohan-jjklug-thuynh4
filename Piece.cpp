//
// Created by Hayden Collins on 2/3/23.
//

#include "Piece.h"

using namespace std;
Piece::Piece() {
    hasMoved = false;
}

Piece::Piece(bool isWhite) {
    hasMoved = false;
    side = isWhite;
}

vector<int> Piece::getAttackedSquares(int index) {
    return vector<int>{};
}

//vector<int> Piece::getAttackedSquares(int index) {
//    return vector<int>(-1);
//}


