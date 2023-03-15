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

//setup constructor
Board::Board(bool setup) {
    //array to convert from index to cord
    side_to_move = true;
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
        board.at(f8) = unique_ptr<Piece>(make_unique<King>(false));
        board.at(a8) = unique_ptr<Piece>(make_unique<King>(true));
        board.at(d7) = unique_ptr<Piece>(make_unique<Pawn>(true));

    }
}

vector<unique_ptr<Piece>> Board::getBoard() {
    vector<unique_ptr<Piece>> board_copy;
    for (int i = 0; i < board.size(); i++) {
        bool side = board.at(i)->side;
        bool has_moved = board.at(i)->has_moved;
        char piece = board.at(i)->piece_type;

        board_copy.push_back(std::unique_ptr<Piece>(make_unique<Empty>(true)));
        setPiece(board_copy, i, side, has_moved, piece);

    }
    return board_copy;
}

bool Board::setBoard(vector<unique_ptr<Piece>> &new_board) {
    if (board.size() == new_board.size()) {
        for (int i = 0; i < new_board.size(); i++) {
            bool side = new_board.at(i)->side;
            bool has_moved = new_board.at(i)->has_moved;
            char piece = new_board.at(i)->piece_type;

            setPiece(board, i, side, has_moved, piece);
        }
        return true;
    }
    return false;
}

void
Board::setPiece(vector<unique_ptr<Piece>> &new_board, int index, bool side, bool has_moved, const char piece_type) {
    if (piece_type == 'E') {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Empty>(side));
    } else if (piece_type == 'P') {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Pawn>(side));
    } else if (piece_type == 'R') {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Rook>(side));
    } else if (piece_type == 'N') {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Knight>(side));
    } else if (piece_type == 'B') {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Bishop>(side));
    } else if (piece_type == 'Q') {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<Queen>(side));
    } else if (piece_type == 'K') {
        new_board.at(index) = std::unique_ptr<Piece>(make_unique<King>(side));
    }
    new_board.at(index)->has_moved = has_moved;
}

//moves a piece and sets original index to empty
void Board::move(int init_pos, int target_pos) {
    bool side = board.at(init_pos)->side;
    char piece = promotion ? promotion_type : board.at(init_pos)->piece_type;

    if (!(target_pos & 0x88)) {
        //checking for castles
        if (piece == 'K' && (init_pos == e1 || init_pos == e8)) {
            //map of rook destinations and origins based on new king position
            map<int, vector<int>> castle_sqs = {{g1, {f1,h1}}, {c1, {d1, a1}}, {g8, {f8, h8}}, {c8, {d8, a8}}};
            //our normal move will only function will only move the king, so below we additionally move the rook to the proper place
            if (castle_sqs.count(target_pos) != 0) {
                setPiece(board, castle_sqs.at(target_pos).at(0), side, true, 'R');
                setPiece(board, castle_sqs.at(target_pos).at(1), side, true, 'E');
            }
        }
        //set new pos to piece
        setPiece(board, target_pos, side, true, piece);

        //set initial position to empty
        setPiece(board, init_pos, side, true, 'E');
    }
}

//finds the king location
int Board::getKingIndex(bool side) {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 16; file++) {
            int square = rank * 16 + file;
            if (!(square & 0x88)) {
                if (board.at(square)->side == side && board.at(square)->piece_type == 'K') {
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
    if (!(!(init_pos & 0x88) && !(new_pos & 0x88))) return false;
    bool side = board.at(init_pos)->side;
    bool legal = false;
    vector<unique_ptr<Piece>> original_board = getBoard();

    //make that move on the board
    move(init_pos, new_pos);
    int king_index = getKingIndex(side);
    vector<int> opp_attacked_squares = getAttackedSquares(!side);

    //if the resulting position does not have the king in check, and it does not capture a piece of the same color, it is legal
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
                    if (board.at(square)->piece_type == 'P') {
                        for (int target_sq : piece_moves) {
                            if (board.at(target_sq)->piece_type != 'E') {
                                if (checkLegalMove(square, target_sq)) {
                                    legal_moves[square].push_back(target_sq);
                                }
                            }
                        }
                        //check pawn pushes
                        vector<int> pawn_pushes = getPawnPushes(square, side, board);
                        for (int target_sq : pawn_pushes) {
                            if (board.at(target_sq)->piece_type == 'E') {
                                if (checkLegalMove(square, target_sq)) {
                                    legal_moves[square].push_back(target_sq);
                                }
                            }
                        }
                    }
                    //for other pieces, simulate the move
                    else {
                        for (int target_sq : piece_moves) {
                            if (checkLegalMove(square, target_sq)) {
                                legal_moves[square].push_back(target_sq);
                            }
                        }
                    }
                    //castles
                    if (board.at(square)->piece_type == 'K') {
                        vector<bool> castles = castleAvailability(side, board, getAttackedSquares(!side));
                        int ks, qs;
                        ks = side ? g1 : g8;
                        qs = side ? c1 : c8;
                        if (castles.at(0)) {
                            if (checkLegalMove(square, ks)) {
                                legal_moves[square].push_back(ks);
                            }
                        }
                        if (castles.at(1)) {
                            if (checkLegalMove(square, qs)) {
                                legal_moves[square].push_back(qs);
                            }
                        }
                    }
                }
            }
        }
    }
    return legal_moves;
}

//takes a file character (a-h) and returns integer value (0 indexed)
int Board::charToInt(char c, bool file) {
    //all chars can be directly converted to integers. Subtracting 97 makes 'a' = 0. Subtracting 48 makes '0' = 0
    return file ? c - 97 : c - 48;
}

//see https://github.com/jacksonthall22/SAN-strings/blob/main/san_strings.txt as a reference for all possible legal short algebraic moves
vector<int> Board::getUserMove(bool side, ostream &outs, istream &ins) {
    //variables
    std::string input, original_input;
    bool legal = false;
    int file, rank, target_sq;

    outs << "Please enter a legal move: ";
    while (!legal) {
        legal = true;
        //rank/file specifier is for examples like dxc6 to specify the d pawn or promotion d7=Q or Rde7
        char piece_type = 'P', rank_file_specifier = '0'; promotion_type = 'E';
        //castle type is true if kingside, false if queenside
        bool castle = false, castle_kingside, promotion = false, capture = false, check = false, checkmate = false;
        std::stringstream ss;

        //ask for move
        getline(ins, input);

        //validate input length first
        while (input.size() < 2 || input.size() > 7) {
            outs << '"' << input << '"' << " is an invalid length. Please enter a legal move: ";
            getline(ins, input);
        }
        original_input = input;

        //linear search to set cases
        for (char c : input) {
            //no spaces allowed
            if (isspace(c)) {
                legal = false;
                break;
            }
            else if (c == 'x') capture = true;
            else if (c == '+') check = true;
            else if (c == '0' || c == '-' || c == 'O') castle = true;
            else if (c == '=') promotion = true;
            else if (c == '#') checkmate = true;
            else if (find(piece_types, piece_types+7, c) != piece_types+7) piece_type = c;

        }
        //remove check and checkmate symbols after setting flags
        while (input.back() == '+' || input.back() == '#') {
            input.pop_back();
        }

        if (promotion) {
            //cannot promote to king or pawn
            char promotion_types[4] = {'Q', 'R', 'N', 'B'};
            //if the last char is not a piecetype specifying promotion. not legal
            if (find(promotion_types, promotion_types + 4, input.back()) == promotion_types + 4) legal = false;
            else {
                //for example d7=Q
                promotion_type = input.back();
                piece_type = 'P';
                input.pop_back();
                if (input.back() != '=') legal = false;
                else {
                    input.pop_back();
                    ss << input.back();
                    ss >> rank;
                    input.pop_back();
                    file = charToInt(input.back(), true);
                    //for example dxe8=Q
                    if (capture) {
                        input.pop_back();
                        //input popped to dx
                        if (input.back() != 'x') legal = false;
                        else {
                            input.pop_back();
                            //rank specifier would be d in dxe8=Q
                            rank_file_specifier = input.back();
                        }
                    }
                }
            }
        } else if (castle) {
            //castle_kingside is true for kingside, false for queenside
            piece_type = 'K';
            if (input == "0-0" || input == "O-O") {
                castle_kingside = true;
                file = charToInt('g', true);
                rank = side ? 1 : 8;
            }
            else if (input == "0-0-0" || input == "O-O-O") {
                castle_kingside = false;
                file = charToInt('c', true);
                rank = side ? 1 : 8;
            }
            else {//no other legal castling options
                legal = false;
                castle = false;
            }
            
        } else {
            // rank and file will be last two chars
            ss << input.back();
            ss >> rank;
            input.pop_back();
            file = charToInt(input.back(), true);
            input.pop_back();
            if (capture) {
                //if a capture, the next char will be x
                if (input.back() != 'x') legal = false;
                else {
                    input.pop_back();
                    //if next char is a piece type, assign, otherwise it is a rank/file specifier
                    if (find(piece_types, piece_types + 7, input.back()) != piece_types + 7) piece_type = input.back();
                    else if (find(ranks, ranks + 8, input.back()) != ranks + 8 ||
                             find(files, files + 8, input.back()) != files + 8) {
                        rank_file_specifier = input.back();
                        input.pop_back();
                        //next will be a piece type unless pawn capture
                        if (find(piece_types, piece_types + 7, input.back()) != piece_types + 7)
                            piece_type = input.back();
                    } else legal = false;
                }
            } else {
                //if it is a pawn push, input will be empty after pulling out rank and file
                if (!input.empty()) {
                    //if it is not a capture, then it will be either a piece or rank/file disambiguation
                    if (find(piece_types, piece_types + 7, input.back()) != piece_types + 7) piece_type = input.back();
                    else if (find(ranks, ranks + 8, input.back()) != ranks + 8 ||
                             find(files, files + 8, input.back()) != files + 8) {
                        rank_file_specifier = input.back();
                        input.pop_back();
                        piece_type = input.back();
                    }
                    else legal = false; // if neither specifiers, illegal
                }
            }
        }

        if (legal) {
            //NOTE: the following target_sq assignment may look a bit weird. This is because the board representation has
            //a8 as index 0, with indices increasing left to right, top to bottom. However, in standard notation,
            //the ranks increase from whites side (a1 being the first rank) to blacks side (a8 being the 8th rank)
            //So the following line with (8-rank) simply converts the user given rank (e3 for example) to the rank
            //corresponding to the board representation
            target_sq = (8 - rank) * 16 + file;
            // check if on board
            if (!(target_sq & 0x88)) {
                map<int, vector<int>> legal_moves = getLegalMoves(side);
                //cycle through starting squares in legal moves
                for (const auto &elem: legal_moves) {
                    //search legal moves for pieces of the input type
                    if (board.at(elem.first)->piece_type == piece_type) {
                        //if the given target sq is in the piece's legal moves
                        if (find(elem.second.begin(), elem.second.end(), target_sq) != elem.second.end()) {
                            if (rank_file_specifier != '0') {
                                //
                                if (find(files, files+8, rank_file_specifier) != files+8) {
                                    if (square_to_coords[elem.first][0] == rank_file_specifier)
                                        return vector<int>{elem.first, target_sq};
                                }
                                else if (find(ranks, ranks+8, rank_file_specifier) != ranks+8) {
                                    if (square_to_coords[elem.first][1] == rank_file_specifier)
                                        return vector<int>{elem.first, target_sq};
                                }
                            }
                            else {
                                return vector<int>{elem.first, target_sq};
                            }

                        }
                    }
                }
            }
        }
        // if no return value, set to false and try again
        legal = false;
        ins.clear();
        outs << '"' << original_input << '"' << " is invalid. Please enter a legal move: ";
    }
}

bool Board::makeUserMove(vector<int> moves) {
    if (moves.size() == 2) {
        promotion = promotion_type != 'E';
        move(moves.at(0), moves.at(1));
        promotion_type = 'E'; promotion = false;
    } else {
        return false;
    }
    side_to_move = !side_to_move;
    return true;
}

void Board::checkGameEnd() {
    map<int, vector<int>> legal_moves = getLegalMoves(side_to_move);
    vector<int> attacked_squares = getAttackedSquares(!side_to_move);
    int king_location = getKingIndex(side_to_move);
    if (legal_moves.empty()) {
        if (find(attacked_squares.begin(), attacked_squares.end(), king_location) != attacked_squares.end()) {
            side_to_move ? cout << "Checkmate, Black wins." << endl : cout << "Checkmate, White wins." << endl;
        }
        else {
            cout << "Stalemate. The game is a draw." << endl;
        }
        game_end = true;
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
        for (int i : elem.second) {
            legal_destinations.push_back(i);
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

void Board::printLegalMovesList(bool side) {
    //TODO print move disambiguating
    cout << "printing legal moves" << endl;
    map<int, vector<int>> legal_moves = getLegalMoves(side);
    cout << "The legal moves in this position are: ";
    for (const auto &elem: legal_moves) {
        cout << endl;
        for (int i = 0; i < elem.second.size(); i++) {
            if (board.at(elem.first)->piece_type == 'P') {
                if (board.at(elem.second.at(i))->piece_type != 'E') {
                    cout << square_to_coords[elem.first][0] << "x" << square_to_coords[elem.second.at(i)] << ", ";

                } else {
                    cout << square_to_coords[elem.second.at(i)] << ", ";
                }
            } else if (board.at(elem.second.at(i))->piece_type != 'E') {
                cout << board.at(elem.first)->piece_type << "x" << square_to_coords[elem.second.at(i)] << ", ";
            } else {
                cout << board.at(elem.first)->piece_type << square_to_coords[elem.second.at(i)] << ", ";
            }
        }
    }
    cout << endl;
}