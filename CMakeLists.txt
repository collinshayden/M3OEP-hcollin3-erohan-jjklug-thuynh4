cmake_minimum_required(VERSION 3.23)
project(M1OEP_hcollin3)

set(CMAKE_CXX_STANDARD 14)

add_executable(M1OEP_hcollin3
        main.cpp Board.cpp Board.h Piece.cpp Piece.h pieces/Rook.cpp pieces/Rook.h pieces/Bishop.cpp pieces/Bishop.h pieces/Pawn.cpp pieces/Pawn.h pieces/Queen.cpp pieces/Queen.h pieces/King.cpp pieces/King.h pieces/Knight.cpp pieces/Knight.h pieces/pieceClasses.h pieces/Empty.cpp pieces/Empty.h)
