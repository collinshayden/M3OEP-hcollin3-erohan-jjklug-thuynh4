**Open Ended Project - Chess - Hayden Collins, Evan Rohan, Jack Klug, Hoang Huynh**

**Summary**
We are making chess for the module 3 open ended project. This is a continuation of Hayden's M2OEP. We are using a board representation technique called 0x88. The general idea is to have 
a 1x128 vector, where you can imagine your normal 8x8 playing board and then another empty 8x8 grid next to it. Each 8 indices in the 
vector alternates between a normal rank (horizontal row on a chess board) and 8 empty squares. The primary advantage to this representation
is that we can do a one line check to see if a given square index is on or off the 8x8 playing space. This is done by doing a bitwise 
and of the index and the hex value 0x88 (hence the representation name) which will return 0 if it is on the board, and 1 if off. This
representation also makes finding attacked squares and thus legal moves far easier from a programming perspective than the intuitive 
2d array representation. 
We have greatly expanded the project this module, fully implementing short algebraic move input validation, legal move validation, 
captures, promotion, castling, stalemate, checkmate, FEN board state representation, pass and play game functionality, debug options to test features, 
functions to get and set the board state from custom positions, and computer moves with Stockfish 15.
via Python,

**Bugs**
No current bugs. 

**Future Work**
There is still much to do. Next module, graphics will focus on graphics. More engine functionality, perhaps web server implementations, 
custom engines, refactoring a few things, etc are all options for future work. 

**Grade**
60 points for complexity. I think this project is vastly more complex than the expectations of an OEP. 
20 points for other programming language (Python)
10 points for command line input/output interfacing with Python. We are sending info to the Stockfish Python module each move via command line, 
then the Python script writes the computer move to a file, then we read the file to receive input. 
Total: 90 points. 

**References**
https://en.wikipedia.org/wiki/Board_representation_(computer_chess)
https://peterellisjones.com/posts/generating-legal-chess-moves-efficiently/
https://www.youtube.com/watch?v=n5vV4u-nKtw
https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation
https://stockfishchess.org/
https://pypi.org/project/stockfish/