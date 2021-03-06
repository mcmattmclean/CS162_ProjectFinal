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
#include "Player.hpp"
using std::string;
using std::vector;

class Room{
private:
  Room* north = nullptr;
  Room* south = nullptr;
  Room* east = nullptr;
  Room* west = nullptr;
  bool isAccessible = true;
  bool visible = true;
  string name = "";
  string graphic = "graphics/test-room.txt";
  string blurb = "";
  vector<string> menuList {"Travel", "Check Inventory", "Explore"};
public:
  Room();
  virtual ~Room();
  virtual void explore(Player*) = 0;
  void printState();
  void printMenu();
  void travelMenu();
  void setName(string);
  string getName();
  void setBlurb(string);
  string getBlurb();
  void setGraphic(string);
  string getGraphic();
  void setVisible(bool);
  bool getVisible();
  void setAccessible(bool);
  bool getAccessible();
  void addMenu(string);
  int getMenuSize();
  vector<string>* getMenu();
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
