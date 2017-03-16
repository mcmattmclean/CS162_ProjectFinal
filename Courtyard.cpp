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
  setBlurb(" You finally arrive at Miskatonic University's courtyard, late yet again.\n Better hurry to Professor Harvey's office before he notices his least favorite TA's absence.");
  setGraphic("graphics/courtyard-intro.txt");
}

void Courtyard::update(){
  if(gatePresentClosed){
    setGraphic("graphics/courtyard-gateclosed.txt");
    setBlurb(" The gate is shut, and Arkham is safe. For now...");
  }
  else if(gatePresentOpen){
    setBlurb(" The massive gateway to somewhere else pulses, filling you with dread.");
  }
  else if(firstVisit){
    firstVisit = false;
    gatePresentOpen = true;
    setGraphic("graphics/courtyard-gate.txt");
    setBlurb(" Before you take a single step, a terrible gate appears, emanating death. The buildings\n near it sprout giant tentacles, and you feel your sanity slipping away as the seconds\n pass. You hear a scream from the direcition of the administration building.");
  }
}

void Courtyard::explore(Player* player){
  if(player->hasTome() && player->hasPapers() && player->hasProfessor()){
    printState();
    cout << " Professor: I really don't think now is the time, that gate needs sealing!" << endl;
  }
  else if(player->hasProfessor() && player->hasMonster()){
    printState();
    cout << " Professor: Quick, my colleagues at the science building might be able to help us!" << endl;
  }
  else if(player->hasProfessor() && player->hasPapers()){
    printState();
    cout << " Professor: We can't seal the gate without the ancient rites! Quick, to the library!" << endl;
  }
  else{
    printState();
    cout << " The gate hums with a mysterious and terrible energy." << endl;
  }
  cin.ignore();
  cin.get();
}
