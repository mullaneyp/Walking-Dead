/*******************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived fighter class
 ** for character Michonne.  Michonne has a stronger 
 ** attack, a special sword attack, and can sneak by 
 ** walkers.
 ** Date: 11/28/16
 *******************************************************/

#ifndef Michonne_hpp
#define Michonne_hpp

#include <stdio.h>
#include <iostream>
#include "fighter.hpp"

using std::cout;
using std::endl;

class Michonne : public Fighter{
    
protected:
    int armor;
    int strength;
    string name;
    
public:
    // Constructor
    Michonne() : Fighter ("Michonne", 20, 8, 'M', 5) {}
    // Virtual methods
    int attack();
    void defend(int);
    void heal();
    // Deconstructor
    ~Michonne();
};

#endif /* Michonne_hpp */
