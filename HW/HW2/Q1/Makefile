Calculator: Calculator.o CalcMain.o
	g++ CalcMain.o Calculator.o -o Calculator

CalcMain.o: CalcMain.cpp Calculator.h Calculator.cpp
	g++ -g -Wall -c CalcMain.cpp

Calculator.o: Calculator.cpp Calculator.h
	g++ -g -Wall -c Calculator.cpp

clean:
	rm Calculator.o CalcMain.o Calculator
