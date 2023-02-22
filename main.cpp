//Hayden Collins, OEP
#include "Board.h"
#include <iomanip>
#include <iostream>
#include "pieces/Knight.h"

using namespace std;

int main () {
    Board board;
    board.printBoard();
//    board.printAttackedSquares(false);
    vector<int> v = board.getAttackedSquares(false);
    Knight k(false);
//    vector<int> v = k.getAttackedSquares(51);
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }
    return 0;
}
