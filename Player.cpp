/******************************************************************************
* Name: Player.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Player class implementation file, contains member function
**  definitions. Derived from room class.
******************************************************************************/
#include "Player.hpp"

Player::Player(string nameIn){
  setName(nameIn);
}

void Player::setName(string nameIn){
  name = nameIn;
}

string Player::getName(){
  return name;
}
