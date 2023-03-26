# imports
import sys
from stockfish import Stockfish
stockfish = Stockfish(r'C:\Users\jackk\OneDrive\College\Spring Semester 2023\CS120\stockfish_15.1_win_x64_avx2\stockfish-windows-2022-x86-64-avx2.exe')

# get arguments from c++
FEN = sys.argv[1]
elo = sys.argv[2]

# remove underscores from FEN and replace them with spaces
FEN = FEN.replace('_', " ")

# put FEN into stockfish
stockfish.set_elo_rating(elo)
stockfish.set_fen_position(FEN)
# get best move
print(FEN)
if stockfish.is_fen_valid(FEN):
    move = stockfish.get_best_move()
else:
    move = "invalid"
# return best move to c++

print(move)

# save to file on way out and send back to c++
f = open("stockfishMove.txt", "w")
f.write(move)
f.close()