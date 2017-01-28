/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for parent fighter class.
 ** Fighter class is an abstract class for various 
 ** fighters or "characters" for game.
 ** Date: 11/28/16
 *****************************************************/

#ifndef fighter_hpp
#define fighter_hpp

#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include "Item.hpp"

using std::string;
using std::cout;
using std::endl;

// Forward declaration.
class Grid;
class Space;

class Fighter{
    
protected:
    Space ***grid;
    Space *location;
    int row, col;
    char symbol;
    int armor;
    int strength;
    string type;
    int guns;
    int food;
    Item** satchel;
    bool key;
    bool tank;
    
public:
    // Constructor
    //Initial constructor worked, but changed to #2 to better initialize satchel.
   // Fighter(string type, int strength, int armor, char symbol, int guns) : type(type), strength(strength), armor(armor), symbol(symbol), guns(guns), food(5){ srand((unsigned)time(NULL)); satchel = new Item*[2];};
    
    // Constructor
    Fighter(string type, int strength, int armor, char symbol, int guns);
    
    // Virtual attack, defense, and heal functions.
    int virtual attack() =0;
    void virtual defend(int) =0;
    void virtual heal() =0;
    
    // Get and set methods for strength.
    int getStrength();
    void setStrength(int);
    // Get methods for char, type, and armor.
    string getType();
    int getArmor();
    char getChar();
    // Get and set methods for key and tank bool values.
    bool getKey();
    void setKey(bool);
    bool getTank();
    void setTank(bool);
    
    // Get and set methods for food and gun item quantities.
    void setGuns(int);
    int getGuns();
    void setFood(int);
    int getFood();
    
    // Get and set locations for player location.
    void setLoc(Space*);
    Space* getLoc();
    
    // Method to add item to satchel.
    void addItem(Item*);
    // Method to get satchel.
    Item** getSatchel();
  
    // Used to deallocate memory for fighter objects.
    void free();
    
    // Deconstructor
    virtual ~Fighter();
};
#endif /* fighter_hpp */


    


