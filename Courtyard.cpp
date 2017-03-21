/******************************************************************************
* Name: Courtyard.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Courtyard class implementation file, contains member function
**  definitions. Derived from room class.
******************************************************************************/
#include "Courtyard.hpp"

Courtyard::Courtyard(){
  setName("The Courtyard");
  setBlurb(" You finally arrive at Miskatonic University's courtyard, late yet again. Better\n hurry to Professor Harvey's office before he notices his least favorite TA's\n absence.");
  setGraphic("graphics/courtyard-intro.txt");
}

/******************************************************************************
* Function: explore()
*
* Description: Sets output strings depending on player actions.
******************************************************************************/
void Courtyard::explore(Player* player){
  string tmp = getBlurb();
  if(player->hasTome() && player->hasPapers() && player->hasProfessor()){
    setBlurb(" Professor: I really don't think now is the time, that gate needs sealing!");
  }
  else if(player->hasProfessor() && player->hasMonster()){
    setBlurb(" Professor: Quick, my colleagues at the science building might be able to help us!");
  }
  else if(player->hasProfessor() && player->hasPapers()){
    setBlurb(" Professor: We can't seal the gate without the ancient rites! Quick, to the library!");
  }
  else{
    setBlurb(" The gate hums with a mysterious and terrible energy.");
  }
  printState();
  cout << " Press enter to continue. ";
  cin.clear();
  cin.ignore();
  cin.get();
  setBlurb(tmp);
}
