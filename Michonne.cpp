/*************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for derived
 ** fighter class for character Michonne.
 ** Date: 11/28/16
 ************************************************/

#include "Michonne.hpp"
/*******************************************************************
 ** Function: attack
 ** Description: Michonne attack function, rolls 3x6 sided die.
 ** Parameters: N/a.
 ** Pre-Conditions: Attack not rolled.
 ** Post-Conditions:  Attack rolled.
 ** Return: Integer value for roll1 + roll2 for Michonne's attack.
 ******************************************************************/
int Michonne::attack()
{
    int roll, roll1, roll2, roll3;
    // Roll 2x6 die.
    roll1 = rand()%6+1;
    // cout << "roll1 " << roll1 << endl;
    roll2 = rand()%6+1;
    // cout << "roll2: " << roll2 << endl;
    roll3 = rand()%6+1;
    roll = roll1+roll2+roll3;
    
    if(roll == 18)
    {
        cout << "Michonne's sword strike!" << endl;
        roll = 100;
    }
    return roll;
}
/*******************************************************************
 ** Function: defend
 ** Description: Michonne defend function.  Takes an attack, rolls
 ** 1x5 sided die in defense, calculates damage and updates strength.
 ** Parameters: Integer attack value.
 ** Pre-Conditions: Attack not defended and damage not applied.
 ** Post-Conditions:  If attack value exceeds defense value,
 ** damage is applied and strength is updated.
 ** Return: n/a.
 ******************************************************************/
void Michonne::defend(int a)
{
    int attack = a;
    int defense, damage;
    
    // Roll 1x5 die.
    int roll1 = rand()%5+1;
    defense = roll1;
    //cout << "Michonne defense: " << roll1 << endl;
    
    damage = (attack - defense) - getArmor();
    
    
    if(damage > 0)
    {
    //    cout << "Michonne damage: " << damage << endl;
        setStrength(getStrength()-damage);
    }
    else if(damage <= 0)
    {
    //    cout << "Attack defended 0 damage!" << endl;
    }
}
/*******************************************************************
 ** Function: heal
 ** Description: Michonne heal function.  If Michonne is less than
 ** initial strength, recovers half the damage incurred.
 ** Parameters: N/a.
 ** Pre-Conditions: Strength not yet recovered.
 ** Post-Conditions:  50% of damage inflicted is recovered.
 ** Return: n/a.
 ******************************************************************/
void Michonne::heal()
{
    if(getStrength() < 20)
    {
        int diff; // Diff is damage inflicted last round.
        diff = 20-getStrength();
        if(diff == 1) // To prevent 1/2 point rounding down to 0.
        {
            diff = 2;
        }
        setStrength(getStrength()+(diff/2));
       // cout << "Michonne healed " << (diff/2) << " points." << endl;
    }
}
Michonne::~Michonne()
{
    // Used for testing.
  //  cout << "delete michonne" << endl;
}