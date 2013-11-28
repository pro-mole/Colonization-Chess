#!/bin/python
'''Colonization Chess
A strategy game of conquest and exploitation of the battlefield'''
import sys
import curses
import getopt
import time

try:                                
    opts, args = getopt.getopt(sys.argv[1:], "hb:s:?", ["help","board_size=","start="])
except getopt.GetoptError:
    sys.exit(2)

#Default configurations
BOARD_SIZE=9
START_PLAYER=0

#print opts
#print args
for opt,arg in opts:
    if opt in ("-b","--board_size"):
        BOARD_SIZE = int(arg)
    if opt in ("-s","--start"):
        START_PLAYER = int(arg)
    if opt in ("-?","-h","help"):
        print "Colonization Chess\nHelp:"

import ColChess

winMain = curses.initscr()
curses.noecho()
curses.cbreak()
winMain.keypad(1)
curses.curs_set(0)

ColChess.board.init(BOARD_SIZE, START_PLAYER)
while not ColChess.endgame:
    winMain.clear()
    ColChess.board.draw(winMain)
    winMain.border()
    winMain.refresh()
    c = winMain.getch()
    if c == 27:
       ColChess.endgame = True

curses.curs_set(1)
winMain.clear()
winMain.keypad(0)
curses.nocbreak()
curses.echo()
curses.endwin()