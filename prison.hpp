/************************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived Prison space class.
 ** Prison allows player to raid for food and guns, but may
 ** be attacked by a walker.
 ** Date: 11/28/16
 ************************************************************/

#ifndef prison_hpp
#define prison_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "space.hpp"
#include "grid.hpp"
#include "fighter.hpp"
#include "Rick.hpp"
#include "walker.hpp"

using std::cout;
using std::endl;

class Prison : public Space{
private:
    Space*** grid;
    char symbol;
    int row, col;
    string name;
    int guns;
    int food;
    int key;
    Fighter* computer;
    
public:
    // Constructor #1, initialized symbol to P.
    //Prison(Space*** grid, int row, int col) : Space ('P', "Prison",grid, row, col),guns(20),food(0), computer(new Walker()){}
    
    // Constructor 2, allowed to initialize symbol with different characters to improve map.
    Prison(char symbol, Space*** grid, int row, int col) : Space (symbol, "Prison",grid, row, col),guns(20),food(0), computer(new Walker()) {}
    
    void setFood(int);
    int getFood();
    void setGuns(int);
    int getGuns();
    void turn();
    
    // Deconstructor.
    ~Prison();
};
#endif /* prison_hpp */
