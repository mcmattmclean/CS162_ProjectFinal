/******************************************************************************
* Name: Player.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Player class header file, contains protected member
**  variable declarations and member function prototypes.
******************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;


class Player{
private:
  vector<string> bag {};
  vector<string> allies {};
  int maxBagSize = 5;
  string name = "";
public:
  Player(string);
  void setName(string);
  string getName();


};


#endif
