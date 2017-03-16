/******************************************************************************
* Name: SecretRoom.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: SecretRoom class header file, contains protected member
**  variable declarations and member function prototypes.
******************************************************************************/
#ifndef SECRETROOM_HPP
#define SECRETROOM_HPP

#include "Room.hpp"

class SecretRoom : public Room{
private:
  bool firstVisit = true;
public:
  SecretRoom();
  void update();
  void explore(Player*);



};


#endif
