/******************************************************************************
* Name: AdminBuilding.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Gate class implementation file, contains member function
**  definitions. Derived from room class.
******************************************************************************/
#include "AdminBuilding.hpp"

/******************************************************************************
* Constructor
*
* Description: Sets name, blurb, and graphic.
******************************************************************************/
AdminBuilding::AdminBuilding(){
  setName("The Administration Building");
  setBlurb(" The hallway is quiet as usual. All the more disturbing after the scream you heard\n earlier.");
  setGraphic("graphics/admin.txt");
}

/******************************************************************************
* Function: explore()
*
* Description: Sets output strings depending on player actions.
******************************************************************************/
void AdminBuilding::explore(Player* player){
  string tmp = getBlurb(); //Clear the blurb

  printState();
  if(player->hasProfessor() && player->hasMonster()){
    setBlurb(" Professor: We best get moving, that gate won't close itself.");
  }
  else if(player->hasProfessor()){
    setBlurb(" We're not going to find what we need messing about here longer!");
  }
  else{
    setBlurb(" Professor Harvey's Office lies straight ahead.");
  }
  printState();
  cout << " Press enter to continue. ";
  cin.ignore();
  cin.get();
  setBlurb(tmp);
}
