/******************************************************************************
* Name: Library.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Library class implementation file, contains member function
**  definitions. Derived from room class.
******************************************************************************/
#include "Library.hpp"

Library::Library(){
  setName("The Library");

}

void Library::update(){}

/******************************************************************************
* Function: explore()
*
* Description: Sets output strings depending on player actions.
******************************************************************************/
void Library::explore(Player* player){
  string tmp = getBlurb();
  // if(player->hasTome() && player->hasPapers() && player->hasProfessor()){
  //   setBlurb(" Professor: I really don't think now is the time, that gate needs sealing!");
  //   printState();
  // }
  // else if(player->hasProfessor() && player->hasMonster()){
  //   setBlurb(" Professor: Quick, my colleagues at the science building might be able to help us!");
  //   printState();
  // }
  // else if(player->hasProfessor() && player->hasPapers()){
  //   setBlurb(" Professor: We can't seal the gate without the ancient rites! Quick, to the library!");
  //   printState();
  // }
  // else{
  //   setBlurb(" The gate hums with a mysterious and terrible energy.");
  //   printState();
  // }
  cout << " Press enter to continue. ";
  cin.clear();
  cin.ignore();
  cin.get();
  setBlurb(tmp);
}
