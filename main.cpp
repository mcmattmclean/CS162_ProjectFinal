#include "Game.hpp"

int main(){
  bool playAgain = true;

  calibrateScreen();

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
