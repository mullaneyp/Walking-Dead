/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived fighter class
 ** for boss Negan.  Negan has high strength points 
 ** and a strong defense using multiple die.
 ** Date: 11/28/16
 *****************************************************/

#ifndef Negan_hpp
#define Negan_hpp

#include <stdio.h>
#include <iostream>
#include "fighter.hpp"

using std::cout;
using std::endl;

class Negan : public Fighter{
protected:
    int armor;
    int strength;
    string name;
    string type;
    int die;
    
public:
    // Constructor
    Negan() : Fighter ("NEGAN", 150, 3, 'N', 20), die(3) {}
    // Implementation of virtual attack, defend, and heal methods.
    int attack();
    void defend(int);
    void heal();
    // Deconstructor.
    ~Negan();
};
#endif /* Negan_hpp */
