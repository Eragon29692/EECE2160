# make WiimoteBtns

WiimoteBtns: main.o WiimoteBtns.o
	g++ main.o WiimoteBtns.o -o WiimoteBtns

main.o: main.cpp WiimoteBtns.h
	g++ -g -Wall -c main.cpp

WiimoteBtns.o: WiimoteBtns.cpp WiimoteBtns.h
	g++ -g -Wall -c WiimoteBtns.cpp

clean:
	rm WiimoteBtns.o main.o WiimoteBtns
