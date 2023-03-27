//Hayden Collins, OEP
#include "Board.h"
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include "pieces/pieceClasses.h"
#include <filesystem>
#include <sstream>
using namespace std;

//TODO print move disambiguating in printLegalMovesList
//TODO save moves of the game in a list (needed for en passant and 50 move rule)
//TODO add en passant
//TODO add three fold repetition, insufficient material, 50 move rule draws

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
string getMove(string FEN, int elo);

void passAndPlay(Board& board);

void stockFish(int elo,Board& board,bool side);

void regularPlay();

void tests();

int squareToInt(string square);

void makeCompMove(bool side,int elo,Board& board);

int main () {
    cout << "Welcome to Chess" << endl;
    Board board(true);
    regularPlay();
}

//this method gets the move for the opponent from the stockfish python library
string getMove(string FEN, int elo){
    //change based on computer type
    const string python = "python3";
    string command = python + " ../chess.py" + " "+ FEN +" "+ to_string(elo);
    //sends a command to the terminal
    system(command.c_str());
    string move;

    //gather move from file now
    ifstream stockMove;
    stockMove.open("../cmake-build-debug/stockfishMove.txt");
    //gets the move from a file written in python
    if(stockMove.is_open()){
        stockMove >> move;
    }
    stockMove.close();


    return move;
    //pull from file when getting move from stockfish
}

//pass and play game mode method
void passAndPlay(Board& board){
    vector<int> moves;
    bool side = true;
    //print board
    board.printBoard(true);
    //while loop to keep game running until somebody wins
    while(!board.game_end){
        if(side){
            cout << "White to move." << endl;
        }else{
            cout << "Black to move." << endl;
        }
        //gets user move
        moves = board.getUserMove(side, cout, cin);
        //makes the users move
        board.makeUserMove(moves);
        board.printBoard(true);
        board.checkGameEnd();
        side = !side;
    }
}

//side is player's side
void stockFish(int elo,Board& board,bool side){
    //based on who is what color determines what order moves are made in
    if(!side){
        makeCompMove(!side,elo,board);
    }

    while(!board.game_end) {
        //prints board
        board.printBoard(side);
        vector<int> moves = board.getUserMove(side, cout, cin);
        //makes the move for the user
        board.makeUserMove(moves);
        //prints board again
        board.printBoard(side);
        //checks if game is over
        board.checkGameEnd();
        if(!board.game_end) {
            //computer moves
            makeCompMove(!side, elo, board);
        }
        //checks if game is over
        board.checkGameEnd();
    }
}

//menu for user input and initial game setup
void regularPlay(){
    string line;
    stringstream ss;
    int elo;
    bool side;
    //sets up board
    Board board(true);
    cout << "Would you like to do pass and play or play a computer? (p/c) or (debug) to enter custom setups: " << endl;
    //gets user input
    getline(cin, line);
    //some input validation to choose what mode the user wants to play
    while(line != "p" && line != "c" && line != "debug"){
        cout << "please enter a valid option (p/c): " << endl;
        cin.clear();
        getline(cin,line);
    }
    if(line == "p"){
        passAndPlay(board);
    }
    else if (line == "debug") {
        tests();
    }
    else{
        cin.clear();
        cout << "Jack , elo 400" << endl;
        cout << "Evan, elo 1000" << endl;
        cout << "Hayden, elo 1700" << endl;
        cout << "Huong, elo 1900" << endl;
        //elo selector
        cout << "Who would you like to play against? (j,e,ha,hu) " << endl;
        getline(cin, line);
        while(line != "j" && line != "e" && line != "ha" && line != "hu"){
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
        cin.clear();
        //which side of the board would you like to play
        cout << "Would you like to play as white or black?(w/b) " << endl;
        getline(cin,line);
        while(line != "w" && line != "b"){
            //validation
            cout << "please enter a valid option (w/b): " << endl;
            cin.clear();
            getline(cin,line);
        }
        if(line == "w"){
            side = true;
        }else{
            side = false;
        }
        stockFish(elo,board,side);
    }
}

void tests() {
    string setup;
    vector<string> setups = {"pin", "legality", "checkmate", "promotion", "castles", "stalemate", "disambiguate"};
    cout << "Choose a setup: 'pin', 'legality' ,'checkmate', 'promotion', 'castles', 'stalemate', 'disambiguate'" << endl;
    getline(cin,setup);
    while (find(setups.begin(), setups.end(), setup) == setups.end()) {
        cout << setup << " is invalid. Choose from: 'pin', 'legality', 'checkmate', 'promotion', 'castles', 'stalemate', 'disambiguate'" << endl;
        getline(cin,setup);
    }
    Board board(setup);
    board.printBoard(true);
    if (setup == "checkmate") {
        cout << "Enter Rh8 to demonstrate checkmate." << endl;
    }
    else if (setup == "stalemate") {
        cout << "Enter Qb6 to demonstrate stalemate." << endl;
    }
    else if (setup == "promotion") {
        cout << "Enter 'a8=Q', 'a8=R', 'a8=N', or 'a8=B' to demonstrate promotion." << endl;
    }
    else if (setup == "disambiguate") {
        cout << "Enter 'Rbd5' or 'Rgd5' to demonstrate disambiguation." << endl;
    }
    else if (setup == "castles") {
        cout << "Enter '0-0' or '0-0-0' to demonstrate castling." << endl;
    }
    else if (setup == "legality") {
        cout << "The Black rook on f8 prevents White from moving into check on f1 or f2. ";
        board.printLegalMovesList(board.side_to_move);
    }
    else if (setup == "pin") {
        cout << "The Black rook on e8 prevents White from moving the knight, it is pinned to the king. ";
        board.printLegalMovesList(board.side_to_move);
    }
    else {
        cout << "Invalid setup type" << endl;
    }
    while (!board.game_end) {
        vector<int> moves = board.getUserMove(board.side_to_move, cout, cin);
        board.makeUserMove(moves);
        board.printBoard(true);
        board.checkGameEnd();
    }
}

//method to convert a user inputted move into the new index in tbe board
int squareToInt(string square){
    int file= square[0]-97;
    int rank = square[1]-48;
    //calculation to get new index in the 0x88 board
    return (8 - rank) * 16 + file;
}

//makes the computer move
void makeCompMove(bool side, int elo, Board& board){
    string opp_move;
    int init;
    int target;
    //gets move from stockfish
    opp_move = getMove(board.getFEN(side), elo);
    //gets initial pos of piece
    init = squareToInt(opp_move.substr(0,2));
    //gets target position for piece
    target = squareToInt(opp_move.substr(2,2));
    //moves piece for bot
    board.move(init,target);
}
