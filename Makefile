CC=g++
INC=-I ./interface/
FLAG=-std=c++11
LIB=
SRC=./src
OBJ=$(SRC)/QIEChannels.o $(SRC)/Charge.o
EXE=main

default: $(EXE)

$(EXE): $(EXE).o $(OBJ)
	$(CC) $(FLAG) $(LIB) $(INC) -o $@ $@.o $(OBJ)

.cc.o:
	$(CC) -c $(FLAG) $(INC) -o $@ $<

clean: 
	rm -f $(EXE)
	rm -f $(EXE).o
	rm -f $(OBJ)

