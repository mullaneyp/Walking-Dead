/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived fighter class
 ** for character Rick.  Rick's unique ability is
 ** an extra "life" as he can be revived one time.
 ** Date: 11/28/16
 *****************************************************/

#ifndef Rick_hpp
#define Rick_hpp

#include <stdio.h>
#include <iostream>
#include "fighter.hpp"

using std::cout;
using std::endl;

class Rick : public Fighter{
    
protected:
    int armor;
    int strength;
    int guns;
    int food;
    int life;
    char symbol;
    
public:
    // Constructor.
    Rick() : Fighter ("Rick", 25, 0, 'R', 5), life(1), food(5) {};
    // Implementation for virtual functions.
    int attack();
    void defend(int);
    void heal();
    // Destructor.
    ~Rick();
};

#endif /* Rick_hpp */
