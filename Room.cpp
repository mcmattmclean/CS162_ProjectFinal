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
