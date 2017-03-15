/******************************************************************************
* Name: util.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Utility function prototypes
******************************************************************************/

#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::getline;

int validateInt(int, int);
void printGraphic(string);
int getNumLines(string);

#endif
