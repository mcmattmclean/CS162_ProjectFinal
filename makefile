CXX = g++
CXXFLAGS = -std=c++0x -pedantic-errors -Wall
OBJS = main.o util.o Game.o Room.o Courtyard.o Gate.o Library.o
OBJS += SecretRoom.o ScienceBuilding.o AdminBuilding.o ProfessorRoom.o
EXECUTABLE = project_test

all: ${OBJS}
	${CXX} ${OBJS} -o ${EXECUTABLE}

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

util.o: util.cpp util.hpp
	${CXX} ${CXXFLAGS} -c util.cpp

Game.o: Game.cpp Game.hpp
	${CXX} ${CXXFLAGS} -c Game.cpp

Room.o: Room.cpp Room.hpp
	${CXX} ${CXXFLAGS} -c Room.cpp

Courtyard.o: Courtyard.cpp Courtyard.hpp
	${CXX} ${CXXFLAGS} -c Courtyard.cpp

Gate.o: Gate.cpp Gate.hpp
	${CXX} ${CXXFLAGS} -c Gate.cpp

Library.o: Library.cpp Library.hpp
	${CXX} ${CXXFLAGS} -c Library.cpp

SecretRoom.o: SecretRoom.cpp SecretRoom.hpp
	${CXX} ${CXXFLAGS} -c SecretRoom.cpp

ScienceBuilding.o: ScienceBuilding.cpp ScienceBuilding.hpp
	${CXX} ${CXXFLAGS} -c ScienceBuilding.cpp

AdminBuilding.o: AdminBuilding.cpp AdminBuilding.hpp
	${CXX} ${CXXFLAGS} -c AdminBuilding.cpp

ProfessorRoom.o: ProfessorRoom.cpp ProfessorRoom.hpp
	${CXX} ${CXXFLAGS} -c ProfessorRoom.cpp

clean:
	rm *.o ${EXECUTABLE}
