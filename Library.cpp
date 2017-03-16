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
  setBlurb(" The librarian ignores you, her nose down in a novel far more interesting than you.");
  setGraphic(" graphics/library-locked.txt");
}

void Library::update(){
}

/******************************************************************************
* Function: explore()
*
* Description: Sets output strings depending on player actions.
******************************************************************************/
void Library::explore(Player* player){
  string tmp = getBlurb();
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
      setGraphic("graphics/bookshelf.txt");
      printState();
      cout << " Press enter to continue. ";
      cin.clear();
      cin.get();
    }

    setBlurb(" The combination lock goes from the numbers 1 - 35. It requires 3 numbers, a right pass,\n a left pass, then a second right pass. The school isn't known for their\n security, so what could it be...");
    int stay = -1;
    do{
      do{
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
        do{
          printState();
          cout << " Enter the first number:" << endl;
          cout << " >>  ";
          firstNum = validateInt(1, 35);
        }while(firstNum == -1);
        do{
          printState();
          cout << " Enter the second number:" << endl;
          cout << " >>  ";
          secondNum = validateInt(1, 35);
        }while(secondNum == -1);
        do{
          printState();
          cout << " Enter the third number:" << endl;
          cout << " >>  ";
          thirdNum = validateInt(1, 35);
        }while(thirdNum == -1);

        if (firstNum == 12 && secondNum == 30 && thirdNum == 18){ //Check if correct
          setBlurb(" You hear a quiet hiss that grows lowder. Suddenly, the bookshelf swings open,\n revealing the secret room!");
          setGraphic("graphics/puzzle-solved.txt");
          player->setUnlockedRoom(true);
          printState();
          cout << " Press enter to continue. ";
          cin.clear();
          cin.ignore();
          cin.get();
          setGraphic("graphics/library-unlocked.txt");
        }
        else{
          setBlurb(" You hear a faint whirring behind the bookshelf, but it quickly stops.");
          printState();
          cout << " Press enter to continue. ";
          cin.clear();
          cin.ignore();
          cin.get();
        }
      }
    }while(!player->hasUnlockedRoom() && stay == 1);
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
      setBlurb(" Professor: This isn't the science building!");
    }
    printState();
    cout << " Press enter to continue. ";
    cin.clear();
    cin.ignore();
    cin.get();
  }
  setBlurb(tmp);
}
