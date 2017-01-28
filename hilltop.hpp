/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived Hilltop class.
 ** Hilltop class is a "safe" space for player and 
 ** allows player to trade food to heal or trade guns 
 ** for food.
 ** Date: 11/28/16
 *****************************************************/

#ifndef hilltop_hpp
#define hilltop_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "space.hpp"
#include "grid.hpp"
#include "fighter.hpp"
#include "Rick.hpp"

using std::cout;
using std::endl;

class Hilltop : public Space{
private:
    Space*** grid;
    char symbol;
    int row, col;
    string name;
    int guns;
    int food;
    
public:
    // Constructor.
    Hilltop(char symbol, Space*** grid, int row, int col) : Space (symbol, "Hilltop", grid, row, col), food(10) {}
    
    // Get and set for food.
    void setFood(int);
    int getFood();
    // Implementation for virtual turn.
    void turn();
    
    // Deconstructor.
    ~Hilltop();
};

#endif /* hilltop_hpp */
