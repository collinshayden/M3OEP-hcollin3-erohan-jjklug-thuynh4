//Hayden Collins, OEP
#include "Board.h"
#include <iomanip>
#include <iostream>
#include "pieces/pieceClasses.h"

using namespace std;

// square encoding
enum squares {
    a8 = 0,   b8, c8, d8, e8, f8, g8, h8,
    a7 = 16,  b7, c7, d7, e7, f7, g7, h7,
    a6 = 32,  b6, c6, d6, e6, f6, g6, h6,
    a5 = 48,  b5, c5, d5, e5, f5, g5, h5,
    a4 = 64,  b4, c4, d4, e4, f4, g4, h4,
    a3 = 80,  b3, c3, d3, e3, f3, g3, h3,
    a2 = 96,  b2, c2, d2, e2, f2, g2, h2,
    a1 = 112, b1, c1, d1, e1, f1, g1, h1, no_sq
};

int main () {
    cout << "Standard setup" << endl;
    Board board(true);
    board.printBoard();
    cout <<"Attacked squares" << endl;
    board.printAttackedSquares(true);

    Knight k(false);
    vector<int> k_attacked_squares = k.getAttackedSquares(d4);
    cout << "Knight on d4 attacks ";
    for (int i = 0; i < k_attacked_squares.size(); i++) {
        cout << k_attacked_squares.at(i) << ", ";
    }
    cout <<endl<<endl;

    Rook r(false);
    vector<int> r_attacked_squares = r.getAttackedSquares(d4);
    cout << "Rook on d4 attacks ";
    for (int i = 0; i < r_attacked_squares.size(); i++) {
        cout << r_attacked_squares.at(i) << ", ";
    }
    cout <<endl<<endl;

    Queen q(false);
    vector<int> q_attacked_squares = q.getAttackedSquares(d4);
    cout << "Queen on d4 attacks ";
    for (int i = 0; i < q_attacked_squares.size(); i++) {
        cout << q_attacked_squares.at(i) << ", ";
    }
    cout <<endl<<endl;

    Bishop b(false);
    vector<int> b_attacked_squares = b.getAttackedSquares(d4);
    cout << "Bishop on d4 attacks ";
    for (int i = 0; i < b_attacked_squares.size(); i++) {
        cout << b_attacked_squares.at(i) << ", ";
    }
    cout <<endl<<endl;

    King ki(false);
    vector<int> ki_attacked_squares = ki.getAttackedSquares(d4);
    cout << "King on d4 attacks ";
    for (int i = 0; i < ki_attacked_squares.size(); i++) {
        cout << ki_attacked_squares.at(i) << ", ";
    }
    cout <<endl<<endl;

    return 0;
}
