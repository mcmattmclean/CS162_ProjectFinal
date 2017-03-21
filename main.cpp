/******************************************************************************
* Name: main.cpp
* Date: 20 Mar 2017
* Author: Matthew McLean
* Description: The main function for CS162's final project. Allows for multiple
**  run-throughs of the game.
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
