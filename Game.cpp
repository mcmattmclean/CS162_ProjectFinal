/******************************************************************************
* Name: Game.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Game class implementation file, contains member function
**  definitions.
******************************************************************************/
#include "Game.hpp"

/******************************************************************************
* Function: Game() constructor
*
* Description: Initializes the Game, dynamically allocating the map.
******************************************************************************/
Game::Game(){

  //Initialize all rooms
  courtyard = new Courtyard();
  gate = new Gate();
  library = new Library();
  sroom = new SecretRoom();
  science = new ScienceBuilding();
  admin = new AdminBuilding();
  profRoom = new ProfessorRoom();

  //Set map for all rooms
  courtyard->setNorth(gate);
  courtyard->setWest(admin);
  courtyard->setEast(library);
  courtyard->setSouth(science);
  gate->setSouth(courtyard);
  library->setWest(courtyard);
  library->setEast(sroom);
  sroom->setWest(library);
  science->setNorth(courtyard);
  admin->setEast(courtyard);
  admin->setNorth(profRoom);
  profRoom->setSouth(admin);

  //Set start location
  currentRoom = courtyard;
}

/******************************************************************************
* Function: Game() destructor
*
* Description: Deletes all dynamically allocated objects.
******************************************************************************/
Game::~Game(){
  delete courtyard;
  delete gate;
  delete library;
  delete sroom;
  delete science;
  delete admin;
  delete profRoom;
}

/******************************************************************************
* Function: startGame()
*
* Description: Displays the main menu for the game, prompting user to either
**  start the game or quit.
******************************************************************************/
bool Game::startGame(){
  int choice = -1;
  bool play;
  int numPadding = getPadding(2, windowHeight, "graphics/main-menu.txt");

  do{
    printGraphic("graphics/main-menu.txt");
    for(int i = 0; i < numPadding; i ++){
      cout << endl;
    }
    cout << " TA: Please see README.md for detailed description of where to go/puzzle answers!\n" << endl;
    cout << " 1) Play Game" << endl << " 2) Quit" << endl;
    cout << " >>  ";
    choice = validateInt(1, 2);
  }while(choice == -1);

  if(choice == 1){
    play = true;
  }
  else{
    play = false;
  }

  return play;
}

/******************************************************************************
* Function: travel()
*
* Description: Takes the room pointer where the player wants to travel to as a
**  parameter. If this is null, prints that there is nowhere to go that direction,
**  and exits. If not null, then it checks if the room is visible and accessible,
**  outputting proper messages for each if either check fails. If both are true,
**  then the currentRoom pointer points to the passed room pointer.
******************************************************************************/
void Game::travel(Room* toTravel){
  string tmp;
  if(toTravel == nullptr){//Don't proceed if there's no room this way
    tmp = currentRoom->getBlurb();
    currentRoom->setBlurb(" There's nowhere to go that way.");
    currentRoom->printState();
    cout << " Press enter to continue. ";
    currentRoom->setBlurb(tmp);
    cin.ignore();
    cin.get();
  }
  else{
    if(toTravel->getVisible() == false){//Check for visibility
      tmp = currentRoom->getBlurb();
      currentRoom->setBlurb(" Doesn't look like you can go this way... Unless...");
      currentRoom->printState();
      cout << " Press enter to continue. ";
      currentRoom->setBlurb(tmp);
      cin.ignore();
      cin.get();
    }
    else if(toTravel->getAccessible() == false){//Check for accessibility
      tmp = currentRoom->getBlurb();
      currentRoom->setBlurb(" You can't go here yet!");
      currentRoom->printState();
      cout << " Press enter to continue. ";
      currentRoom->setBlurb(tmp);
      cin.ignore();
      cin.get();
    }
    else{
      currentRoom = toTravel; //If all checks pass, move to new room
    }
  }
}

/******************************************************************************
* Function: run()
*
* Description: Drives the game, looping through user input and possible actions
**  until the game is completed.
******************************************************************************/
void Game::run(){
  currentRoom->printState();  //Begin intro sequence in the courtyard
  cout << " Press enter to get moving. ";
  cin.ignore();
  cin.get();
  currentRoom->setGraphic("graphics/courtyard-gate.txt");
  currentRoom->setBlurb(" Before you take a single step, a terrible gate appears, emanating death. The buildings\n near it sprout giant tentacles, and you feel your sanity slipping away as the seconds\n pass. You hear a scream from the direction of the administration building.");
  currentRoom->printState();
  cout << " Press enter to continue. ";
  currentRoom->setBlurb(" The massive gateway pulses, filling you with dread.");
  cin.get(); //End intro sequence

  while(!gameOver){ //Continue until player dies or gate is closed
    int menuChoice;
    //Loop printing the current graphic and waiting for valid input
    do{
      currentRoom->printState();
      cout << " Health: " << player.getHealth() << " Sanity: " << player.getSanity() << '\n' << endl;
      currentRoom->printMenu();
      cout << " >>  ";
      menuChoice = validateInt(1, currentRoom->getMenuSize());
    }while(menuChoice == -1);

    if(menuChoice == 1){  //Travel option
      int travelChoice = -1;

      //Print travel sub menu and loop until valid user input
      do{
        currentRoom->printState();
        currentRoom->travelMenu();
        cout << " >>  ";
        travelChoice = validateInt(1, 5);
      }while(travelChoice == -1);

      if(travelChoice == 1){
        travel(currentRoom->getNorth());
      }
      else if(travelChoice == 2){
        travel(currentRoom->getEast());
      }
      else if(travelChoice == 3){
        travel(currentRoom->getSouth());
      }
      else if(travelChoice == 4){
        travel(currentRoom->getWest());
      }
      else{
        player.setSanity(player.getSanity()+1); //Prevent sanity loss when not moving
      }
    }

    if(menuChoice == 2){  //Check inventory option
      currentRoom->printState();
      vector<string>* userBag = player.getBag();
      if(userBag->size() == 0){
        cout << " Your bag is empty!" << endl;
      }
      else{
        cout << " Your bag contains: " << endl;
        for(unsigned int i = 0; i < userBag->size(); i++){//Print each item in bag
          cout << ' ' << (*userBag)[i] << endl;
        }
      }
      cout << "\n Press enter to continue. ";
      cin.clear();
      cin.ignore();
      cin.get();
    }

    if(menuChoice == 3){  // Explore option
      currentRoom->explore(&player);  //Explore logic handled by individual room
    }

    refresh();  //Updates room info, checks for game over, subtracts sanity
  }

  //Game is over, so determine win or lose
  if(player.getSanity() <= 0 || player.getHealth() <= 0){ //Loss conditions
    int padding = getPadding(0, windowHeight, "graphics/lose.txt");
    for(int i = 0; i < padding; i++){
      cout << endl;
    }
    printGraphic("graphics/lose.txt");
    for(int i = 0; i < padding; i++){
      cout << endl;
    }
  }
  else{
    int padding = getPadding(0, windowHeight, "graphics/win.txt");
    for(int i = 0; i < padding; i++){
      cout << endl;
    }
    printGraphic("graphics/win.txt");
    for(int i = 0; i < padding; i++){
      cout << endl;
    }
  }
  cout << " Press enter to return to main menu.";
  cin.get();
}


/******************************************************************************
* Function: refresh()
*
* Description:
******************************************************************************/
void Game::refresh(){
  player.setSanity(player.getSanity()-1); //After every game choice, sanity decreases by 1
  if(player.getSanity() <= 0 || player.getHealth() <= 0){
    gameOver = true;
  }
  if(player.hasUnlockedRoom()){ //Check for secret room status
    sroom->setAccessible(true);
    sroom->setVisible(true);
  }
  if(player.hasClosedGate()){ //Check for win condition
    gameOver = true;
  }
}
