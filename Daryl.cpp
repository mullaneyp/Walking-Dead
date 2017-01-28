/*************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for derived 
 ** fighter class for character Daryl.
 ** Date: 11/28/16
 ************************************************/

#include "Daryl.hpp"
/**************************************************************
 ** Function: attack
 ** Description: Daryl attack function, rolls 2x6 sided die.
 ** Daryl also has a special attack, a 1/18 chance of of an 
 ** attack of 18 points, indicating a direct shot.
 ** Parameters: N/a.
 ** Pre-Conditions: Attack not rolled.
 ** Post-Conditions:  Attack rolled.
 ** Return: Integer value for roll for Daryl's attack.
 **************************************************************/
int Daryl::attack()
{
    int roll, roll1, roll2, bow;
    // Roll 2x6 die.
    roll1 = rand()%6+1;
    // cout << "roll1 " << roll1 << endl;
    roll2 = rand()%6+1;
    // cout << "roll2: " << roll2 << endl;
    roll = roll1+roll2;
    
    bow = rand()%18+1;
    if(bow == 18)
    {
        cout << "Dary's bow! Direct shot!" << endl;
        roll = 50;
    }
    return roll;
}
/*******************************************************************
 ** Function: defend
 ** Description: Daryl defend function.  Takes an attack, rolls
 ** 1x6 sided die in defense, calculates damage and updates strength.
 ** Parameters: Integer attack value.
 ** Pre-Conditions: Attack not defended and damage not applied.
 ** Post-Conditions:  If attack value exceeds defense value,
 ** damage is applied and strength is updated.
 ** Return: n/a.
 ******************************************************************/
void Daryl::defend(int a)
{
    int attack = a;
    int defense, damage;
    
    // Roll 1x6 die.
    int roll1 = rand()%6+1;
    defense = roll1;
    
    damage = (attack - defense) - getArmor();
    
    
    if(damage > 0)
    {
        cout << "Daryl damage " << damage << endl;
        setStrength(getStrength()-damage);
    }
    else if(damage <= 0)
    {
     //   cout << "Attack defended 0 damage!" << endl;
    }
}
/*******************************************************************
 ** Function: heal
 ** Description: Daryl heal function.  If Daryl is less than
 ** initial strength, recovers 70% the damage incurred.
 ** Parameters: N/a.
 ** Pre-Conditions: Strength not yet recovered.
 ** Post-Conditions:  70% of damage inflicted is recovered.
 ** Return: n/a.
 ******************************************************************/
void Daryl::heal()
{
    if(getStrength() < 35)
    {
        int diff; // Diff is damage inflicted last round.
        diff = 35-getStrength();
        if(diff == 1) // To prevent 1/2 point rounding down to 0.
        {
            diff = 2;
        }
        setStrength(getStrength()+((diff * 7)/10));
      //  cout << "Daryl healed " << ((diff * 7)/10) << " points." << endl;
    }
}
Daryl::~Daryl()
{
    // Used for testing.
 //   cout << "delete daryl" << endl;
}