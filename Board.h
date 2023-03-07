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

    int fileToInt(char c);

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


};


#endif //M1OEP_HCOLLIN3_BOARD_H
