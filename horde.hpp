/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived Horde class.
 ** Horde class is initialized as occupied by a walker
 ** fighter and the player may fight the walker to win
 ** food.
 ** Date: 11/28/16
 *****************************************************/
#ifndef horde_hpp
#define horde_hpp

#include <stdio.h>
#include <iostream>
#include "fighter.hpp"
#include "walker.hpp"

using std::cout;
using std::endl;
using std::cin;

class Horde : public Space{
private:
    Space*** grid;
    char symbol;
    int row, col;
    Fighter* computer;
    int food;
    string name;
    
public:
    // Constructors.
    // Initial constructor set all spaces with char '.'.
   // Horde(Space*** grid, int row, int col) : Space ('.', "Surrounded by Horde", grid, row, col),food(20), computer(new Walker()){}
    
    // Second constructor to allow initialize of map with different char symbols.
    Horde(char symbol, Space*** grid, int row, int col) : Space (symbol, "Surrounded by Horde", grid, row, col),food(20), computer(new Walker()){}
    // Get and set methods for food.
    void setFood(int);
    int getFood();
    // Implementation of virtual turn.
    void turn();
    
    // Deconstructor.
    ~Horde();
};
#endif /* horde_hpp */
