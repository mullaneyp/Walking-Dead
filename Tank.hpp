/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived fighter class
 ** for Tank.  Tank has significant hit points and can
 ** only be obtained by player getting key from 
 ** armory and giving the key to King Ezekiel.
 ** Given significant attack and strength, it is has 
 ** a weak heal ability.
 ** Date: 11/28/16
 *****************************************************/

#ifndef Tank_hpp
#define Tank_hpp

#include <stdio.h>
#include <iostream>
#include "fighter.hpp"

using std::cout;
using std::endl;

class Tank : public Fighter{
protected:
    int armor;
    int strength;
    string name;
    string type;
    int die;
    
public:
    // Constructor
    Tank() : Fighter ("Tank", 500, 3, 'T', 20), die(3) {}
    // Virtual implementation of attack, defend, and heal methods.
    int attack();
    void defend(int);
    void heal();
    // Deconstructor
    ~Tank();
};
#endif /* Tank_hpp */
