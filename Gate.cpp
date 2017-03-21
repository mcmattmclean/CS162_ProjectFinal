/******************************************************************************
* Name: Gate.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Gate class implementation file, contains member function
**  definitions. Derived from room class.
******************************************************************************/
#include "Gate.hpp"

Gate::Gate(){
  setName("A gate to another dimension");
  setBlurb(" The gate vibrates, shaking your bones and tearing at your mind.");
  setGraphic("graphics/gate.txt");
}

/******************************************************************************
* Function: explore()
*
* Description: Sets output strings depending on player actions. This room has
**  the logic for closing the gate.
******************************************************************************/
void Gate::explore(Player* player){
  // player->setTome(true);
  // player->setPapers(true);
  // player->setProfessor(true);//testing

  string tmp = getBlurb();

  if(player->hasTome() && player->hasPapers() && player->hasProfessor()){
    setBlurb(" Professor: Alright, here goes nothing!");
    printState();
    cout << " Press enter to continue. ";
    cin.clear();
    cin.ignore();
    cin.get();

    setBlurb(" The professor chants the ancient rites from the tome, checking his notes as he goes.\n The portal continues to writhe, the buildings tentacles suddenly turning toward you.");
    setGraphic("graphics/chant.txt");
    printState();
    cout << " Press enter to continue. ";
    cin.clear();
    cin.get();

    setBlurb(" A massive tentacle raises above you, poised to smash you to bits. The professor\n continues to chant, sweat pouring down his brow, blood beginning to drip from\n his ears and eyes.");
    setGraphic("graphics/tentacle.txt");
    printState();
    cout << " Press enter to continue. ";
    cin.clear();
    cin.get();

    setBlurb(" As the tentacle swings down, you close your eyes, accepting your fate.");
    setGraphic(""); //Set blank graphic
    printState();
    cout << " Press enter to continue. ";
    cin.clear();
    cin.get();

    setBlurb(" Yet...");
    printState();
    cout << " Press enter to continue. ";
    cin.clear();
    cin.get();

    setBlurb(" Sudden silence. Broken by the chirp of a bird. You open your eyes and see that\n the gate is closed, and everything is back to normal.");
    setGraphic("graphics/courtyard-gateclosed.txt");
    printState();
    cout << " Press enter to continue. ";
    cin.clear();
    cin.get();

    setBlurb(" Professor: Well then, that was anticlimactic. Ah well, back to grading those papers!");
    player->setClosedGate(true);
    printState();
    cout << " Press enter to continue. ";
    cin.get();
  }
  else{
    string tmpG = getGraphic();
    if(player->hasProfessor() && player->hasMonster()){
      setBlurb(" Professor: We're not ready to close the gate yet! We've got to study this monster first!");
    }
    else if(player->hasProfessor() && !player->hasTome()){
      setBlurb(" Professor: We're not ready to close the gate yet! We've still got to grab the\n ancient tome!");
    }
    else if(!player->hasProfessor()){
      setBlurb(" The mere proximity of the gate is enough to drive you insane. You touch your ear\n and find it slick with blood.");
      setGraphic("graphics/gate-pulse.txt");
      player->setSanity(player->getSanity() - 5);
    }
    printState();
    setGraphic(tmpG);
    cout << " Press enter to continue. ";
    cin.clear();
    cin.ignore();
    cin.get();
    setBlurb(tmp);
  }
}
