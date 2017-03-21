/******************************************************************************
* Name: SecretRoom.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: SecretRoom class implementation file, contains member function
**  definitions. Derived from room class.
******************************************************************************/
#include "SecretRoom.hpp"

SecretRoom::SecretRoom(){
  setName("A secret room behind a bookshelf");
  setAccessible(false);
  setVisible(false);
  setGraphic("graphics/secret-room.txt");
  setBlurb(" The room is dusty and filled with cobwebs. In the center of the room on a pedestal\n is an ancient tome.");
}

void SecretRoom::update(){}

/******************************************************************************
* Function: explore()
*
* Description: Sets output strings depending on player actions. This room
**  also has logic to pick up the ancient tome.
******************************************************************************/
void SecretRoom::explore(Player* player){
  string tmp = getBlurb();

  if(firstVisit){
    firstVisit = false;
    setBlurb(" You grab the ancient tome from its pedestal. It's heavier than you expected.\n\n Item acquired: Ancient Tome");
    player->addItem("An Ancient Tome");
    tmp = "The room is dusty and filled with cobwebs.";
    setGraphic("graphics/secret-room-tome.txt");
  }
  else{
    setBlurb(" Professor: Alright, that's everything. I should be able to close that gate now!");
  }
  printState();
  cout << " Press enter to continue. ";
  cin.clear();
  cin.ignore();
  cin.get();
  setBlurb(tmp);
}
