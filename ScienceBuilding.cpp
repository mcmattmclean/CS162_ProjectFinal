/******************************************************************************
* Name: ScienceBuilding.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: ScienceBuilding class implementation file, contains member function
**  definitions. Derived from room class.
******************************************************************************/
#include "ScienceBuilding.hpp"

ScienceBuilding::ScienceBuilding(){
  setName("The Science Building");
  setBlurb(" The scientists here seem unimpressed by the terrible gate that continues to drive you insane.");
  setGraphic("graphics/science.txt");
}

void ScienceBuilding::update(){}

/******************************************************************************
* Function: explore()
*
* Description: Sets output strings depending on player actions and possessions.
**  This room lets the player trade the monster corpse for important research
**  notes, needed to close the gate.
******************************************************************************/
void ScienceBuilding::explore(Player* player){
  string tmp = getBlurb();
  bool hackyCinStuff = true;

  if(player->hasProfessor() && player->hasMonster()){ // Turn monster in for the research notes
    hackyCinStuff = false;
    setBlurb(" Professor: These scientists can help me dissect this fearsome beast! Let's see what we can learn...");
    setGraphic("graphics/dissection.txt");
    player->setMonster(false);
    player->setPapers(true);
    player->removeItem("A Monstrous Corpse");
    player->addItem("Research Notes");
    printState();

    cout << " Press enter to continue. ";
    cin.clear();
    cin.ignore();
    cin.get();
    setBlurb(" Professor: AHA! With these notes, we may stand a chance at closing that gate!\n\n You've acquired: Research Notes");
    setGraphic("graphics/notes.txt");
    printState();
  }
  else if(player->hasTome() && player->hasPapers() && player->hasProfessor()){
    setBlurb(" Professor: We've got everything we need to close that gate, let's get back to the courtyard!");
    printState();
  }
  else if(player->hasProfessor() && player->hasPapers()){
    setBlurb(" Professor: We can't seal the gate without the ancient rites! Quick, to the library!");
    printState();
  }
  else{
    setBlurb(" It smells like bleach in here.");
    printState();
  }
  cout << " Press enter to continue. ";
  cin.clear();
  if(hackyCinStuff){
    cin.ignore();
  }
  cin.get();
  setBlurb(tmp);
}
