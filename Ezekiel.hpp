/*******************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for derived fighter class
 ** for character King Ezekiel.  King Ezekiel is not able
 ** to be selected by player, but fights with player if
 ** player gives all food to King Ezekiel at The Kingdom.
 ** Ezekiel has a strong defense.
 ** Date: 11/28/16
 *******************************************************/

#ifndef Ezekiel_hpp
#define Ezekiel_hpp

#include <stdio.h>
#include "fighter.hpp"

using std::cout;
using std::endl;

class Ezekiel : public Fighter{
    
protected:
    int armor;
    int strength;
    string name;
    bool fight;
    
public:
    // Constructor
    Ezekiel() : Fighter ("King Ezekiel", 35, 8, 'Z', 0), fight(false) {}
    // Virtual methods
    int attack();
    void defend(int);
    void heal();
    // Deconstructor
    ~Ezekiel();
};
#endif /* Ezekiel_hpp */
