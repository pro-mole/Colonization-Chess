'''Players module'''

from Player import *

from PlayerNature import *
from PlayerIndustry import *

def getPlayerClass(name):
    if name == "Nature":
        return PlayerNature
    elif name == "Industry":
        return PlayerIndustry
    else:
        return Player
