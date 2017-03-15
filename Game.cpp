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
* Description: Initializes the Game, dynamically allocating the map and player
**  objects.
******************************************************************************/
Game::Game(){

}

/******************************************************************************
* Function: startGame() constructor
*
* Description: First prints the setup screen for the game, allowing the user to
**  resize their screen as appropriate. Then starts the main menu for the game,
**  prompting user to either start the game or quit.
******************************************************************************/
bool Game::startGame(){
  //Print set-up graphic so user can resize window
  printGraphic("graphics/setup.txt");
  cout << " >> ";
  cin.get();  //Wait for enter character

  int choice = -1;
  bool play;
  int numPadding = (windowHeight - getNumLines("graphics/main-menu.txt")) \
  / 2 - 2;

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

/******************************************************************************
* Function: run()
*
* Description: Drives the game, looping through user input and possible actions
**  until the game is completed.
******************************************************************************/
void Game::run(){



}

void Game::refresh(){
  
}
