EXEC=colchess
VMAJ=0
VMIN=1
REL=1
EXECNAME=$(EXEC)-$(VMAJ).$(VMIN)-$(REL)$(EXEC_EXT)

ALL_OBJ=$(OBJ)/colchess.o $(OBJ)/board.o $(OBJ)/tileMap.o $(OBJ)/player.o $(OBJ)/playerIndustry.o $(OBJ)/playerNature.o $(OBJ)/tile.o $(OBJ)/tileBase.o $(OBJ)/tileStructure.o $(OBJ)/tileTerrain.o $(OBJ)/tileUnit.o

.SUFFIXES: .o .h .c .hpp .cpp

all: $(EXECNAME)

clean:
	rm $(OBJ)/*.o
	rm $(EXECNAME)

run: $(EXECNAME)
	./$(EXECNAME)
	
$(OBJ)/%.o: $(SRC)/%.cpp $(INC)/%.h $(INC)/commons.h
	$(CC) -c -o $@ $<

$(EXECNAME): $(ALL_OBJ)
	$(CL) -o $(EXECNAME) $(OBJ)/*.o $(SDLLIBS)