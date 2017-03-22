/******************************************************************************
* Name: ScienceBuilding.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: ScienceBuilding class header file, contains protected member
**  variable declarations and member function prototypes.
******************************************************************************/
#ifndef SCIENCEBUILDING_HPP
#define SCIENCEBUILDING_HPP

#include "Room.hpp"

class ScienceBuilding : public Room{
private:
public:
  ScienceBuilding();
  void explore(Player*);

};


#endif
