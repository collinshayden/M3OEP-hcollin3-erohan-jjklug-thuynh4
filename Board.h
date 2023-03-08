//
// Created by Hayden Collins on 2/3/23.
//

#ifndef M1OEP_HCOLLIN3_BOARD_H
#define M1OEP_HCOLLIN3_BOARD_H

#include "vector"
#include "Piece.h"
#include <map>

class Board {
public:
    bool side_to_move;
    bool game_end = false;


    // Constructor
    Board(bool setup);

    //Getters
    vector<unique_ptr<Piece>> getBoard();

    int getKingIndex(bool side);

    int charToInt(char c, bool file);

    vector<int> getUserMove(bool side, ostream &outs, istream &ins);

    //Setters
    bool setBoard(vector<unique_ptr<Piece>> &new_board);

    void setPiece(vector<unique_ptr<Piece>> &new_board, int index, bool side, bool hasMoved, const string &unicode);

    void move(int init_pos, int target_pos);

    bool makeUserMove(vector<int> moves);

    //logic for legality
    vector<int> getAttackedSquares(bool side);

    bool checkLegalMove(int init_pos, int new_pos);

    map<int, vector<int>> getLegalMoves(bool side);

    //prints
    void printBoard();

    void printAttackedSquares(bool side);

    void printLegalMoves(bool side);

    void printLegalMovesList(bool side);

private:
    vector<unique_ptr<Piece>> board;
    string square_to_coords[128] = {
            "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8", "i8", "j8", "k8", "l8", "m8", "n8", "o8", "p8",
            "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7", "i7", "j7", "k7", "l7", "m7", "n7", "o7", "p7",
            "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6", "i6", "j6", "k6", "l6", "m6", "n6", "o6", "p6",
            "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5", "i5", "j5", "k5", "l5", "m5", "n5", "o5", "p5",
            "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4", "i4", "j4", "k4", "l4", "m4", "n4", "o4", "p4",
            "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3", "i3", "j3", "k3", "l3", "m3", "n3", "o3", "p3",
            "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2", "i2", "j2", "k2", "l2", "m2", "n2", "o2", "p2",
            "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1", "i1", "j1", "k1", "l1", "m1", "n1", "o1", "p1"
    };
    char files[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char ranks[8] = {'1','2','3','4','5','6','7','8'};
    char piece_types[7] = {'E', 'P', 'R', 'N', 'B', 'Q', 'K'};

};


#endif //M1OEP_HCOLLIN3_BOARD_H
