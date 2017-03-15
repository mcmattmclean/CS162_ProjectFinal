/******************************************************************************
* Name: Courtyard.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Courtyard class implementation file, contains member function
**  definitions. Derived from room class.
******************************************************************************/
#include "Courtyard.hpp"

Courtyard::Courtyard(){
  setName("The Courtyard");
  setBlurb("The Courtyard seems oddly quiet, the regular hustle and bustle of students suspiciously absent.");
  setGraphic("graphics/courtyard-intro.txt");
}

void Courtyard::update(){
  if(gatePresentClosed){
    setGraphic("graphics/courtyard-gateclosed.txt");
    setBlurb("The gate is shut, and Arkham is safe. For now...");
  }
  else if(gatePresentOpen){
    setGraphic("graphics/courtyard-gate.txt");
    setBlurb("The massive gateway to somewhere else pulses, filling you with dread.");
    gatePresentOpen = false;//test
    gatePresentClosed = true;//test
  }
  else if(firstVisit){
    firstVisit = false;
    gatePresentOpen = true;
    setGraphic("graphics/courtyard-gate.txt");
    setBlurb("Suddenly, the sky twists, rending apart space and time as a horrifying whirlwind appears off in the distance.");
  }
}
