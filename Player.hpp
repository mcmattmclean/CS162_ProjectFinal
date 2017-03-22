/******************************************************************************
* Name: Player.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Player class header file, contains member function prototypes
**  and private member variables. Used to hold most game state variables as
**  well as the player's inventory.
******************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>

using std::string;
using std::vector;

class Player{
private:
  vector<string> bag {"Notebook", "Lucky Penny"};
  int sanity = 100;
  int health = 100;
  unsigned int maxBagSize = 5;
  bool tome = false;
  bool monster = false;
  bool papers = false;
  bool professor = false;
  bool unlockedRoom = false;
  bool closedGate = false;
public:
  Player();
  void setHealth(int);
  void setSanity(int);
  int getHealth();
  int getSanity();

  vector<string>* getBag();
  bool addItem(string);
  bool removeItem(string);

  void setTome(bool);
  void setMonster(bool);
  void setPapers(bool);
  void setProfessor(bool);
  void setUnlockedRoom(bool);
  void setClosedGate(bool);
  bool hasTome();
  bool hasMonster();
  bool hasPapers();
  bool hasProfessor();
  bool hasUnlockedRoom();
  bool hasClosedGate();
};

#endif
