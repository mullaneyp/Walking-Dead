/*******************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived fighter class
 ** for character Daryl.  Daryl has a special bow attack
 ** and heals faster than any other character (70%).
 ** Date: 11/28/16
 *******************************************************/

#ifndef Daryl_hpp
#define Daryl_hpp

#include <stdio.h>
#include <iostream>
#include "fighter.hpp"

using std::cout;
using std::endl;

class Daryl : public Fighter{
    
protected:
    int armor;
    int strength;
    string name;
    
public:
    // Constructor
    Daryl() : Fighter ("Daryl", 35, 4, 'D', 5) {}
    // Virtual methods
    int attack();
    void defend(int);
    void heal();
    // Deconstructor
    ~Daryl();
};
#endif /* Daryl_hpp */
