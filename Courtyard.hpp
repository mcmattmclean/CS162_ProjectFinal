/******************************************************************************
* Name: Courtyard.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Courtyard class header file, contains protected member
**  variable declarations and member function prototypes.
******************************************************************************/
#ifndef COURTYARD_HPP
#define COURTYARD_HPP

#include "Room.hpp"

class Courtyard : public Room{
private:
  bool gatePresentOpen = false;  //When true, graphic switches to open
  bool gatePresentClosed = false;  //When true, graphic switches to closed gate
  bool firstVisit = true;
public:
  Courtyard();
  void update();

};


#endif
