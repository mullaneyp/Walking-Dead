/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for Rick.
 ** Date: 11/28/16
 *****************************************************/

#include "Rick.hpp"
/**************************************************************
 ** Function: attack
 ** Description: Rick attack function, rolls 2x6 sided die.
 ** Parameters: N/a.
 ** Pre-Conditions: Attack not rolled.
 ** Post-Conditions:  Attack rolled.
 ** Return: Integer value for roll1 + roll2 for Rick's attack.
 **************************************************************/
int Rick::attack()
{
    // Roll 2x6 die.
    int roll1 = rand()%6+1;
    int roll2 = rand()%6+1;
    
    return roll1 + roll2;
}
/*******************************************************************
 ** Function: defend
 ** Description: Rick defend function.  Takes an attack, rolls
 ** 2x6 sided die in defense, calculates damage and updates strength.
 ** Rick's special ability is he has one extra life.
 ** Parameters: Integer attack value.
 ** Pre-Conditions: Attack not defended and damage not applied.
 ** Post-Conditions:  If attack value exceeds defense value,
 ** damage is applied and strength is updated.
 ** Return: n/a.
 ******************************************************************/
void Rick::defend(int a)
{
    int attack = a;
    int defense, damage, roll1, roll2, rick;
    
    // Roll 2x6 die.
    roll1 = rand()%6+1;
    roll2 = rand()%6+1;
    defense = roll1 + roll2;
    cout << "Rick defense " << defense << endl;
    
    damage = (attack - defense) - getArmor();
    
    if(damage > 0)
    {
        cout << "Rick damage: " << damage << endl;
        setStrength(getStrength()-damage);
    }
    else if(damage <= 0)
    {
           cout << "Attack defended 0 damage!" << endl;
    }
    // Resurrected
    if(life == 1)
    {
        rick = getStrength();
        if(rick <= 0)
        {
            setStrength(20);
            cout << "Rick revived!" << endl;
            life--;
        }
    }
}
/**************************************************************************
 ** Function: heal
 ** Description: Rick heal function.  If Rick is less than
 ** initial strength, recovers half the damage incurred.
 ** Parameters: N/a.
 ** Pre-Conditions: Strength not yet recovered.
 ** Post-Conditions:  50% of damage inflicted is recovered.
 ** Return: n/a.
 **************************************************************************/
void Rick::heal()
{
    if(getStrength() < 25)
    {
        int diff; // Diff is damage inflicted last round.
        diff = 25-getStrength();
        if(diff == 1) // To prevent 1/2 point rounding down to 0.
        {
            diff = 2;
        }
        setStrength(getStrength()+(diff/2));
       // cout << "Rick healed " << (diff/2) << " points." << endl;
    }
}
Rick::~Rick()
{
    // Used for testing.
     //cout << "delete rick" << endl;
}