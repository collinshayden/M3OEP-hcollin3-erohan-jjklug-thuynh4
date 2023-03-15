//Hayden Collins, OEP
#include "Board.h"
#include <iomanip>
#include <iostream>
#include "pieces/pieceClasses.h"
#include <filesystem>
#include <sstream>
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
string getMove(string FEN, string elo,Board board);
void passAndPlay();

void stockFish(int elo);

int main () {
    string line;
    stringstream ss;
    int elo;
    cout << "Welcome to Chess" << endl;
    cout << "would you like to do pass and play or play a computer? (p/c) " << endl;
    getline(cin, line);
    while(line != "p" || line != "c"){
        cout << "please enter a valid option (p/c): " << endl;
        cin.clear();
        getline(cin,line);
    }
    if(line == "p"){
        passAndPlay();
    }else{
        cin.clear();
        cout << "Jack , elo 400" << endl;
        cout << "Evan, elo 1000" << endl;
        cout << "Hayden, elo 1700" << endl;
        cout << "Huong, elo 1900" << endl;
        cout << "Who would you like to play against? (j,e,ha,hu) " << endl;
        getline(cin, line);
        while(line != "j" || line != "e" || line != "ha" || line != "hu"){
            cout << "please enter a valid option (j,e,ha,hu): " << endl;
            cin.clear();
            getline(cin,line);
        }
        if(line == "j"){
            elo = 400;
        }else if(line == "e"){
            elo = 1000;
        }else if(line == "ha"){
            elo = 1700;
        }else{
            elo = 2000;
        }
        //run stockfish option
        stockFish(elo);
    }
    cout << "Board" << endl;
    Board board(false);//true is standard setup, false is custom
    board.printBoard(true);
//    cout << endl << "Attacked Squares" << endl;
//    board.printAttackedSquares(true);
//    cout << endl << "Legal Moves" << endl;

    while(!board.game_end) {
        board.printLegalMovesList(board.side_to_move);
        vector<int> moves = board.getUserMove(board.side_to_move, cout, cin);
        board.makeUserMove(moves);
        board.printBoard(true);
//        board.checkGameEnd();
    }
}


}

string getMove(string FEN, string elo, Board board){
    //change based on computer type
    const string python = "python";
    string command = python + "../stockfish.py" + FEN + elo;
    system(command.c_str());
    //get return from python?
}

void passAndPlay(){

}

void stockFish(int elo){

}