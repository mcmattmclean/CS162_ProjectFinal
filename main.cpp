/******************************************************************************
* Name: main.cpp
* Date: 20 Mar 2017
* Author: Matthew McLean
* Description: The main function for Miskatonic Madness. Allows for multiple
**  run-throughs of the game. main controls which game functions are called
**  based on user input processed by Game functions.
******************************************************************************/
#include "Game.hpp"

int main(){
  bool playAgain = true;

  calibrateScreen();  //Allow user to resize their terminal window

  do{
    Game game = Game(); //Initialize game
    bool play = game.startGame(); //Display main menu of game

    if(play){
      game.run();
    }
    else{
      playAgain = false;
    }

  }while(playAgain == true);  //Game returns to main menu when ended

  return 0;
}
