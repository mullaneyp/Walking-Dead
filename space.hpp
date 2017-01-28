/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for parent space class.
 ** Space class is an abstract class for various
 ** spaces that will occupy the map for the game.
 ** Date: 11/28/16
 *****************************************************/

#ifndef space_hpp
#define space_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "fighter.hpp"

using std::cout;
using std::endl;

// Forward declaration.
class Grid;

class Space{
protected:
    Space ***grid; 
    int row, col;
    char symbol;
    string name;
    bool zeke;
    Space *top, *bottom, *left, *right;
    Fighter* player;
    Fighter* computer;
    
public:
    // Constructor.
    Space(char symbol, string name, Space ***grid, int row, int col);
    
    // Get and set methods for linked spaces.
    void setTop(Space*);
    void setBottom(Space*);
    void setLeft(Space*);
    void setRight(Space*);
    Space* getTop();
    Space* getBottom();
    Space* getLeft();
    Space* getRight();
    
    // Get methods for player controlled and computer fighters.
    Fighter* getPlayer();
    Fighter* getComputer();
    // Get and set methods for player symbol.
    char getChar();
    void setSymbol(char);
    // Get method for fighter names.
    string getName();
    // Set method for player controlled fighter.
    void setPlayer(Fighter*);
    // Get and set methods for bool zeke, which determines whether King Ezekiel will join fight.
    void setZeke(bool);
    bool getZeke();
    // Used to deallocate fighter objects.
    void free();
    
    // Virtual methods.  Turn is the special action of the space for each turn of the game.
    void virtual turn()=0;
    virtual ~Space();
};

#endif /* space_hpp */
