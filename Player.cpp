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
**  if appropriate.
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
