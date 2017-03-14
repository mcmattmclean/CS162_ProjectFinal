#include "util.hpp"

void printGraphic(string fileName){
  for(int i = 0; i < 800; i++){
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
