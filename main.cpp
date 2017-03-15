#include "Game.hpp"

int main(){

  Game game = Game();
  bool play = game.startGame();

  if(play){
    game.run();
  }


  // string test1 = "graphics/setup.txt";
  // string test2 = "graphics/basic-room.txt";
  //
  // printGraphic(test1);
  // cin.get();
  // printGraphic(test2);

  return 0;
}
