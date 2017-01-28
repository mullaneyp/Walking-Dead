/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived space class.
 ** Negansmen class is initialized as occupied by a
 ** Savior fighter and the player may fight Savior to
 ** obtain guns.  If savior dies, they become a walker.
 ** Date: 11/28/16
 *****************************************************/

#ifndef negansmen_hpp
#define negansmen_hpp

#include <stdio.h>
#include <iostream>
#include "space.hpp"
#include "Savior.hpp"
#include "walker.hpp"

using std::cout;
using std::endl;
using std::cin;

class Space;

class Negansmen: public Space{
private:
    Space*** grid;
    char symbol;
    int guns;
    string name;
    Fighter* computer;
    
public:
    // Constructor #1.  Worked correctly to initialize space char to '.'
    //Negansmen(Space*** grid, int row, int col) : Space ('.',"Surrounded by Saviors",grid, row, col), guns(5), computer(new Savior()){}
    
    // Constructor #2, allows initializes different symbols to draw better map.
    Negansmen(char symbol, Space*** grid, int row, int col) : Space (symbol,"Surrounded by Saviors",grid, row, col), guns(5), computer(new Savior()){}
    
    // Get and set methods for guns.
    void setGuns(int);
    int getGuns();
    
    // Virtual methods.
    void turn();
    // Deconstructor
    ~Negansmen();
};
#endif /* negansmen_hpp */
