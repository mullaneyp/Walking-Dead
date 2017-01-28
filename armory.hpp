/************************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived Armory space class.
 ** Armory space allows player to trade all guns for a key.
 ** Date: 11/28/16
 ************************************************************/

#ifndef armory_hpp
#define armory_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "space.hpp"
#include "grid.hpp"
#include "fighter.hpp"
#include "Rick.hpp"

using std::cout;
using std::endl;

class Armory : public Space{
private:
    Space*** grid;
    char symbol;
    int row, col;
    string name;
    int guns;
    int food;
    int key;
    
public:
    // Constructor #1, intialized symbol to 'A'.
   // Armory(Space*** grid, int row, int col) : Space ('A', "Armory",grid, row, col), key(1),guns(20),food(0) {}
    
    // Second constructor, allowed to change symbol in map initialization to create a better map.
    Armory(char symbol, Space*** grid, int row, int col) : Space (symbol, "Armory",grid, row, col), key(1),guns(20),food(0) {}
    
    // Get and set methods for food and guns.
    void setFood(int);
    int getFood();
    void setGuns(int);
    int getGuns();
    // Implementation of virtual turn.
    void turn();
    
    // Deconstructor.
    ~Armory();
};
#endif /* armory_hpp */
