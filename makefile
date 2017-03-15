CXX = g++
CXXFLAGS = -std=c++0x -pedantic-errors -Wall
OBJS = main.o util.o Game.o Room.o Courtyard.o Player.o
EXECUTABLE = project_test

all: ${OBJS}
	${CXX} ${OBJS} -o ${EXECUTABLE}

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

util.o: util.cpp util.hpp
	${CXX} ${CXXFLAGS} -c util.cpp

Game.o: Game.cpp Game.hpp
	${CXX} ${CXXFLAGS} -c Game.cpp

Player.o: Player.cpp Player.hpp
	${CXX} ${CXXFLAGS} -c Player.cpp

Room.o: Room.cpp Room.hpp
	${CXX} ${CXXFLAGS} -c Room.cpp

Courtyard.o: Courtyard.cpp Courtyard.hpp
	${CXX} ${CXXFLAGS} -c Courtyard.cpp

clean:
	rm *.o ${EXECUTABLE}
