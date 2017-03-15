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
  printGraphic("graphics/setup.txt");
  cin.get();
  printGraphic("graphics/main-menu.txt");
  cout << "1) Play Game" << endl << "2) Quit" << endl;
  // int play = 0;
  // cin >> play;
  return false;
}

/******************************************************************************
* Function: run()
*
* Description: Drives the game, looping through user input and possible actions
**  until the game is completed.
******************************************************************************/
void Game::run(){



}
