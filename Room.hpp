/******************************************************************************
* Name: Room.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Abstract class Room header file, contains protected member
**  variable declarations and member function prototypes.
******************************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
using std::string;

class Room{
private:
  Room* north = nullptr;
  Room* south = nullptr;
  Room* east = nullptr;
  Room* west = nullptr;
  string name = "";
public:
  Room();
  void setName(string);
  string getName();
  void setNorth(Room*);
  void setSouth(Room*);
  void setEast(Room*);
  void setWest(Room*);
  Room* getNorth();
  Room* getSouth();
  Room* getEast();
  Room* getWest();
};

#endif
