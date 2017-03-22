/******************************************************************************
* Name: Room.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Abstract class Room implementation file, contains member function
**  definitions.
******************************************************************************/
#include "Room.hpp"

/******************************************************************************
* Constructor
******************************************************************************/
Room::Room(){
}

/******************************************************************************
* Destructor
******************************************************************************/
Room::~Room(){}

/******************************************************************************
* Function setNorth()
*
* Description: Sets north to passed room pointer.
******************************************************************************/
void Room::setNorth(Room* room){
  north = room;
}

/******************************************************************************
* Function setSouth()
*
* Description: Sets south to passed room pointer.
******************************************************************************/
void Room::setSouth(Room* room){
  south = room;
}

/******************************************************************************
* Function setEast()
*
* Description: Sets east to passed room pointer.
******************************************************************************/
void Room::setEast(Room* room){
  east = room;
}

/******************************************************************************
* Function setWest()
*
* Description: Sets west to passed room pointer.
******************************************************************************/
void Room::setWest(Room* room){
  west = room;
}

/******************************************************************************
* Function getNorth()
*
* Description: Returns room pointer north.
******************************************************************************/
Room* Room::getNorth(){
  return north;
}

/******************************************************************************
* Function getSouth()
*
* Description: Returns room pointer south.
******************************************************************************/
Room* Room::getSouth(){
  return south;
}

/******************************************************************************
* Function getEast()
*
* Description: Returns room pointer east.
******************************************************************************/
Room* Room::getEast(){
  return east;
}

/******************************************************************************
* Function getWest()
*
* Description: Returns room pointer west.
******************************************************************************/
Room* Room::getWest(){
  return west;
}

/******************************************************************************
* Function setName()
*
* Description: Sets name to passed string value.
******************************************************************************/
void Room::setName(string nameIn){
  name = nameIn;
}

/******************************************************************************
* Function getName()
*
* Description: Returns value of name variable.
******************************************************************************/
string Room::getName(){
  return name;
}

/******************************************************************************
* Function setGraphic()
*
* Description: Sets graphic to passed string value.
******************************************************************************/
void Room::setGraphic(string graphicIn){
    graphic = graphicIn;
}

/******************************************************************************
* Function getGraphic()
*
* Description: Returns value of graphic variable.
******************************************************************************/
string Room::getGraphic(){
  return graphic;
}

/******************************************************************************
* Function setBlurb()
*
* Description: Sets blurb to passed string value.
******************************************************************************/
void Room::setBlurb(string blurbIn){
  blurb = blurbIn;
}

/******************************************************************************
* Function getBlurb()
*
* Description: Returns value of blurb variable.
******************************************************************************/
string Room::getBlurb(){
  return blurb;
}

/******************************************************************************
* Function setAccessible()
*
* Description: Sets isAccessible to value of passed bool.
******************************************************************************/
void Room::setAccessible(bool status){
  isAccessible = status;
}

/******************************************************************************
* Function getAccessible()
*
* Description: Returns value of isAccessible bool.
******************************************************************************/
bool Room::getAccessible(){
  return isAccessible;
}

/******************************************************************************
* Function setVisible()
*
* Description: Sets visible to value of passed bool.
******************************************************************************/
void Room::setVisible(bool status){
  visible = status;
}

/******************************************************************************
* Function getVisible()
*
* Description: Returns value of visible variable.
******************************************************************************/
bool Room::getVisible(){
  return visible;
}

/******************************************************************************
* Function printState()
*
* Description: Gets the current graphic, prints it using printGraphic from
**  utility functions, then prints the blurb surrouned by padding as determined
**  by getPadding() utility function.
******************************************************************************/
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

/******************************************************************************
* Function getMenu()
*
* Description: Returns address of menuList vector.
******************************************************************************/
vector<string>* Room::getMenu(){
  return &menuList;
}

/******************************************************************************
* Function travelMenu()
*
* Description: Prints the locations in each of the 4 pointer variables, printing
**  "Nothing" if the pointer is null.
******************************************************************************/
void Room::travelMenu(){
  cout << " LOCATIONS" << endl;
  cout << " 1) North: ";
  if(getNorth() != nullptr && getNorth()->getVisible() == true){//Check north pointer, print if present
    cout << getNorth()->getName() << endl;
  }
  else{
    cout << "Nothing" << endl;
  }
  cout << " 2) East: ";
  if(getEast() != nullptr && getEast()->getVisible() == true){//Check east pointer, print if present
    cout << getEast()->getName() << endl;
  }
  else{
    cout << "Nothing" << endl;
  }
  cout << " 3) South: ";
  if(getSouth() != nullptr && getSouth()->getVisible() == true){//Check south pointer, print if present
    cout << getSouth()->getName() << endl;
  }
  else{
    cout << "Nothing" << endl;
  }
  cout << " 4) West: ";
  if(getWest() != nullptr && getWest()->getVisible() == true){//Check west pointer, print if present
    cout << getWest()->getName() << endl;
  }
  else{
    cout << "Nothing" << endl;
  }
  cout << " 5) Return to menu." << endl;
}

/******************************************************************************
* Function addMenu()
*
* Description: Adds the passed string to the back of the menuList vector.
******************************************************************************/
void Room::addMenu(string toAdd){
  menuList.push_back(toAdd);
}

/******************************************************************************
* Function getMenuSize()
*
* Description: returns the size of the menuList vector.
******************************************************************************/
int Room::getMenuSize(){
  return menuList.size();
}

/******************************************************************************
* Function printMenu()
*
* Description: Prints each menuList item, numbered.
******************************************************************************/
void Room::printMenu(){
  cout << " MENU" << endl;
  for(unsigned int i = 0; i < menuList.size(); i++){
    cout << ' ' << i+1 << ") " << menuList[i] << endl;
  }
}
