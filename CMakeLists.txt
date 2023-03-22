cmake_minimum_required(VERSION 3.23)
project(M3OEP_hcollin3-erohan-jjklug-thuynh4)

set(CMAKE_CXX_STANDARD 14)

add_executable(M3OEP_hcollin3-erohan-jjklug-thuynh4
        main.cpp
        Board.h
        Piece.h
        pieces/Rook.h
        pieces/Bishop.h
        pieces/Pawn.h
        pieces/Queen.h
        pieces/King.h
        pieces/Knight.h
        pieces/pieceClasses.h
        pieces/Empty.h)
