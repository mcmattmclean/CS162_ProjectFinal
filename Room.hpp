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
#include <vector>
#include "util.hpp"
using std::string;
using std::vector;

class Room{
private:
  Room* north = nullptr;
  Room* south = nullptr;
  Room* east = nullptr;
  Room* west = nullptr;
  string name = "";
  string graphic = "graphics/test-room.txt";
  string blurb = "";
  vector<string> menuList {"Travel", "Explore", "Check Inventory"};
public:
  Room();
  virtual ~Room();
  virtual void update() = 0;
  void printState();
  void printMenu();
  void setName(string);
  string getName();
  void setBlurb(string);
  string getBlurb();
  void setGraphic(string);
  string getGraphic();
  void addMenu(string);
  int getMenuSize();
  void clearMenu();
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
