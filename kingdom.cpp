/*********************************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for derived Kingdom space class.
 ** Date: 11/28/16
 ********************************************************************/

#include "kingdom.hpp"
/***************************************************************************
 ** Function: turn
 ** Description: Kingdom's special action and final action "on the map".
 ** If player has the key, they can give it to King Ezekiel and obtain the 
 ** the tank or player can choose to give all their food to King Ezekiel
 ** (which will reward player with him joining them for boss fight).
 ** Parameters: N/a.
 ** Pre-Conditions: Player has not interacted with space.
 ** Post-Conditions: Player has interacted with space.  Player food/tank
 ** updated.
 ** Return: N/a.
 **************************************************************************/
void Kingdom::turn()
{
    cout << "Welcome to the Kingdom." << endl;
    char ch;
    cout << "H. Heal(trade food for health). " << endl;
    cout << "G. Gift(give Ezekiel all your food for safe haven)." << endl;
    if(player->getKey())
    {
        cout << "K. Give key to King Ezekiel?" << endl;
    }
        cin >> ch;
        ch = toupper(ch);
        cin.clear();
        cin.ignore();
        while((ch != 'H') && (ch != 'G') && (ch!= 'K'))
        {
            cout << "Please choose H or G." << endl;
            cin >> ch;
            ch = toupper(ch);
            cin.clear();
            cin.ignore();
        }
        if(ch == 'H')
        {
            player->setFood(-1);
            this->setFood((this->getFood()+1));
            player->heal();
        }
        else if(ch == 'G')
        {
            cout << "King Ezekiel thanks you!" << endl;
            player->setFood(-(player->getFood()));
            this->setFood((this->getFood()));
            player->setGuns(10);
            this->setZeke(true);
        }
        else if((ch =='K') && (player->getKey()))
        {
            cout << "You have the key!" << endl;
            player->setTank(true);
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
int Kingdom::getFood()
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
void Kingdom::setFood(int f)
{
    food = f;
    cout << "Kingdom food: " << food << endl;
}
Kingdom::~Kingdom()
{
  //  cout << "Kingdom deleted" << endl;
}