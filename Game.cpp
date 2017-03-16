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
* Description: First prints the setup screen for the game, allowing the user to
**  resize their screen as appropriate. Then starts the main menu for the game,
**  prompting user to either start the game or quit.
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

void Game::travel(Room* toTravel){
  if(toTravel == nullptr){
    currentRoom->printState();
    cout << " There's nowhere to go that way." << endl;
    cin.ignore();
    cin.get();
  }
  else{
    if(toTravel->getVisible() == false){
      currentRoom->printState();
      cout << "Doesn't look like you can go this way... Unless..." << endl;
      cin.ignore();
      cin.get();
    }
    else if(toTravel->getAccessible() == false){
      currentRoom->printState();
      cout << "You can't go here yet!" << endl;
      cin.ignore();
      cin.get();
    }
    else{
      currentRoom = toTravel;
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
  currentRoom->printState();  //Four lines for intro sequence
  cout << "Health: " << player.getHealth() << " Sanity: " << player.getSanity() << '\n' << endl;
  currentRoom->printMenu();
  cout << " >>  ";
  cin.ignore();
  cin.get();
  while(!gameOver){
    refresh();
    int menuChoice;
    do{
      currentRoom->printState();
      cout << "Health: " << player.getHealth() << " Sanity: " << player.getSanity() << '\n' << endl;
      currentRoom->printMenu();
      cout << " >>  ";
      menuChoice = validateInt(1, currentRoom->getMenuSize());
    }while(menuChoice == -1);

    if(menuChoice == 1){  //Travel option
      int travelChoice = -1;
      do{
        currentRoom->printState();
        currentRoom->travelMenu();
        cout << " >>  ";
        travelChoice = validateInt(1, 5);
      }while(travelChoice == -1);
      if(travelChoice == 1){ //North
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
    }

    if(menuChoice == 2){  //Check inventory option
      currentRoom->printState();
      vector<string>* userBag = player.getBag();
      if(userBag->size() == 0){
        cout << "Your bag is empty!" << endl;
      }
      else{
        cout << "Your bag contains: " << endl;
        for(unsigned int i = 0; i < userBag->size(); i++){
          cout << (*userBag)[i] << endl;
        }
      }
      cin.ignore();
      cin.get();
    }

    if(menuChoice == 3){
      currentRoom->explore(&player);
    }

    player.setSanity(player.getSanity()-1); //After every game choice, sanity decreases by 1
    if(player.getSanity() <= 0 || player.getHealth() <= 0){
      gameOver = true;
    }
  }

  if(player.getSanity() <= 0 || player.getHealth() <= 0){
    int padding = getPadding(0, windowHeight, "graphics/lose.txt");
    for(int i = 0; i < padding; i++){
      cout << endl;
    }
    printGraphic("graphics/lose.txt");
    for(int i = 0; i < padding; i++){
      cout << endl;
    }
    cout << "Press enter to return to main menu.";
    cin.ignore();
    cin.get();
  }
}

void Game::refresh(){
  currentRoom->update();
}
