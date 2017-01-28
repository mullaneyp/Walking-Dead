/*******************************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for derived Armory space class.
 ** Date: 11/28/16
 *******************************************************************/

#include "armory.hpp"
/***************************************************************************
 ** Function: turn
 ** Description: Armory's special action.  The player can trade food
 ** for health or can trade all guns to obtain the tank key.  If the player
 ** chooses to trade for the tank key, they can no longer carry guns.
 ** Parameters: N/a.
 ** Pre-Conditions: Player has not interacted with space.
 ** Post-Conditions: Player has interacted with space.  Player food/tank 
 ** updated.
 ** Return: N/a.
 **************************************************************************/
void Armory::turn()
{
    cout << "Armory" << endl;
    char ch;
    cout << "H. Heal(trade food for health).\nK. Trade all your guns for a key." << endl;
    cout << "R. Restock(trade food for guns)." << endl;
    cin >> ch;
    ch = toupper(ch);
    cin.clear();
    cin.ignore();
    
    while((ch != 'H') && (ch != 'R') && (ch!= 'K'))
    {
        cout << "Please choose H, K, or R." << endl;
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
    else if(ch == 'R')
    {
        player->setFood(-1);
        this->setFood((this->getFood()+1));
        this->setGuns((this->getGuns()-1));
        player->setGuns(1);
    }
    else if(ch == 'K')
    {
        cout << player->getType() << " received key." << endl;
        player->setGuns(-(player->getGuns())); 
        player->addItem(new Item("Key",1));
        player->setKey(true);
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
int Armory::getFood()
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
void Armory::setFood(int f)
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
void Armory::setGuns(int g)
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
int Armory::getGuns()
{
    return guns;
}
Armory::~Armory()
{
 //   cout << "Armory deleted" << endl;
}