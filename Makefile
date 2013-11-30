OS=mac
INC=./inc
LIB=./lib
SRC=./src
OBJ=./obj

SDLFLAGS=-I/opt/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE
CC=g++ -c -Wall -I$(INC) $(SDLFLAGS)
SDLLIBS=-L/opt/local/lib -lSDLmain -Wl,-framework,AppKit -lSDL -Wl,-framework,Cocoa
CL=g++ -Wall -L$(LIB) $(SDLLIBS) -framework CoreFoundation -headerpad_max_install_names

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

	
$(OBJ)/%.o: $(SRC)/%.cpp $(INC)/%.h $(INC)/commons.h
	$(CC) -c -o $@ $<

$(EXECNAME): $(ALL_OBJ)
	$(CL) -o $(EXECNAME) $(OBJ)/*.o