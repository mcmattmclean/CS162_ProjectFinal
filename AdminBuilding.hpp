/******************************************************************************
* Name: AdminBuilding.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: AdminBuilding class header file, contains protected member
**  variable declarations and member function prototypes.
******************************************************************************/
#ifndef ADMINBUILDING_HPP
#define ADMINBUILDING_HPP

#include "Room.hpp"

class AdminBuilding : public Room{
private:
public:
  AdminBuilding();
  void printState();

};


#endif
