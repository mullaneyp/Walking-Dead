/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived fighter class
 ** for Savior, Negan's troops.  
 ** Date: 11/28/16
 *****************************************************/
#ifndef Savior_hpp
#define Savior_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>
#include "fighter.hpp"
#include <string>

using std::cout;
using std::endl;
using std::string;

class Savior : public Fighter {
    
protected:
    int armor;
    int strength;
    string type;
    
public:
    // Constructor
    Savior() : Fighter("Savior", 12, 0, 'S', 5){};
    // Implementation of virtual attack, defend, and heal methods.
    int attack();
    void defend(int);
    void heal();
    // Deconstructor
    ~Savior();
};
#endif /* Savior_hpp */
