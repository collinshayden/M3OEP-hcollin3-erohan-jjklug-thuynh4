//
// Created by Hayden Collins on 2/3/23.
//
#include "Board.h"
#include <stdio.h>
#include "pieces/pieceClasses.h"
#include "string"
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

// enum that lets us easily convert between algebraic coordinates and indices
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

//array to convert from index to cord
string square_to_coords[] = {
        "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8", "i8", "j8", "k8", "l8", "m8", "n8", "o8", "p8",
        "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7", "i7", "j7", "k7", "l7", "m7", "n7", "o7", "p7",
        "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6", "i6", "j6", "k6", "l6", "m6", "n6", "o6", "p6",
        "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5", "i5", "j5", "k5", "l5", "m5", "n5", "o5", "p5",
        "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4", "i4", "j4", "k4", "l4", "m4", "n4", "o4", "p4",
        "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3", "i3", "j3", "k3", "l3", "m3", "n3", "o3", "p3",
        "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2", "i2", "j2", "k2", "l2", "m2", "n2", "o2", "p2",
        "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1", "i1", "j1", "k1", "l1", "m1", "n1", "o1", "p1"
};

Board::Board(bool setup) {
    //starting with empty board
    for (int j = 0; j < 128; j++) {
        board.push_back(std::unique_ptr<Piece>(make_unique<Empty>(true)));
    }

    //setting squares to proper pieces, otherwise empty (useful for debugging)
    if (setup) {
        //black
        for (int i = a7; i <= h7; i++) {
            board.at(i) = unique_ptr<Piece>(make_unique<Pawn>(false));
        }
        board.at(a8) = unique_ptr<Piece>(make_unique<Rook>(false));
        board.at(b8) = unique_ptr<Piece>(make_unique<Knight>(false));
        board.at(c8) = unique_ptr<Piece>(make_unique<Bishop>(false));
        board.at(d8) = unique_ptr<Piece>(make_unique<Queen>(false));
        board.at(e8) = unique_ptr<Piece>(make_unique<King>(false));
        board.at(f8) = unique_ptr<Piece>(make_unique<Bishop>(false));
        board.at(g8) = unique_ptr<Piece>(make_unique<Knight>(false));
        board.at(h8) = unique_ptr<Piece>(make_unique<Rook>(false));

        //white
        for (int i = a2; i <= h2; i++) {
            board.at(i) = unique_ptr<Piece>(make_unique<Pawn>(true));
        }
        board.at(a1) = unique_ptr<Piece>(make_unique<Rook>(true));
        board.at(b1) = unique_ptr<Piece>(make_unique<Knight>(true));
        board.at(c1) = unique_ptr<Piece>(make_unique<Bishop>(true));
        board.at(d1) = unique_ptr<Piece>(make_unique<Queen>(true));
        board.at(e1) = unique_ptr<Piece>(make_unique<King>(true));
        board.at(f1) = unique_ptr<Piece>(make_unique<Bishop>(true));
        board.at(g1) = unique_ptr<Piece>(make_unique<Knight>(true));
        board.at(h1) = unique_ptr<Piece>(make_unique<Rook>(true));
    } else {
        board.at(h2) = unique_ptr<Piece>(make_unique<Pawn>(true));
        board.at(a3) = unique_ptr<Piece>(make_unique<Rook>(false));
//        board.at(f8) = unique_ptr<Piece>(make_unique<Rook>(false));
    }
}

vector<unique_ptr<Piece>> Board::getBoard() {
    vector<unique_ptr<Piece>> board_copy;
    for (int i = 0; i < board.size(); i++) {
        bool side = board.at(i)->side;
        bool hasMoved = board.at(i)->hasMoved;
        string unicode = board.at(i)->unicode;

        board_copy.push_back(std::unique_ptr<Piece>(make_unique<Empty>(true)));
        setPiece(board_copy, i, side, hasMoved, unicode);

    }
    return board_copy;
}

bool Board::setBoard(vector<unique_ptr<Piece>> &new_board) {
    if (board.size() == new_board.size()) {
        for (int i = 0; i < new_board.size(); i++) {
            bool side = new_board.at(i)->side;
            bool hasMoved = new_board.at(i)->hasMoved;
            string unicode = new_board.at(i)->unicode;

            setPiece(board, i, side, hasMoved, unicode);
        }
        return true;
    }
    return false;
}

void Board::setPiece(vector<unique_ptr<Piece>> &new_board, int index, bool side, bool hasMoved, const string &unicode) {
    if (unicode == ".") {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Empty>(side));
    } else if (unicode == "♙") {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Pawn>(side));
    } else if (unicode == "♖") {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Rook>(side));
    } else if (unicode == "♘") {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Knight>(side));
    } else if (unicode == "♗") {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Bishop>(side));
    } else if (unicode == "♕") {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Queen>(side));
    } else if (unicode == "♔") {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<King>(side));
    }
    new_board.at(index)->hasMoved = hasMoved;
}

//moves a piece and sets original index to empty
void Board::move(int init_pos, int target_pos) {
    bool side = board.at(init_pos)->side;
    string unicode = board.at(init_pos)->unicode;

    if (!(target_pos & 0x88)) {
        //set new pos to piece
        setPiece(board, target_pos, side, true, unicode);
        //set initial position to empty
        setPiece(board, init_pos, true, true, ".");
    }
}

//finds the king location
int Board::getKingIndex(bool side) {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;
            if (!(square & 0x88)) {
                if (board.at(square)->side == side && board.at(square)->unicode == "♔") {
                    return square;
                }
            }
        }
    }
    return -1;
}

//find the attacked squares of a side
vector<int> Board::getAttackedSquares(bool side) {
    vector<int> all_attacked_squares;
    vector<int> piece_attacked_squares;
//
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;
            if (!(square & 0x88)) {
                if (board.at(square)->side == side) {
                    piece_attacked_squares = board.at(square)->getAttackedSquares(square, board);
                    all_attacked_squares.insert(end(all_attacked_squares), begin(piece_attacked_squares),
                                                end(piece_attacked_squares));
                }
            }
        }
    }
    return all_attacked_squares;
}

bool Board::checkLegalMove(int init_pos, int new_pos) {
    bool side = board.at(init_pos)->side;
    bool legal = false;
    vector<int> opp_attacked_squares = getAttackedSquares(!side);
    vector<unique_ptr<Piece>> original_board = getBoard();

    //make that move on the board
    move(init_pos, new_pos);
    int king_index = getKingIndex(side);

    //if the resulting position does not have the king in check, it is legal
    if (find(opp_attacked_squares.begin(), opp_attacked_squares.end(), king_index) == opp_attacked_squares.end()) {
        legal = true;
    }

    //reset board
    setBoard(original_board);
    return legal;
}

//determines legal moves for given side
map<int, vector<int>> Board::getLegalMoves(bool side) {
    map<int, vector<int>> legal_moves;

    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;

            if (!(square & 0x88)) {
                if (board.at(square)->side == side) {
                    //get the possible moves of the piece
                    vector<int> piece_moves = board.at(square)->getAttackedSquares(square, board);

                    //pawns move diagonally to capture only when there is a piece there
                    for (int i = 0; i < piece_moves.size(); i++) {
                        if (board.at(square)->unicode == "♙") {
                            if (board.at(piece_moves.at(i))->unicode != ".") {
                                if (checkLegalMove(square, piece_moves.at(i))) {
                                    legal_moves[square].push_back(piece_moves.at(i));
                                }
                            }
                            if (side) {
                                int target_sq = square - 16;//white pawn moves up one square
                                if (!(target_sq & 0x88) && board.at(target_sq)->unicode == ".") {
                                    if (checkLegalMove(square, target_sq)) {
                                        legal_moves[square].push_back(target_sq);
                                    }
                                    //if pawn hasn't moved, it can move two squares
                                    if (!board.at(square)->hasMoved) {
                                        target_sq -= 16; //two squares
                                        //if the pawn is on the second rank, target square is on board, and the squares in front are empty
                                        //pawn can move two squares
                                        if (square >= a2 && square <= h2 && !(target_sq & 0x88) &&
                                            board.at(target_sq)->unicode == ".") {
                                            if (checkLegalMove(square, target_sq)) {
                                                legal_moves[square].push_back(target_sq);
                                            }
                                        }
                                    }
                                }
                            } else {
                                int target_sq = square + 16;//white pawn moves up one square
                                if (!(target_sq & 0x88) && board.at(target_sq)->unicode == ".") {
                                    if (checkLegalMove(square, target_sq)) {
                                        legal_moves[square].push_back(target_sq);
                                    }
                                    //if pawn hasn't moved, it can move two squares
                                    if (!board.at(square)->hasMoved) {
                                        target_sq += 16; //two squares
                                        //if the pawn is on the second rank, target square is on board, and the squares in front are empty
                                        //pawn can move two squares
                                        if (square >= a7 && square <= h7 && !(target_sq & 0x88) &&
                                            board.at(target_sq)->unicode == ".") {
                                            if (checkLegalMove(square, target_sq)) {
                                                legal_moves[square].push_back(target_sq);
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (checkLegalMove(square, piece_moves.at(i))) {
                                legal_moves[square].push_back(piece_moves.at(i));
                            }
                        }
                    }
                }
            }
        }
    }
    return legal_moves;
}

vector<int> Board::getUserMove(bool side, ostream& outs, istream& ins) {
    //variables
    std::string input;
    bool good = false;
    int file;
    int rank;
    int tieFile = 0;
    bool castle = false;
    bool occupied = false;
    bool move;
    char piece;
    //ask for move
    outs << "Please enter a move: ";
    getline(ins,input);
    while(!good) {
        good = true;
        //check to see if it is a single input
        if(!input.empty()) {
            for (int i = 0; i < input.length(); ++i) {
                if (isspace(input.at(i)))
                    good = false;
            }
            if(!good){
                outs << "Invalid input. Enter a single move: ";
                ins.clear();
                getline(ins,input);
            }

        }
        else{
            good = false;
            outs << "No input. Enter a single move: ";
            ins.clear();
            getline(ins,input);
        }
        //pawn move
        if(input.length() == 2){
            if((input[0] != 'a' && input[0] != 'b' && input[0] != 'c' && input[0] != 'd' && input[0] != 'e' && input[0] != 'f' && input[0] != 'g' && input[0] != 'h') || (input[1] != '1' && input[1] != '2' && input[1] != '3' && input[1] != '4' && input[1] != '5' && input[1] != '6' && input[1] != '7' && input[1] != '8' )){
                good = false;
                outs << "Incorrect pawn move. please enter a legal move: ";
            }
        }//other move - castle
        else if(input.length() == 3) {
            if (((input[0] != 'N' && input[0] != 'B' && input[0] != 'R' && input[0] != 'Q' && input[0] != 'K') ||
                 (input[1] != 'a' && input[1] != 'b' && input[1] != 'c' && input[1] != 'd' && input[1] != 'e' &&
                  input[1] != 'f' && input[1] != 'g' && input[1] != 'h') ||
                 (input[2] != '1' && input[2] != '2' && input[2] != '3' && input[2] != '4' && input[2] != '5' &&
                  input[2] != '6' && input[2] != '7' && input[2] != '8')) && input != "O-O") {
                good = false;
                outs << "Incorrect move. please enter a legal move: ";
            }//capture or move
        }
        else if(input.length() == 4) {
            if((input[0] != 'N' && input[0] != 'B' && input[0] != 'R' && input[0] != 'Q' && input[0] != 'K' )||(input[1] != 'x' && input[1] != 'a' && input[1] != 'b' && input[1] != 'c' &&
                                                                                                                input[1] != 'd' && input[1] != 'e' && input[1] != 'f' && input[1] != 'g' && input[1] != 'h') ||
               (input[2] != 'a' && input[2] != 'b' && input[2] != 'c' && input[2] != 'd' && input[2] != 'e' &&
                input[2] != 'f' && input[2] != 'g' && input[2] != 'h') || (input[3] != '1' && input[3] != '2' &&
                                                                           input[3] != '3' && input[3] != '4' && input[3] != '5' && input[3] != '6' && input[3] != '7' &&
                                                                           input[3] != '8')) {
                good = false;
                outs << "Incorrect move. please enter a legal move: ";
            }
        }//castle or capture with R or B
        else if(input.length() == 5){
            if(input != "O-O-O" && ((input[0] != 'N' && input[0] != 'R' && input[1] != 'a' && input[1] != 'b' && input[1] != 'c' && input[1] != 'd' && input[1] != 'e' && input[1] != 'f' && input[1] != 'g' && input[1] != 'h') || (input[3] != 'x' &&input[3] != 'a' && input[3] != 'b' && input[3] != 'c' && input[3] != 'd' && input[3] != 'e' && input[3] != 'f' && input[3] != 'g' && input[3] != 'h' )||( input[4] != '1' && input[4] != '2' &&input[4] != '3' && input[4] != '4' && input[4] != '5' && input[4] != '6' && input[4] != '7' && input[4] != '8') )){
                good = false;
                outs << "Incorrect move. please enter a legal move: ";
            }

        }//if any single word that is not according lengths
        else{
            good = false;
            outs << "Incorrect move. please enter a legal move: ";
        }
        //if still good disect the move, and see if it is a possible move for the piece
        if(good){
            tieFile = 0;
            castle = false;
            occupied = false;
            move = false;
            std::stringstream ss;
            //pawn move
            if(input.length() == 2){
                piece = 'P';
                file = findFile(input[0]);
                ss << input[1];
                ss >> rank;
            }
                //regular move or castle
            else if(input.length() == 3){
                if(input == "O-O")
                    castle = true;
                else {
                    piece = input[0];
                    file = findFile(input[1]);
                    ss << input[2];
                    ss >> rank;
                }

            }
                //capture or tied move
            else if(input.length() == 4){
                if(input[1] == 'X'){
                    occupied = true;
                    file = findFile(input[2]);
                    piece = input[0];
                    ss << input[3];
                    ss >> rank;
                }
                else{
                    piece = input[0];
                    tieFile = findFile(input[1]);
                    file = findFile(input[2]);
                    ss << input[3];
                    ss >> rank;
                }
            }
                //castle or tied capture
            else if(input.length() == 5){
                if(input == "O-O-O"){
                    castle = true;
                }
                else{
                    piece = input[0];
                    tieFile = findFile(input[1]);
                    file = findFile(input[3]);
                    ss << input[4];
                    ss >> rank;
                }
            }
            //if castle, check if the castle is possible
            if(castle){
                //TODO castle
                //kingside
                if (input == "O-O"){
                    outs << "\nKingside Castle\n";
                    move = false;
                }
                    //queenside
                else{
                    outs << "\nQueenside Castle\n";
                    move = false;
                }
            }
                //else check if the legal move or capture can occur, if capture, then remove according piece from vector
            else{
                outs << "\nYou entered legal move: " << input << "\n";
                if(tieFile == 0 && (piece == 'N' || piece == 'K' || piece == 'Q' || piece == 'R' || piece == 'B')){
                    for(int i = 0; i < vector.size(); ++i){
                        if(vector[i]->getType() == piece){
                            if(vector[i]->move(Square(file,rank,occupied),board))
                                move = true;
                        }
                    }
                }
                else{
                    for(int i = 0; i < vector.size(); ++i){
                        if(vector[i]->getType() == piece && vector[i]->getSpace().getFile() == tieFile){
                            move = vector[i]->move(Square(file,rank,occupied),board);
                        }
                    }
                }

            }
            //if the move did not go through reprompt
            if(!move){
                good = false;
                cout << "Move was not in possible moves for the piece: ";
                ins.clear();
                getline(ins,input);
            }
            //make sure on the board
            //check if in check
            //moving out of a pin of the king
            //check if legal move for the piece - inheritance/put in move class/move returns true or false if move was ok, and if it failed redo validation
            //move

        }//reprompt for any one word answers that were not legal chess moves
        else{
            ins.clear();
            getline(ins,input);
        }
    }


}

//prints unicode representation of board
void Board::printBoard() {
    // print new line
    printf("\n");

    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;

            if (file == 0) {
                printf(" %d  ", 8 - rank);
            }
            // if square is on board
            if (!(square & 0x88)) {
                cout << board[square]->unicode << " ";
            }
        }
        printf("\n");
    }
    printf("\n    a b c d e f g h\n");
}

//prints attacked squares of a side as x
void Board::printAttackedSquares(bool side) {
    vector<int> attacked_squares = getAttackedSquares(side);
    printf("\n");

    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;

            if (file == 0) {
                printf(" %d  ", 8 - rank);
            }
            if (!(square & 0x88)) {
                if (find(attacked_squares.begin(), attacked_squares.end(), square) != attacked_squares.end()) {
                    printf("x ");
                } else {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
    printf("\n    a b c d e f g h\n");
}

void Board::printLegalMoves(bool side) {
    map<int, vector<int>> legal_moves = getLegalMoves(side);
    vector<int> legal_destinations;

    for (const auto &elem: legal_moves) {
        for (int i = 0; i < elem.second.size(); i++) {
            legal_destinations.push_back(elem.second.at(i));
        }
    }

    printf("\n");
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;

            if (file == 0) {
                printf(" %d  ", 8 - rank);
            }
            if (!(square & 0x88)) {
                if (find(legal_destinations.begin(), legal_destinations.end(), square) != legal_destinations.end()) {
                    printf("x ");
                } else {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
    printf("\n    a b c d e f g h\n");
}
















