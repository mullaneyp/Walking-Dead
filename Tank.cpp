/*************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for derived
 ** fighter class for character Tank.
 ** Date: 11/28/16
 ************************************************/

#include "Tank.hpp"
/**************************************************************
 ** Function: attack
 ** Description: Tank attack function, rolls 1x100 sided die.
 ** Parameters: N/a.
 ** Pre-Conditions: Attack not rolled.
 ** Post-Conditions:  Attack rolled.
 ** Return: Integer value for roll for Tank's attack.
 **************************************************************/
int Tank::attack()
{
    // Roll 100 sided die.
    int roll = rand()%100+1;
    
    return roll;
}
/*******************************************************************
 ** Function: defend
 ** Description: Tank defend function.  Takes an attack, rolls
 ** 3x6 sided die in defense, calculates damage and updates strength.
 ** For every 4 points of strength that blue men lose, they lose a
 ** defense die.  Also notified user each time a die is lost.
 ** Parameters: Integer attack value.
 ** Pre-Conditions: Attack not defended and damage not applied.
 ** Post-Conditions:  If attack value exceeds defense value,
 ** damage is applied and strength is updated.
 ** Return: n/a.
 ******************************************************************/
void Tank::defend(int a)
{
    int attack = a;
    int defense, roll1, roll2, roll3, damage;
    int prerollStrength;
    // Track strength before roll to determine and output if a die is lost.
    prerollStrength = getStrength();
    
    // Roll 3x6 die.
    roll1 = rand()%6+1;
    roll2 = rand()%6+1;
    roll3 = rand()%6+1;
    
    if(getStrength() > 350)
    {
        defense = (roll1 + roll2 + roll3);
    }
    else if((getStrength() > 100) && (getStrength() < 251))
    {
        defense = (roll1 + roll2);
    }
    else if((getStrength() < 101))
        defense = roll1;
    //  cout << "Tank defense roll: " << defense  << endl;
    
    damage = (attack - defense) - getArmor();
    
    if(damage > 0)
    {
        //      cout << "Tank damage: " << damage << endl;
        setStrength(getStrength()-damage);
        if((prerollStrength > 8) && (getStrength() < 9))
        {
            if(getStrength() > 4)
            {
                cout << "Tank lost a die, 2 die left." << endl;
            }
            else if(getStrength() < 5)
            {
                cout << "Tank lost 2 die, 1 die left." << endl;
            }
        }
        else if((prerollStrength > 4) && (getStrength() < 5))
        {
            cout << "Tank lost 2 die, 1 die left." << endl;
        }
    }
    else if(damage <= 0)
    {
        //     cout << "Attack defended 0 damage!" << endl;
    }
}
/*******************************************************************
 ** Function: heal
 ** Description: Tank heal function.  If Tank are less than
 ** initial strength, recovers 1% the damage incurred.
 ** Parameters: N/a.
 ** Pre-Conditions: Strength not yet recovered.
 ** Post-Conditions:  1% of damage inflicted is recovered.
 ** Return: n/a.
 ******************************************************************/
void Tank::heal()
{
    if(getStrength() < 500)
    {
        int diff; // Diff is damage inflicted last round.
        diff = 500-getStrength();
        if(diff == 1) // To prevent 1/2 point rounding down to 0.
        {
            diff = 2;
        }
        setStrength(getStrength()+(diff/20));
        cout << "Tank healed " << (diff/20) << " points." << endl;
    }
}
Tank::~Tank()
{
    // Used for testing.
    cout << "Tank died!" << endl;
}