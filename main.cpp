//Hayden Collins, OEP
#include "Board.h"
#include <iomanip>
#include <iostream>
#include "pieces/Knight.h"

using namespace std;

int main () {
    Board board;
    board.printBoard();
    board.printAttackedSquares(true);
    vector<int> v = board.getAttackedSquares(true);
    return 0;
}
