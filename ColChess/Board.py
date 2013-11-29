#The game board
# defines the game components and display routines

import math
import curses
import Tiles as T
import Players as P

class Board:
    B = []
    '''The game board, defaults to 9x9'''
    players = []
    '''The list of players; Initially 2, perhaps more in the future'''
    current_player = None
    '''Who is playing now?'''
    
    def init(self, BOARD_SIZE, START_PLAYER):
        '''Initialize the board
        BOARD_SIZE: size of the square board
        START_PLAYER: who starts(0: Nature; 1: Industry)'''
        for i in range(BOARD_SIZE):
            self.B.append([])
            for j in range(BOARD_SIZE):
                self.B[i].append(T.Tile())
        
        for p in ["Nature","Industry"]:
            self.players.append([P.playerClass[p]()])
        self.current_player = self.players[START_PLAYER]
    
    def draw(self, win):
        '''Draws the board on the specified curses window'''
        h,w = win.getmaxyx()
        x0 = w/2 - len(self.B)/2
        win.addstr(1,1,str(x0))
        y0 = h/2 - len(self.B)/2
        win.addstr(2,1,str(y0))
        for y in range(len(self.B)):
            for x in range(len(self.B)):
                win.addstr(y0+y, x0+x, str(self.B[y][x]))
    
    def __repr__(self):
        '''String representation of the game's current status'''
        R = ""
        for row in self.B:
            for cell in row:
                R += str(cell)
            R += "\n"
        
        R += "\n"
        R += "Player 1: {}\n".format(self.players[0])
        R += "Player 2: {}\n".format(self.players[1])
        return R
