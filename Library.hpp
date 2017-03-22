/******************************************************************************
* Name: Library.hpp
* Date: 14 Mar 2017
* Author: Matthew McLean
* Description: Library class header file, contains protected member
**  variable declarations and member function prototypes.
******************************************************************************/
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Room.hpp"

class Library : public Room{
private:
  bool firstVisit = true;
public:
  Library();
  void explore(Player*);

};


#endif
