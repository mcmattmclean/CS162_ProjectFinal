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

void Room::setAccessible(bool status){
  isAccessible = status;
}

bool Room::getAccessible(){
  return isAccessible;
}

void Room::setVisible(bool status){
  visible = status;
}

bool Room::getVisible(){
  return visible;
}

void Room::printState(){
  string currentGraphic = getGraphic();
  printGraphic(currentGraphic);
  int padding = getPadding(getMenuSize(), 40, currentGraphic);
  for(int i = 0; i < padding; i++){
    cout << endl;
  }
  cout << getBlurb() << endl;
  for(int i = 0; i < padding; i++){
    cout << endl;
  }
}

vector<string>* Room::getMenu(){
  return &menuList;
}

void Room::travelMenu(){
  cout << " LOCATIONS" << endl;
  cout << " 1) North: ";
  if(getNorth() != nullptr && getNorth()->getVisible() == true){
    cout << getNorth()->getName() << endl;
  }
  else{
    cout << "Nothing" << endl;
  }
  cout << " 2) East: ";
  if(getEast() != nullptr && getEast()->getVisible() == true){
    cout << getEast()->getName() << endl;
  }
  else{
    cout << "Nothing" << endl;
  }
  cout << " 3) South: ";
  if(getSouth() != nullptr && getSouth()->getVisible() == true){
    cout << getSouth()->getName() << endl;
  }
  else{
    cout << "Nothing" << endl;
  }
  cout << " 4) West: ";
  if(getWest() != nullptr && getWest()->getVisible() == true){
    cout << getWest()->getName() << endl;
  }
  else{
    cout << "Nothing" << endl;
  }
  cout << " 5) Return to menu." << endl;
}

void Room::addMenu(string toAdd){
  menuList.push_back(toAdd);
}

int Room::getMenuSize(){
  return menuList.size();
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
