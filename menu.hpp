/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for simple menu functions.
 ** Date: 11/28/16
 *****************************************************/

#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>
#include <iostream>
#include "fighter.hpp"
#include "Rick.hpp"
#include "Michonne.hpp"
#include "Daryl.hpp"

// Function to select direction to move.
int move();
// Function to select initial player character.
Fighter* selection();
// Select additional fighters to join team for boss battle.
Fighter* selectTeam(Fighter*);

#endif /* menu_hpp */
