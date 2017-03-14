#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){

  string test1 = "graphics/setup.txt";
  string test2 = "graphics/basic-room.txt";

  ifstream textImg;
  char input;

  for(int i = 0; i < 800; i++){
    cout << endl;
  }

  cout << endl;
  textImg.open(test1);
  while(textImg.get(input)){
    std::cout << input;
  }
  textImg.close();
  cout << endl;

  cin.get();

  for(int i = 0; i < 800; i++){
    cout << endl;
  }

  cout << endl;
  textImg.open(test2);
  while(textImg.get(input)){
    std::cout << input;
  }
  textImg.close();
  cout << endl;


  return 0;
}
