/******************************************************************************
* Name: util.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Utility function definitions to facilitate common functionality.
******************************************************************************/
#include "util.hpp"

/******************************************************************************
* Function: getNumLines()
*
* Description: Opens file matching passed string, determines how many lines,
**  then returns this number. Used to determine spacing of user menu with
**  graphics.
******************************************************************************/
int getNumLines(string fileName){
  int length = 0;
  ifstream graphic;
  string line;
  graphic.open(fileName);

  while (getline(graphic, line)){
    length++;
  }

  graphic.close();

  return length;
}

/******************************************************************************
* Function: printGraphic()
*
* Description: Prints new lines to clear space in the terminal for new graphic.
* Then opens the file matching the string passed to it and displayes the file.
******************************************************************************/
void printGraphic(string fileName){
  for(int i = 0; i < 200; i++){ //Print new lines
    cout << endl;
  }

  ifstream textImg;
  char input;

  cout << endl;
  textImg.open(fileName);
  while(textImg.get(input)){
    std::cout << input;
  }
  textImg.close();
  cout << endl;
}

/*****************************************************************************
* Function: validateInt.cpp
*
* Description: Attempts to read an int. If invalid, it returns -1, else it
**  returns the input integer.
*****************************************************************************/
int validateInt(int min, int max){
  int userInt = -1;

  std::cin >> userInt;  //Read user input

  if(std::cin.fail() || userInt < min || userInt > max){
    std::cin.clear();
    std::cin.ignore(256, '\n');
    userInt = -1;
  }

  return userInt;
}
