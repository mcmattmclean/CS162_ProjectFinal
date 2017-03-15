/*****************************************************************************
* Name: validateInt.cpp
* Author: Matthew McLean
* Date: 25 Feb 2017
* Description: This is the implementation file for the validateInt function and
**	contains its definition. validateInt prompts the user for an integer input,
**  and loops until valid input is received. Valid input is defined as an integer
**  from the passed min value to the INT_MAX value of climits.
*****************************************************************************/

#include <iostream>
#include "validateInt.hpp"

int validateInt(int min, int max, string curGraphic, ){
  int userInt;

  std::cin >> userInt;  //Read user input

  while (std::cin.fail() || userInt < min || userInt > max){  //Loop until valid
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cout << "Sorry please enter a valid integer: ";
    std::cin >> userInt;
  }

  std::cin.clear();
  std::cin.ignore(256, '\n');

  return userInt;
}
