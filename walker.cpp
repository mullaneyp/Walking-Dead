/******************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for Walker class.
 ** Date: 11/28/16
 ******************************************************/

#include "walker.hpp"
using std::cout;
using std::endl;

/**************************************************************
 ** Function: attack
 ** Description: Walker attack function, rolls 1x10 sided die.
 ** Parameters: N/a.
 ** Pre-Conditions: Attack not rolled.
 ** Post-Conditions:  Attack rolled.
 ** Return: Integer value for roll  Walkers's attack.
 **************************************************************/
int Walker::attack()
{
    // Roll 1x10 die.
    int roll = rand()%10+1;
    
    return roll;
}
/*******************************************************************
 ** Function: defend
 ** Description: Walker defend function.  Takes an attack, rolls
 ** 2x6 sided die in defense, calculates damage and updates strength.
 ** Parameters: Integer attack value.
 ** Pre-Conditions: Attack not defended and damage not applied.
 ** Post-Conditions:  If attack value exceeds defense value,
 ** damage is applied and strength is updated.
 ** Return: n/a.
 ******************************************************************/
void Walker::defend(int a)
{
    int attack = a;
    int defense, damage;
    
    // Roll 2x6 die.
    int roll1 = rand()%6+1;
    int roll2 = rand()%6+1;
    defense = roll1+roll2;
    
    damage = (attack - defense) - getArmor();
    
    if(damage > 0)
    {
        setStrength(getStrength()-damage);
    }
    else if(damage <= 0)
    {
        //     cout << "Attack defended 0 damage!" << endl;
    }
}
/*******************************************************************
 ** Function: heal
 ** Description: Walker heal function.  If Walker is less than
 ** initial strength, recovers 75% the damage incurred.
 ** Parameters: N/a.
 ** Pre-Conditions: Strength not yet recovered.
 ** Post-Conditions: 75% of damage inflicted is recovered.
 ** Return: n/a.
 ******************************************************************/
void Walker::heal()
{
    if(getStrength() < 12)
    {
        int diff;  // Diff is damage inflicted last round.
        diff = 12-getStrength();
        if(diff == 1) // To prevent 1/2 point rounding down to 0.
        {
            diff = 2;
        }
        setStrength(getStrength()+((diff * 3)/4));
       // cout << "Walker healed " << ((diff * 3)/4) << " points." << endl;
    }
}
Walker::~Walker()
{
  //  cout << "walker deleted " << endl;
}