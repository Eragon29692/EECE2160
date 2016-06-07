Furniture: Furniture.o Table.o Bed.o main.o
	g++ Furniture.o Table.o Bed.o main.o -o Furniture

Furniture.o: Furniture.cpp Furniture.h
	g++ -g -Wall -c Furniture.cpp

Table.o: Table.cpp Table.h Furniture.h
	g++ -g -Wall -c Table.cpp

Bed.o: Bed.cpp Bed.h Furniture.h
	g++ -g -Wall -c Bed.cpp

main.o: main.cpp Bed.h Table.h Furniture.h
	g++ -g -Wall -c main.cpp

clean:
	rm Bed.o Table.o main.o Furniture.o Furniture
