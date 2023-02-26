//Hayden Collins, OEP
#include "Board.h"
#include <iomanip>
#include <iostream>
#include "pieces/Queen.h"

using namespace std;

int main () {
    Board board;
    board.printBoard();
//    board.printAttackedSquares(true);

    Queen q = Queen(1);

    return 0;
}
