SHELL=/bin/bash
PATH=/bin:/usr/bin:/usr/local/bin
OS=mac
INC=./inc
LIB=./lib
SRC=./src
OBJ=./obj

SDLFLAGS=`sdl2-config --cflags`
SDLLIBS=`sdl2-config --libs`

CC=g++ -c -Wall -I$(INC) $(SDLFLAGS)
CL=g++ -Wall -L$(LIB)

ALL_OBJ=$(OBJ)/colchess.o $(OBJ)/board.o $(OBJ)/player.o $(OBJ)/playerIndustry.o $(OBJ)/playerNature.o $(OBJ)/tile.o $(OBJ)/tileBase.o $(OBJ)/tileStructure.o $(OBJ)/tileTerrain.o $(OBJ)/tileUnit.o 

EXEC=colchess
VMAJ=0
VMIN=1
REL=1
EXECNAME=$(EXEC)-$(VMAJ).$(VMIN)-$(REL)

.SUFFIXES: .o .h .c .hpp .cpp

all: $(EXECNAME)

clean:
	rm $(OBJ)/*.o
	rm $(EXECNAME)
	rm colchess

run: $(EXECNAME)
	./$(EXECNAME)
	
$(OBJ)/%.o: $(SRC)/%.cpp $(INC)/%.h $(INC)/commons.h
	$(CC) -c -o $@ $<

$(EXECNAME): $(ALL_OBJ)
	$(CL) -o $(EXECNAME) $(OBJ)/*.o $(SDLLIBS)
	ln -sf $(EXECNAME) ./colchess