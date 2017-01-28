/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for grid class, which 
 ** creates 2D gameboard filled with spaces.
 ** Date: 11/28/16
 *****************************************************/

#ifndef grid_hpp
#define grid_hpp

#include <stdio.h>
#include <iostream>
#include "fighter.hpp"
#include "Rick.hpp"
#include "space.hpp"
#include "walker.hpp"
#include "negansmen.hpp"
#include "hilltop.hpp"
#include "armory.hpp"
#include "horde.hpp"
#include "kingdom.hpp"
#include "prison.hpp"
#include <stack>

using std::cout;
using std::endl;

class Space;

class Grid{
    
private:
    Space*** grid;
    int row, col;
    int playRow, playCol;
    int gridSize;
    Fighter* player;
    Space* location;
    bool Ezekiel;
    
public:
    // Constructor.
    Grid();
    // Returns grid.
    Space*** getGrid();
    // Returns space pointer.
    Space* getSpace(int, int);
    // Initializes board with spaces.
    void setBoard();
    // Sets player in a space.
    void setPlayer(int, int, Fighter*);
    // Returns fighter from a space.
    Fighter* getPlayer();
    // Moves player and calls turn for each turn.
    void makeMove(int);

    // Displays grid.
    void print();
    
    ~Grid();
};
#endif /* grid_hpp */
