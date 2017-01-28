/*************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for derived
 ** fighter class for character King Ezekiel
 ** Date: 11/28/16
 ************************************************/

#include "Ezekiel.hpp"
/********************************************************************
 ** Function: attack
 ** Description: King Ezekiel attack function, rolls 2x8 sided die.
 ** Parameters: N/a.
 ** Pre-Conditions: Attack not rolled.
 ** Post-Conditions:  Attack rolled.
 ** Return: Integer value for roll1 + roll2 for King Ezekiel's attack.
 *********************************************************************/
int Ezekiel::attack()
{
    // Roll 2x8 sided die.
    int roll1 = rand()%8+1;
    int roll2 = rand()%8+1;
   // cout << "King ezekiel attack " << roll1+roll2 << endl;
    return roll1 + roll2;
}
/*******************************************************************
 ** Function: defend
 ** Description: King Ezekiel defend function.  Takes an attack, rolls
 ** 3x8 sided die in defense, calculates damage and updates strength.
 ** King Ezekiel loses a die as more damage is sustained.  Also 
 ** notified user each time a die is lost.
 ** Parameters: Integer attack value.
 ** Pre-Conditions: Attack not defended and damage not applied.
 ** Post-Conditions:  If attack value exceeds defense value,
 ** damage is applied and strength is updated.
 ** Return: n/a.
 ******************************************************************/
void Ezekiel::defend(int a)
{
    int attack = a;
    int defense, roll1, roll2, roll3, damage;
    int prerollStrength;
    // Track strength before roll to determine and output if a die is lost.
    prerollStrength = getStrength();
    
    // Roll 3x8 die.
    roll1 = rand()%8+1;
    roll2 = rand()%8+1;
    roll3 = rand()%8+1;
    
    if(getStrength() > 30)
    {
        defense = (roll1 + roll2 + roll3);
    }
    else if((getStrength() > 20) && (getStrength() < 31))
    {
        defense = (roll1 + roll2);
    }
    else if((getStrength() < 15))
        defense = roll1;
    
    damage = (attack - defense) - getArmor();
    
    if(damage > 0)
    {
        setStrength(getStrength()-damage);
        if((prerollStrength > 20) && (getStrength() < 31))
        {
            if(getStrength() > 14)
            {
                cout << "King Ezekiel lost a die, 2 die left." << endl;
            }
            else if(getStrength() < 15)
            {
                cout << "King Ezekiel lost 2 die, 1 die left." << endl;
            }
        }
        else if((prerollStrength > 14) && (getStrength() < 15))
        {
            cout << "King Ezekiel lost 2 die, 1 die left." << endl;
        }
    }
    else if(damage <= 0)
    {
        //     cout << "Attack defended 0 damage!" << endl;
    }
}
/*******************************************************************
 ** Function: heal
 ** Description: King Ezekiel heal function.  If King Ezekiel is less 
 ** than initial strength, recovers 60% the damage incurred.
 ** Parameters: N/a.
 ** Pre-Conditions: Strength not yet recovered.
 ** Post-Conditions:  60% of damage inflicted is recovered.
 ** Return: n/a.
 ******************************************************************/
void Ezekiel::heal()
{
    if(getStrength() < 35)
    {
        int diff; // Diff is damage inflicted last round.
        diff = 35-getStrength();
        if(diff == 1) // To prevent 1/2 point rounding down to 0.
        {
            diff = 2;
        }
        setStrength(getStrength()+((6 * diff)/10));
      //  cout << "King Ezekiel healed " << ((6 * diff)/10) << " points." << endl;
    }
}
Ezekiel::~Ezekiel()
{
    // Used for testing.
   // cout << "King Ezekiel died!" << endl;
}