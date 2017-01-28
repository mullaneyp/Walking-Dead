/******************************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for derived Horde space class.
 ** Date: 11/28/16
 *****************************************************************/

#include "horde.hpp"

/**********************************************************************
 ** Function: turn
 ** Description: Horde's special action.  The player can fight a 
 ** walker to win food, choose skip the fight and lose food, or if
 ** the player is Michonne, she can sneak by wwalkers unnoticed.
 ** Parameters: N/a.
 ** Pre-Conditions: Player has not interacted with space. If space
 ** has not been entered by a player, intitialized with a symbol
 ** on the map for geography (road, grass, etc).
 ** Post-Conditions: Player has interacted with space.  After 
 ** entered by a player, symbol will show on map that a walker is there.
 ** Return: N/a.
 ***********************************************************************/
void Horde::turn()
{
    this->setSymbol('W');
    cout << "Horde of walkers!" << endl;
    char ch;
    if(player->getChar() == 'M')
    {
        cout << "A. Attack (fight for food)." << endl;
        cout << "I. Michonne is invisible to walkers and can sneak by." << endl;
        cin >> ch;
        ch = toupper(ch);
        cin.clear();
        cin.ignore();
        while((ch != 'A') && (ch != 'I'))
        {
            cout << "Please enter a choose A or I." << endl;
            cin >> ch;
            ch = toupper(ch);
            cin.clear();
            cin.ignore();
        }
    }
    else
    {
        cout << "A. Attack (fight for food).\nH. Hide(drop food and run)." << endl;
        cin >> ch;
        ch = toupper(ch);
        cin.clear();
        cin.ignore();
        while((ch != 'A') && (ch != 'H'))
        {
            cout << "Please enter a choose A or H." << endl;
            cin >> ch;
            ch = toupper(ch);
            cin.clear();
            cin.ignore();
        }
    }
    // If player chooses attack, fights walker.  Fights is only one round.
    if(ch == 'A')
    {
        Fighter *f1, *f2;
        f1 = player;
        f2 = computer;
        
        int roll1, roll2;
        
        cout << f1->getType() << " strength: " << f1->getStrength() << endl;
        cout << f2->getType() << " strength: " << f2->getStrength() << endl;
        
        roll1 = f1->attack();
        //    cout << "P1 " << f1->getName() << " attack: " << roll1 << endl;
        // Player 2 defends.
        f2->defend(roll1);
        
        // If player 2 dies, notify user.  If alive, attack player 1.
        if(f2->getStrength() <= 0)
        {
            cout << f2->getType() << " died! " << endl;
            // Player food +1.
            f1->setFood(1);
            cout << f1->getType() << " wins. " << endl;
        }
        else if(f2->getStrength() > 0)
        {
            roll2 =  f2->attack();
            //   cout << "P2 " << f2->getName() << " attack: " << roll2 << endl;
            f1->defend(roll2);
            if(f1->getStrength() <= 0)
            {
                cout  << f1->getType() << " died! " << endl;
            }
            else if(roll1 >roll2) // If player 1 wins, player food +1, horde food -1.
            {
                cout << player->getType() << " wins. " << endl;
                f1->setFood(1);
                this->setFood((this->getFood()-1));
                cout << "+1 player food." << endl;
            }
            else if(roll2 > roll1) // If player 2 wins, player food -1, horde food +1.
            {
                cout << computer->getType() << " wins. " << endl;
                this->setFood(this->getFood()+1);
                f1->setFood(-1);
                cout << "-1 player food." << endl;
            }
            else if(roll2 == roll1)
            {
                cout << "draw!" << endl;
            }
        }
    }
    else if(ch == 'H') // If player chooses hide, player food -1.
    {
        player->setFood(-1);
        cout << "Player dropped food, -1 food." << endl;
    }
    else if(ch == 'I') // If Michonne chooses, can pass by freely.
    {
        cout << "Horde of walkers passed by Michonne." << endl;
    }
}
/****************************************************
 ** Function: setFood
 ** Description: Updates the amount of food in space.
 ** Parameters: N/a.
 ** Pre-Conditions: Amount of food not altered.
 ** Post-Conditions: Amount of food updated.
 ** Return: N/a
 ***************************************************/
void Horde::setFood(int f)
{
    food = f;
}
/****************************************************
 ** Function: getFood
 ** Description: Returns amount of food in space.
 ** Parameters: N/a.
 ** Pre-Conditions: Amount of food not known.
 ** Post-Conditions: Amount of food known.
 ** Return: Integer value for number of food.
 ***************************************************/
int Horde::getFood()
{
    return food;
}
/*****************************************************
 ** Function: Desconstructor.
 ** Description: Deletes computer controlled fighter.
 ** Parameters: N/a.
 ** Pre-Conditions:  Computer is alive.
 ** Post-Conditions: Computer is dead.
 ** Return: N/a.
 ******************************************************/
Horde::~Horde()
{
    delete computer;
  //  cout << "Horde deleted " << endl;
}