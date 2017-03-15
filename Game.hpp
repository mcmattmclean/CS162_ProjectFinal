/******************************************************************************
* Name: Game.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Game class header file, contains protected member
**  variable declarations and member function prototypes.
******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "util.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "Courtyard.hpp"
#include "Game.hpp"

class Game{
private:
  Player* player = nullptr;
public:
  Game();
  bool startGame();
  void run();

};

#endif
