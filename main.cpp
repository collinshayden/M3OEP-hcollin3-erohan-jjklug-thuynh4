//Hayden Collins, OEP
#include "Board.h"
#include <iomanip>
#include <iostream>
#include "pieces/King.h"

using namespace std;

int main () {
    Board board;
    board.printBoard();
    board.printAttackedSquares(true);
    King k = King(1);
    vector<int> v = k.getAttackedSquares(51);
    cout << v.size() << endl;
    return 0;
}
