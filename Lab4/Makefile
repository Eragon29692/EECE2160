# Student program Makefile 

myZedBoard: zedMain.o ZedBoard.o 
	g++ zedMain.o ZedBoard.o –o myZedBoard	

zedMain.o: zedMain.cpp ZedBoard.h
	g++ -g –Wall -c zedMain.cpp

ZedBoard.o: ZedBoard.cpp ZedBoard.h
	g++ -g –Wall -c ZedBoard.cpp

clean:
	rm zedMain.o ZedBoard.o myZedBoard
