#include <iostream>
#include <fstream>
#include <string>
#include "util.hpp"

using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){

  string test1 = "graphics/setup.txt";
  string test2 = "graphics/basic-room.txt";

  printGraphic(test1);
  cin.get();
  printGraphic(test2);

  return 0;
}
