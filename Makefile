CC=g++
INC=-I ./interface/
CFLAGS=-c -g -Wall `root-config --cflags`
FLAG=-std=c++11
FLAG+=`root-config --glibs`
LIB=
SRC=./src
OBJ=$(SRC)/QIEChannels.o $(SRC)/Charge.o $(SRC)/Histgram.o
EXE=main

default: $(EXE)

$(EXE): $(EXE).o $(OBJ)
	$(CC) $(FLAG) $(LIB) $(INC) -o $@ $@.o $(OBJ)

.cc.o:
	$(CC) $(CFLAGS) $(INC) -o $@ $<

clean: 
	rm -f $(EXE)
	rm -f $(EXE).o
	rm -f $(OBJ)
