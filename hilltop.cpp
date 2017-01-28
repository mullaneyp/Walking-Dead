/********************************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for derived Hilltop space class.
 ** Date: 11/28/16
 ********************************************************************/

#include "hilltop.hpp"
/***************************************************************************
 ** Function: turn
 ** Description: Hilltop's special action.  The player can trade food
 ** for health or can trade guns to restock food.
 ** Parameters: N/a.
 ** Pre-Conditions: Player has not interacted with space.
 ** Post-Conditions: Player has interacted with space.  Player food updated.
 ** Return: N/a.
 **************************************************************************/
void Hilltop::turn()
{
    cout << "Hilltop" << endl;
    char ch;
    if(player->getKey())
    {
        while(ch!= 'L')
        {
            cout << "No guns, cannot trade guns for food." << endl;
            cout << "H. Heal(trade food for health).\nL. Leavestock." << endl;
            cout << "Food: " << player->getFood() << " " << " Health: " << player->getStrength() << endl;
            cin >> ch;
            ch = toupper(ch);
            cin.clear();
            cin.ignore();
        
            while((ch != 'H') && (ch!= 'L'))
            {
                cout << "Please choose H or L." << endl;
                cin >> ch;
                ch = toupper(ch);
                cin.clear();
                cin.ignore();
            }
            if(ch == 'H')
            {
                if(player->getFood() > 0)
                {
                    player->setFood(-1);
                    this->setFood((this->getFood()+1));
                    player->heal();
                }
                else if(player->getFood() <= 0)
                    cout << "Can't heal, not enough food." << endl;
            }
        }
    }
    else
    {
        while(ch!= 'L')
        {
                cout << "H. Heal(trade food for health).\nR. Restock(trade guns for food)." << endl;
                cout << "L. Leave." << endl;
                cout << "Guns: " << player->getGuns() << " " << "Food: " << player->getFood();
                cout << " Health: " << player->getStrength() << endl;
                cin >> ch;
                ch = toupper(ch);
                cin.clear();
                cin.ignore();
    
            while((ch != 'H') && (ch != 'R') && (ch!= 'L'))
            {
                cout << "Please choose H, R, or L." << endl;
                cin >> ch;
                ch = toupper(ch);
                cin.clear();
                cin.ignore();
            }
            if(ch == 'H')
            {
                if(player->getFood() > 0)
                {
                    player->setFood(-1);
                    this->setFood((this->getFood()+1));
                    player->heal();
                }
                else if(player->getFood() <= 0)
                    cout << "Can't heal, not enough food." << endl;
            }
            else if(ch == 'R')
            {
                if(player->getGuns() > 0)
                {
                    cout << "Restocked." << endl;
                    player->setFood(1);
                    this->setFood((this->getFood()-1));
                    player->setGuns(-1);
                }
                else if(player->getGuns() <= 0)
                {
                    cout << "Unable to trade for food, not enough guns." << endl;
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
int Hilltop::getFood()
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
void Hilltop::setFood(int f)
{
    food = f;
    cout << "Hilltop food: " << food << endl;
}
Hilltop::~Hilltop()
{
  //  cout << "Hilltop deleted" << endl;
}