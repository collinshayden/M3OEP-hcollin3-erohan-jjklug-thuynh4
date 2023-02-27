**Open Ended Project - Chess - Hayden Collins**

**Summary**
I am making chess for my open ended project. I am using a board representation technique called 0x88. The general idea is to have 
a 1x128 vector, where you can imagine your normal 8x8 playing board and then another empty 8x8 grid next to it. Each 8 indices in the 
vector alternates between a normal rank (horizontal row on a chess board) and 8 empty squares. The primary advantage to this representation
is that we can do a one line check to see if a given square index is on or off the 8x8 playing space. This is done by doing a bitwise 
and of the index and the hex value 0x88 (hence the representation name) which will return 0 if it is on the board, and 1 if off. This
representation also makes finding attacked squares and thus legal moves far easier from a programming perspective than the intuitive 
2d array representation. 
I've currently got the attacked squares generation working for all the pieces, and printable with unicode chess piece symbols. 

**Bugs**
No current bugs. 

**Future Work**
There is still much to do. Firstly, I need to finish up legal moves. That shouldn't be too hard as getting the logic for attacked squares 
is the most work. Then adding user input and actual moves. Graphics, chess engines, etc are all possible expansions as well.

**Grade**
20*7=140 points for class inheritence. 40 points for complexity and usability. 10 points for testing. 190 points total.

**References**
https://en.wikipedia.org/wiki/Board_representation_(computer_chess)
https://peterellisjones.com/posts/generating-legal-chess-moves-efficiently/
https://www.youtube.com/watch?v=n5vV4u-nKtw