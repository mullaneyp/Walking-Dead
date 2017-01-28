/************************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived Kingdom space class.
 ** Kingdom space is where traversing the map will end and
 ** boss battle will begin.
 ** Date: 11/28/16
 ************************************************************/

#ifndef kingdom_hpp
#define kingdom_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "space.hpp"
#include "grid.hpp"
#include "fighter.hpp"
#include "Rick.hpp"
#include "Ezekiel.hpp"

using std::cout;
using std::endl;

class Kingdom : public Space{
private:
    Space*** grid;
    char symbol;
    int row, col;
    string name;
    
    Fighter* computer;
    int guns;
    int food;
    int key;
    bool zeke;
    
public:
    // Constructor.
    Kingdom(char symbol, Space*** grid, int row, int col) : Space (symbol, "Kingdom", grid, row, col), food(0) {}
    
    // Get and set methods for food.
    void setFood(int);
    int getFood();
    
    // Virtual turn method.
    void turn();
    
    // Deconstructor.
    ~Kingdom();
};
#endif /* kingdom_hpp */
