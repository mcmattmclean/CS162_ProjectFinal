/******************************************************************************
* Name: util.cpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Utility function definitions to facilitate common functionality.
******************************************************************************/
#include "util.hpp"


/******************************************************************************
* Function: printGraphic()
*
* Description: Prints new lines to clear space in the terminal for new graphic.
* Then opens the file matching the string passed to it and displayes the file.
******************************************************************************/
void printGraphic(string fileName){
  for(int i = 0; i < 800; i++){ //Print new lines
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
