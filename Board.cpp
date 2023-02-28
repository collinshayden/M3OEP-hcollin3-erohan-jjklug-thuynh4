//
// Created by Hayden Collins on 2/3/23.
//
#include "Board.h"
#include <stdio.h>
#include "pieces/pieceClasses.h"
#include "string"
#include <iostream>
#include <map>

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
        board.at(d5) = unique_ptr<Piece>(make_unique<Pawn>(true));
        board.at(e6) = unique_ptr<Piece>(make_unique<Rook>(false));
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

void Board::setPiece(vector<unique_ptr<Piece>> &new_board, int index, bool side, bool hasMoved, const string& unicode) {
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
                        }
                        else {
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

    for(const auto& elem : legal_moves)
    {
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














