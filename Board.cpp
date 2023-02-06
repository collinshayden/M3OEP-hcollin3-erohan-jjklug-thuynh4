//
// Created by Hayden Collins on 2/3/23.
//

#include "Board.h"
enum Pieces {e, P, R, N, B, Q, K, p, r, n, b, q, k};
int o = 0x88;

Board::Board() {
    vector<int> board = {
      r, n, b, q, k, b, n, r, o, o, o, o, o, o, o, o,
      p, p, p, p, p, p, p, p, o, o, o, o, o, o, o, o,
      e, e, e, e, e, e, e, e, o, o, o, o, o, o, o, o,
      e, e, e, e, e, e, e, e, o, o, o, o, o, o, o, o,
      e, e, e, e, e, e, e, e, o, o, o, o, o, o, o, o,
      e, e, e, e, e, e, e, e, o, o, o, o, o, o, o, o,
      P, P, P, P, P, P, P, P, o, o, o, o, o, o, o, o,
      R, N, B, Q, K, B, N, R, o, o, o, o, o, o, o, o,
    };

}

std::vector<int> Board::getBoardState() {
    return board;
}

void Board::move() {

}
