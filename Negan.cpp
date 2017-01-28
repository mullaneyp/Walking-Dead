/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Implentation file for derived fighter 
 ** class for boss Negan.
 ** Date: 11/28/16
 *****************************************************/
#include "Negan.hpp"
/*******************************************************************
 ** Function: attack
 ** Description: Negan attack function, rolls 2x10 sided die.
 ** Parameters: N/a.
 ** Pre-Conditions: Attack not rolled.
 ** Post-Conditions:  Attack rolled.
 ** Return: Integer value for roll1 + roll2 for Negan attack.
 ******************************************************************/
int Negan::attack()
{
    // Roll 2x10 sided die.
    int roll1 = rand()%10+1;
    int roll2 = rand()%10+1;
    
    return roll1 + roll2;
}
/*******************************************************************
 ** Function: defend
 ** Description: Negan defend function.  Takes an attack, rolls
 ** 4x5 sided die in defense, calculates damage and updates strength.
 ** For every 4 points of strength that blue men lose, they lose a
 ** defense die.  Also notified user each time a die is lost.
 ** Parameters: Integer attack value.
 ** Pre-Conditions: Attack not defended and damage not applied.
 ** Post-Conditions:  If attack value exceeds defense value,
 ** damage is applied and strength is updated.
 ** Return: n/a.
 ******************************************************************/
void Negan::defend(int a)
{
    int attack = a;
    int defense, roll1, roll2, roll3, roll4, damage;
    int prerollStrength;
    // Track strength before roll to determine and output if a die is lost.
    prerollStrength = getStrength();
    
    // Roll 4x5 die.
    roll1 = rand()%5+1;
    roll2 = rand()%5+1;
    roll3 = rand()%5+1;
    roll4 = rand()%5+1;
    
    if(getStrength() > 125)
    {
        defense = (roll1 + roll2 + roll3 +roll4);
    }
    else if((getStrength() > 100) && (getStrength() < 126))
    {
        defense = (roll1 + roll2 + roll3);
    }
    else if((getStrength() < 49) && (getStrength() < 101))
        defense = (roll1 + roll2);
    else if(getStrength() < 50)
        defense = roll1;
    //  cout << "Negan defense roll: " << defense  << endl;
    
    damage = (attack - defense) - getArmor();
    
    if(damage > 0)
    {
        //      cout << "Negan damage: " << damage << endl;
        setStrength(getStrength()-damage);
        if((prerollStrength > 100) && (getStrength() < 126))
        {
            if(getStrength() > 100)
            {
                cout << "Negan lost a die, 3 die left." << endl;
            }
            else if(getStrength() < 101)
            {
                cout << "Negan lost 2 die, 2 die left." << endl;
            }
            else if(getStrength() < 50)
            {
                cout << "Negan lost 3 die, 1 die left" << endl;
            }
        }
        else if((prerollStrength > 49) && (getStrength() < 101))
        {
            if(getStrength() < 50)
            {
                cout << "Negan lost 3 die, 1 die left." << endl;
            }
        }
    }
    else if(damage <= 0)
    {
        //     cout << "Attack defended 0 damage!" << endl;
    }
}
/*******************************************************************
 ** Function: heal
 ** Description: Negan heal function.  If Negan is less than
 ** initial strength, recovers half the damage incurred.
 ** Parameters: N/a.
 ** Pre-Conditions: Strength not yet recovered.
 ** Post-Conditions:  10% of damage inflicted is recovered.
 ** Return: n/a.
 ******************************************************************/
void Negan::heal()
{
    if(getStrength() < 150)
    {
        int diff; // Diff is damage inflicted last round.
        diff = 150-getStrength();
        if(diff == 1) // To prevent 1/2 point rounding down to 0.
        {
            diff = 2;
        }
        setStrength(getStrength()+(diff/10));
       // cout << "Negan healed " << (diff/10) << " points." << endl;
    }
}
Negan::~Negan()
{
    // Used for testing.
    // cout << "Negan died!" << endl;
}