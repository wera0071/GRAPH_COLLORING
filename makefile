CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

.PHONY: all clean

all: main

main: parser.o solver.o main.o
	$(CXX) $(CXXFLAGS) parser.o solver.o main.o -o main

main.o: main.cpp parser.h solver.h
	$(CXX) $(CXXFLAGS) -c main.cpp

parser.o: parser.cpp parser.h
	$(CXX) $(CXXFLAGS) -c parser.cpp

solver.o: solver.cpp solver.h
	$(CXX) $(CXXFLAGS) -c solver.cpp

clean:
	@rm -rf *.o main
