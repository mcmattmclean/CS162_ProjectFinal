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

void Courtyard::printState(){}
