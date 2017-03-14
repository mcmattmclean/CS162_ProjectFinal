CXX = g++
CXXFLAGS = -std=c++0x -pedantic-errors -Wall
OBJS = main.o
EXECUTABLE = project_test

all: ${OBJS}
	${CXX} ${OBJS} -o ${EXECUTABLE}

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

clean:
	rm *.o ${EXECUTABLE}
