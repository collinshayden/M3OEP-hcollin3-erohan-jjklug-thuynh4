//Hayden Collins, OEP
#include "Board.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main () {
    Board board;
    board.printBoard();
//    board.printAttackedSquares(false);
    vector<int> v = board.getAttackedSquares(false);
    cout << v.size() << endl;
    return 0;
}
