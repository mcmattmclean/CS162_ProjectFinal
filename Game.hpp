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
#include "Gate.hpp"
#include "Library.hpp"
#include "SecretRoom.hpp"
#include "ScienceBuilding.hpp"
#include "AdminBuilding.hpp"
#include "ProfessorRoom.hpp"
#include "Game.hpp"

class Game{
private:
  const int windowHeight = 40;
  Player* player = nullptr;
  Room* currentRoom = nullptr;
  Room* courtyard = nullptr;
  Room* gate = nullptr;
  Room* library = nullptr;
  Room* sroom = nullptr;
  Room* science = nullptr;
  Room* admin = nullptr;
  Room* profRoom = nullptr;

public:
  Game();
  ~Game();
  bool startGame();
  void run();
  void refresh();

};

#endif
