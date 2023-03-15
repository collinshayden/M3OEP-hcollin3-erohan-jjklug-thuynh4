//Hayden Collins, OEP
#include "Board.h"
#include <iomanip>
#include <iostream>
#include "pieces/pieceClasses.h"

using namespace std;

//TODO comments & readme
//TODO menu on program start (color to play, stockfish enabled, show legal moves, etc)
//TODO stockfish api via python
//TODO FEN get/set positions
//TODO print move disambiguating in printLegalMovesList
//TODO add promotion
//TODO save moves of the game in a list (needed for en passant and 50 move rule)
//TODO add en passant
//TODO add three fold repetition, insufficient material, 50 move rule draws
//TODO add test cases for all complex functionality

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
    cout << "Board" << endl;
    Board board(false);//true is standard setup, false is custom
    board.printBoard();
//    cout << endl << "Attacked Squares" << endl;
//    board.printAttackedSquares(true);
//    cout << endl << "Legal Moves" << endl;

    while(!board.game_end) {
        board.printLegalMovesList(board.side_to_move);
        vector<int> moves = board.getUserMove(board.side_to_move, cout, cin);
        board.makeUserMove(moves);
        board.printBoard();
//        board.checkGameEnd();
    }
}


