/******************************************************************************
* Name: Room.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Abstract class Room implementation file, contains member function
**  definitions.
******************************************************************************/
#include "Room.hpp"

Room::Room(){
}

Room::~Room(){}

void Room::setNorth(Room* room){
  north = room;
}

void Room::setSouth(Room* room){
  south = room;
}

void Room::setEast(Room* room){
  east = room;
}

void Room::setWest(Room* room){
  west = room;
}

Room* Room::getNorth(){
  return north;
}

Room* Room::getSouth(){
  return south;
}

Room* Room::getEast(){
  return east;
}

Room* Room::getWest(){
  return west;
}

void Room::setName(string nameIn){
  name = nameIn;
}

string Room::getName(){
  return name;
}

void Room::setGraphic(string graphicIn){
    graphic = graphicIn;
}

string Room::getGraphic(){
  return graphic;
}

void Room::setBlurb(string blurbIn){
  blurb = blurbIn;
}

string Room::getBlurb(){
  return blurb;
}

void Room::printState(){
  string currentGraphic = getGraphic();
  printGraphic(currentGraphic);
  int padding = getPadding(getMenuSize(), 40, currentGraphic);
  for(int i = 0; i < padding; i++){
    cout << endl;
  }
  printMenu();
  for(int i = 0; i < padding; i++){
    cout << endl;
  }
}

void Room::addMenu(string toAdd){
  menuList.push_back(toAdd);
}

int Room::getMenuSize(){
  int totalHeadersFooters = 2;
  return menuList.size() + totalHeadersFooters;
}

void Room::printMenu(){
  cout << " MENU" << endl;
  for(unsigned int i = 0; i < menuList.size(); i++){
    cout << ' ' << i+1 << ") " << menuList[i] << endl;
  }
}

void Room::clearMenu(){
  while(menuList.size() > 0){
    menuList.clear();
  }
}
