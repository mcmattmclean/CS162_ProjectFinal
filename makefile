CXX = g++
CXXFLAGS = -std=c++0x -pedantic-errors -Wall
OBJS = main.o util.o
EXECUTABLE = project_test

all: ${OBJS}
	${CXX} ${OBJS} -o ${EXECUTABLE}

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

util.o: util.cpp util.hpp
	${CXX} ${CXXFLAGS} -c util.cpp

clean:
	rm *.o ${EXECUTABLE}
