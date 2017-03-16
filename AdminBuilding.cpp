/******************************************************************************
* Name: AdminBuilding.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Gate class implementation file, contains member function
**  definitions. Derived from room class.
******************************************************************************/
#include "AdminBuilding.hpp"

AdminBuilding::AdminBuilding(){
  setName("The Administration Building");
  setBlurb(" The hallway is quiet as usual. All the more disturbing after the scream you heard\n earlier.");
}

void AdminBuilding::update(){}

void AdminBuilding::explore(Player* player){
  string tmp = getBlurb(); //Clear the blurb
  setBlurb("");

  printState();
  if(player->hasProfessor() && player->hasMonster()){
    setBlurb(" Professor: We best get moving, that gate won't close itself.");
    printState();
  }
  else if(player->hasProfessor()){
    setBlurb(" We're not going to find what we need messing about here longer!");
    printState();
  }
  else{
    setBlurb(" The hallway seems to go on forever. Professor Harvey's Office lies straight ahead.");
    printState();
  }
  cin.ignore();
  cin.get();
  setBlurb(tmp);
}
