/******************************************************************************
* Name: ProfessorRoom.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: ProfessorRoom class header file, contains protected member
**  variable declarations and member function prototypes.
******************************************************************************/
#ifndef PROFESSORROOM_HPP
#define PROFESSORROOM_HPP

#include "Room.hpp"

class ProfessorRoom : public Room{
private:
public:
  ProfessorRoom();
  void printState();

};


#endif
