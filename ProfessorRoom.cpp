/******************************************************************************
* Name: ProfessorRoom.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: ProfessorRoom class implementation file, contains member function
**  definitions. Derived from room class.
******************************************************************************/
#include "ProfessorRoom.hpp"

/******************************************************************************
* Constructor
*
* Description: Sets name, blurb, and graphic.
******************************************************************************/
ProfessorRoom::ProfessorRoom(){
  setName("Professor Harvey's Office");
  setBlurb(" It's strangely quiet. You see what you think is blood pooling behind the desk...");
  setGraphic("graphics/office.txt");
}

/******************************************************************************
* Function: explore()
*
* Description: Sets output strings depending on player actions. For this room,
**  also executes the fight with the terrible monster. The fight continues until
**  the monster or the player is defeated. If defeated, the professor joins
**  the player and the corpse is added to his or her inventory.
******************************************************************************/
void ProfessorRoom::explore(Player* player){
  if(firstVisit){ //Only fight monster on first visit
    setGraphic("graphics/monster.txt");
    setBlurb(" A horrifying monster crawls out from behind the desk! ");
    int fightChoice = -1;
    do{
      while(fightChoice == -1){ //Get valid fight choice
        printState();
        cout << " 1) Punch the monster" << endl;
        cout << " 2) Cower in fear" << endl;
        cout << " 3) Use your environment" << endl;
        cout << " 4) Accept the monster is only in your mind" << endl;
        cout << " >>  ";
        fightChoice = validateInt(1, 4);
      }

      // Control output for fight choices
      if(fightChoice == 1){
        setBlurb(" Your strikes confuse the monster more then anything, its terrible eyes stare\n at you in disappointment.");
      }
      else if(fightChoice == 2){
        setBlurb(" The beast grabs you by the throat, and throws you against the wall.");
        player->setHealth(player->getHealth() - 50);
      }
      else if(fightChoice == 3){
        setBlurb(" You maneuver around the monster, dodging its evil claws as it reaches for\n you. You grab the bookshelf and heave with all your might. It tumbles forward,\n crushing the horrible creature.\n\n You've acquired: A Monstrous Corpse");
        player->addItem("A Monstrous Corpse"); //Player must choose this option to proceed
      }
      else if(fightChoice == 4){
        setBlurb(" What a foolish thing to do. The monster lurches toward you, and crushes your\n throat between its slick claws.");
        player->setHealth(0);
      }

      printState();
      cout << " Health: " << player->getHealth() << " Sanity: " << player->getSanity() << '\n' << endl;
      cout << " Press enter to continue. ";
      cin.clear();
      cin.ignore();
      cin.get();
      fightChoice = -1; //Reset input validation
    }while((player->hasMonster() == false) && (player->getHealth() > 0)); //Continue until player or monster is defeated.

    if(player->getHealth() > 0){ //Check for death before progressing story
      firstVisit = false;
      player->setProfessor(true);
      setBlurb(" The storage closet door suddenly swings open, and the Professor sheepishly walks out.\n\n Professor: Goodness what a mess. I suppose that's to be expected when the space and\n time continuum insits on allowing the old ones to return. Ah well, let's get\n to closing that gate!");
      setGraphic("graphics/office-defeated.txt");
      printState();
      cout << " Press enter to continue. ";
      cin.get();
      setBlurb(" The office is a complete mess.");
    }
  }
  else{//If not the first visit, choose correct blurb
    string tmp = getBlurb();
    if((player->hasTome() && player->hasProfessor()) || (player->hasPapers() && player->hasProfessor())){
      setBlurb(" Professor: There isn't anything left here, stop snooping around my things and move!");
    }
    else if(player->hasProfessor() && player->hasMonster()){
      setBlurb(" Professor: If we can learn more about this creature, perhaps we can begin to\n understand where it came from!");
    }
    else{
      setBlurb(" Professor: We can't seal the gate without the ancient rites! Quick, to the library!");
    }
    printState();
    setBlurb(tmp);
    cout << " Press enter to continue. ";
    cin.clear();
    cin.ignore();
    cin.get();
  }
}
