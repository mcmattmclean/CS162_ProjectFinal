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
