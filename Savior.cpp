/*************************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for Savior fighter class
 ** Date: 11/28/16
 *************************************************************/

#include "Savior.hpp"
using std::cout;
using std::endl;
/*****************************************************************
 ** Function: attack
 ** Description: Savior attack function, rolls 2x6 sided die.
 ** Parameters: N/a.
 ** Pre-Conditions: Attack not rolled.
 ** Post-Conditions:  Attack rolled.
 ** Return: Integer value for roll1 + roll2 for Saviors's attack.
 ****************************************************************/
int Savior::attack()
{
    // roll 2x6 die
    int roll1 = rand()%6+1;
    int roll2 = rand()%6+1;
    
    return roll1 + roll2;
}
/*******************************************************************
 ** Function: defend
 ** Description: Savior defend function.  Takes an attack, rolls
 ** 2x6 sided die in defense, calculates damage and updates strength.
 ** Parameters: Integer attack value.
 ** Pre-Conditions: Attack not defended and damage not applied.
 ** Post-Conditions:  If attack value exceeds defense value,
 ** damage is applied and strength is updated.
 ** Return: n/a.
 ******************************************************************/
void Savior::defend(int a)
{
    int attack = a;
    int defense, damage;
    
    // Roll 2x6 die.
    int roll1 = rand()%6+1;
    int roll2 = rand()%6+1;
    defense = roll1+roll2;
    
    //   cout << "Savior defense: " << defense << endl;
    
    damage = (attack - defense) - getArmor();
    
    if(damage > 0)
    {
        //      cout << "Savior damage: " << damage << endl;
        setStrength(getStrength()-damage);
    }
    else if(damage <= 0)
    {
        //     cout << "Attack defended 0 damage!" << endl;
    }
}
/*******************************************************************
 ** Function: heal
 ** Description: Savior heal function.  If Savior is less than
 ** initial strength, recovers 25% of the damage incurred.
 ** Parameters: N/a.
 ** Pre-Conditions: Strength not yet recovered.
 ** Post-Conditions:  25% of damage inflicted is recovered.
 ** Return: n/a.
 ******************************************************************/
void Savior::heal()
{
    if(getStrength() < 12)
    {
        int diff;  // Diff is damage inflicted last round.
        diff = 12-getStrength();
        if(diff == 1) // To prevent 1/2 point rounding down to 0.
        {
            diff = 2;
        }
        setStrength(getStrength()+((25 * diff)/100));
      //  cout << "Savior healed " << ((25 * diff)/100) << " points." << endl;
    }
}
Savior::~Savior()
{
    // Used for testing.
    // cout << "Savior deleted" << endl;
}