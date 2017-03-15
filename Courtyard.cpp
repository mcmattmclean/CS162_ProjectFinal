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
  setBlurb("You finally arrive at Miskatonic University's courtyard, late for class yet again. \nBetter hurry to class before Professor Harvey notices your absence.");
  setGraphic("graphics/courtyard-intro.txt");
}

void Courtyard::update(){
  if(gatePresentClosed){
    setGraphic("graphics/courtyard-gateclosed.txt");
    setBlurb("The gate is shut, and Arkham is safe. For now...");
  }
  else if(gatePresentOpen){
    setBlurb("The massive gateway to somewhere else pulses, filling you with dread.");
  }
  else if(firstVisit){
    firstVisit = false;
    gatePresentOpen = true;
    setGraphic("graphics/courtyard-gate.txt");
    setBlurb("Before you take a single step, a terrible gate appears, emanating death. The buildings \nnear it sprout giant tentacles, and you feel your sanity slipping away as the seconds\npass.");
  }
}
