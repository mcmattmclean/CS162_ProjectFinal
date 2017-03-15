/******************************************************************************
* Name: Gate.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Gate class header file, contains protected member
**  variable declarations and member function prototypes.
******************************************************************************/
#ifndef GATE_HPP
#define GATE_HPP

#include "Room.hpp"

class Gate : public Room{
private:
public:
  Gate();
  void update();

};


#endif
