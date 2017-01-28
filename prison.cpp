/******************************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for derived Prison space class.
 ** Date: 11/28/16
 ******************************************************************/

#include "prison.hpp"
/***************************************************************************
 ** Function: turn
 ** Description: Prison's special action.  The player can raid for food or 
 ** guns as much as they want, however, there is a 1/3 chance that they 
 ** will be attacked by a walker and will not be able to defend the attack.
 ** Parameters: N/a.
 ** Pre-Conditions: Player has not interacted with space.
 ** Post-Conditions: Player has interacted with space.  Player food/tank
 ** updated.
 ** Return: N/a.
 **************************************************************************/
void Prison::turn()
{
    cout << "Prison" << endl;
    char ch;
    cout << "P. Pass prison by." << endl;
    cout << "R. Raid prison for supplies." << endl;
    cin >> ch;
    ch = toupper(ch);
    cin.clear();
    cin.ignore();
    
    while((ch != 'P') && (ch != 'R'))
    {
        cout << "Please choose P or R." << endl;
        cin >> ch;
        ch = toupper(ch);
        cin.clear();
        cin.ignore();
    }
    if(ch == 'P')
    {
        cout << "Better keep moving toward the Kingdom." << endl;
    }
    else if(ch == 'R')
    {
        while((ch != 'L') && (player->getStrength()>0))
        {
            Fighter *f1, *f2;
            f1 = player;
            f2 = computer;
            int attack;
            cout << "F. Take food?\nG. Take guns?\nL. Leave" << endl;
            cout << "Guns: " << player->getGuns() << " " << "Food: " << player->getFood();
            cout << " Health: " << player->getStrength() << endl;
            cin >> ch;
            ch = toupper(ch);
            cin.clear();
            cin.ignore();

            if(ch == 'F')
            {
                player->setFood(1);
                attack = rand()%3+1;
                if(attack == 3)
                {
                    cout << "Walker attack!" << endl;
                    
                    int roll;
                    
                    // Computer walker attacks, surprise attack is not defended.
                    roll = f2->attack();
                    cout << "Lose " << roll << " strength" << endl;
                    player->setStrength((player->getStrength()-roll));
                }
            }
            else if(ch == 'G')
            {
                player->setGuns(1);
                attack = rand()%3+1;
                if(attack == 3)
                {
                    cout << "Walker attack!" << endl;
                   
                    int roll;
                    
                    // Computer walker attacks, surprise attack is not defended.
                    roll = f2->attack();
                    cout << "Lose " << roll << " strength" << endl;
                    player->setStrength((player->getStrength()-roll));
                }
            }
        }
    }
}
/****************************************************
 ** Function: getFood
 ** Description: Returns amount of food in space.
 ** Parameters: N/a.
 ** Pre-Conditions: Amount of food not known.
 ** Post-Conditions: Amount of food known.
 ** Return: Integer value for number of food.
 ***************************************************/
int Prison::getFood()
{
    return food;
}
/****************************************************
 ** Function: setFood
 ** Description: Updates the amount of food in space.
 ** Parameters: N/a.
 ** Pre-Conditions: Amount of food not altered.
 ** Post-Conditions: Amount of food updated.
 ** Return: N/a
 ***************************************************/
void Prison::setFood(int f)
{
    food = f;
    cout << "Armory food: " << food << endl;
}
/****************************************************
 ** Function: setGuns
 ** Description: Updates space's guns by adding the
 ** integer value passed.
 ** Parameters: Integer value to add/subtract.
 ** Pre-Conditions: Amount of space's guns unaltered.
 ** Post-Conditions: Amount of space's guns updated.
 ** Return: N/a
 ***************************************************/
void Prison::setGuns(int g)
{
    guns = g;
}
/****************************************************
 ** Function: getGuns
 ** Description: Returns quantity of space's guns.
 ** Parameters: N/a.
 ** Pre-Conditions: Amount of guns unknown.
 ** Post-Conditions: Amount of guns known.
 ** Return: Integer value for amount space's of guns.
 ***************************************************/
int Prison::getGuns()
{
    return guns;
}
Prison::~Prison()
{
    delete computer;
}