/******************************************************************************
* Name: Library.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Library class implementation file, contains member function
**  definitions. Derived from room class.
******************************************************************************/
#include "Library.hpp"

/******************************************************************************
* Constructor
*
* Description: Sets name, blurb, and graphic.
******************************************************************************/
Library::Library(){
  setName("The Library");
  setBlurb(" The librarian ignores you, her nose down in a novel far more interesting than you.");
  setGraphic("graphics/library-locked.txt");
}

/******************************************************************************
* Function: explore()
*
* Description: Sets output strings depending on player actions.
******************************************************************************/
void Library::explore(Player* player){
  string tmp = getBlurb();
  string tmpG = getGraphic();

  if(player->hasProfessor() && player->hasPapers() && !player->hasUnlockedRoom()){ //Get tome path

    if(firstVisit){ //Only display this the first time they enter with the professor
      firstVisit = false;
      setBlurb(" Professor: Quick, the tome is kept in a secret room behind the east wall! There's a\n combination lock behind the books on the third shelf that will open the way!");
      printState();
      cout << " Press enter to continue. ";
      cin.clear();
      cin.ignore();
      cin.get();

      setBlurb(" Professor: Blasted thing! I haven't had to get into this room in quite a while, and my\n memory isn't what it used to be. Better keep trying combinations until we get in.");
      printState();
      cout << " Press enter to continue. ";
      cin.clear();
      cin.get();
    }
    setGraphic("graphics/bookshelf.txt");
    setBlurb(" The combination lock goes from the numbers 1 - 35. It requires 3 numbers, a right pass,\n a left pass, then a second right pass. The school isn't known for their security,\n so what could it be...");
    int stay = -1;
    do{//Loop menu and solve attempt until successful or player leaves
      do{//Print combination menu until valid input
        printState();
        cout << " 1) Solve" << endl;
        cout << " 2) Leave" << endl;
        cout << " >>  ";
        stay = validateInt(1, 2);
      }while(stay == -1);

      int firstNum;
      int secondNum;
      int thirdNum;

      if(stay == 1){  //Get combo from user
        stay = -1;
        do{//Loop until input valid
          printState();
          cout << " Enter the first number:" << endl;
          cout << " >>  ";
          firstNum = validateInt(1, 35);
        }while(firstNum == -1);
        do{//Loop until input valid
          printState();
          cout << " Enter the second number:" << endl;
          cout << " >>  ";
          secondNum = validateInt(1, 35);
        }while(secondNum == -1);
        do{//Loop until input valid
          printState();
          cout << " Enter the third number:" << endl;
          cout << " >>  ";
          thirdNum = validateInt(1, 35);
        }while(thirdNum == -1);

        if (firstNum == 12 && secondNum == 30 && thirdNum == 18){ //Check if correct
          setBlurb(" You hear a quiet hiss that grows lowder. Suddenly, the bookshelf swings open,\n revealing the secret room!");
          player->setUnlockedRoom(true);
          printState();
          cout << " Press enter to continue. ";
          cin.clear();
          cin.ignore();
          cin.get();
          setGraphic("graphics/library-unlocked.txt");
        }
        else{//If incorrect
          setBlurb(" You hear a faint whirring behind the bookshelf, but it quickly stops.");
          printState();
          cout << " Press enter to continue. ";
          setGraphic(tmpG);
          cin.clear();
          cin.ignore();
          cin.get();
        }
      }
    }while(!player->hasUnlockedRoom() && stay == 1);

    if(stay == 2){
      setGraphic(tmpG); //In case player backs out before even attempting combo
    }

  }
  else{
    if(!player->hasProfessor()){  //Exploring before having the professor
      setBlurb(" It's quiet here and filled with books. The oldest section is concentrated in an ancient\n bookshelf along the east wall.");
    }
    else if(player->hasTome() && player->hasPapers() && player->hasProfessor()){
      setBlurb(" Professor: We better get back to that gate, I think with these items, and a little luck,\n we stand a chance at closing it!");
    }
    else if(!player->hasTome() && player->hasUnlockedRoom()){
      setBlurb(" Professor: Lets get in there and grab that tome!");
    }
    else if(player->hasProfessor() && player->hasMonster()){
      setBlurb(" Professor: This corpse alone won't do us any good, we need to study it at the science\n building first!");
    }
    printState();
    cout << " Press enter to continue. ";
    cin.clear();
    cin.ignore();
    cin.get();
  }
  setBlurb(tmp);
}
