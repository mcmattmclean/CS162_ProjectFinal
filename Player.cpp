#include "Player.hpp"

Player::Player(){}

void Player::setHealth(int healthIn){
  health = healthIn;
}

void Player::setSanity(int sanityIn){
  sanity = sanityIn;
}

int Player::getHealth(){
  return health;
}

int Player::getSanity(){
  return sanity;
}

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
* Description: Removes the item matching the passed string.
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

void Player::setTome(bool hasTome){
  tome = hasTome;
}

void Player::setMonster(bool hasMonster){
  monster = hasMonster;
}

void Player::setPapers(bool hasPapers){
  papers = hasPapers;
}

void Player::setProfessor(bool hasProfessor){
  professor = hasProfessor;
}

void Player::setUnlockedRoom(bool roomLockState){
  unlockedRoom = roomLockState;
}

bool Player::hasTome(){
  return tome;
}

bool Player::hasMonster(){
  return monster;
}

bool Player::hasPapers(){
  return papers;
}

bool Player::hasProfessor(){
  return professor;
}

bool Player::hasUnlockedRoom(){
  return unlockedRoom;
}
