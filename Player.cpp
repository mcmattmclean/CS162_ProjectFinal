/******************************************************************************
* Name: Player.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Player class implementation file, contains member function
**  definitions. Used to hold most game state variables as well as the player's
**  inventory.
******************************************************************************/

#include "Player.hpp"

/******************************************************************************
* Constructor
******************************************************************************/
Player::Player(){}

/******************************************************************************
* Function: setHealth()
*
* Description: Sets health variable to passed integer value.
******************************************************************************/
void Player::setHealth(int healthIn){
  health = healthIn;
}

/******************************************************************************
* Function: setSanity()
*
* Description: Sets sanity variable to passed integer value.
******************************************************************************/
void Player::setSanity(int sanityIn){
  sanity = sanityIn;
}

/******************************************************************************
* Function: getHealth()
*
* Description: Returns value of health variable.
******************************************************************************/
int Player::getHealth(){
  return health;
}

/******************************************************************************
* Function: getSanity()
*
* Description: Returns value of sanity variable.
******************************************************************************/
int Player::getSanity(){
  return sanity;
}

/******************************************************************************
* Function: getBag()
*
* Description: Returns address of bag vector, which is used to hold the user's
**  inventory as strings.
******************************************************************************/
vector<string>* Player::getBag(){
  return &bag;
}

/******************************************************************************
* Function: addItem
*
* Description: Adds item if there is room in the bag. Updates crirical item flags
**  if appropriate. Returns true if item was added, false if not.
******************************************************************************/
bool Player::addItem(string toAdd){
  bool itemAdded;

  if(bag.size() < maxBagSize){
    bag.push_back(toAdd);
    itemAdded = true;
    if(toAdd == "An Ancient Tome"){
      setTome(true);
    }
    else if(toAdd == "A Monstrous Corpse"){
      setMonster(true);
    }
    else if(toAdd == "Research Notes"){
      setPapers(true);
    }
  }
  else{
    itemAdded = false;
  }
  return itemAdded;
}

/******************************************************************************
* Function: removeItem
*
* Description: Removes the item matching the passed string, returning true if
**  it's there. If not returns false.
******************************************************************************/
bool Player::removeItem(string toRemove){
  bool removed = false;
  for(unsigned int i = 0; i < bag.size(); i++){
    if(bag[i] == toRemove){ //Iterate through bag until item matches toRemove
      bag.erase(bag.begin()+i);
      removed = true;
    }
  }
  return removed;
}

/******************************************************************************
* Function: setTome()
*
* Description: Sets tome variable to passed boolean value.
******************************************************************************/
void Player::setTome(bool hasTome){
  tome = hasTome;
}

/******************************************************************************
* Function: setMonster()
*
* Description: Sets monster variable to passed boolean value.
******************************************************************************/
void Player::setMonster(bool hasMonster){
  monster = hasMonster;
}

/******************************************************************************
* Function: setPapers()
*
* Description: Sets papers variable to passed boolean value.
******************************************************************************/
void Player::setPapers(bool hasPapers){
  papers = hasPapers;
}

/******************************************************************************
* Function: setProfessor()
*
* Description: Sets professor variable to passed boolean value.
******************************************************************************/
void Player::setProfessor(bool hasProfessor){
  professor = hasProfessor;
}

/******************************************************************************
* Function: setUnlockedRoom()
*
* Description: Sets unlockedRoom variable to passed boolean value.
******************************************************************************/
void Player::setUnlockedRoom(bool roomLockState){
  unlockedRoom = roomLockState;
}

/******************************************************************************
* Function: setClosedGate()
*
* Description: Sets closedGate variable to passed boolean value.
******************************************************************************/
void Player::setClosedGate(bool gateState){
  closedGate = gateState;
}

/******************************************************************************
* Function: hasTome()
*
* Description: Returns value of boolean tome variable.
******************************************************************************/
bool Player::hasTome(){
  return tome;
}

/******************************************************************************
* Function: hasMonster()
*
* Description: Returns value of boolean monster variable.
******************************************************************************/
bool Player::hasMonster(){
  return monster;
}

/******************************************************************************
* Function: hasPapers()
*
* Description: Returns value of boolean papers variable.
******************************************************************************/
bool Player::hasPapers(){
  return papers;
}

/******************************************************************************
* Function: hasProfessor()
*
* Description: Returns value of boolean professor variable.
******************************************************************************/
bool Player::hasProfessor(){
  return professor;
}

/******************************************************************************
* Function: hasUnlockedRoom()
*
* Description: Returns value of boolean unlockedRoom variable.
******************************************************************************/
bool Player::hasUnlockedRoom(){
  return unlockedRoom;
}

/******************************************************************************
* Function: hasClosedGate()
*
* Description: Returns value of boolean closedGate variable.
******************************************************************************/
bool Player::hasClosedGate(){
  return closedGate;
}
