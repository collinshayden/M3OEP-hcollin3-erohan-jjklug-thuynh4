#imports
import sys
from Stockfish import stockfish
#get arguments from c++
FEN = sys.argv[1]
elo = sys.argv[2]

#put FEN into stockfish
stockfish.set_elo_rating(elo)
stockfish.set_fen_position(FEN)
#get best move
if(stockfish.is_fen_valid()):
    move = stockfish.get_best_move()
else:
    move = "invalid"

#return best move to c++
