/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived Walker class.
 ** Date: 11/28/16
 *****************************************************/

#ifndef walker_hpp
#define walker_hpp

#include <stdio.h>
#include <iostream>
#include "space.hpp"
#include "fighter.hpp"

using std::cout;
using std::endl;
using std::string;

class Walker : public Fighter{
private:
    int armor;
    int strength;
    string type;
    
public:
    // Constructors.
    Walker() : Fighter("Walker", 12, 0, 'W', 5){};
    // Implementation of virtual attack, defend, and heal methods.
    int attack();
    void defend(int);
    void heal();
    // Deconstructor.
    ~Walker();
};
#endif /* walker_hpp */
