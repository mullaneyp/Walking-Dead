/**********************************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for derived Negansmen space class.
 ** Date: 11/28/16
 **********************************************************************/

#include "negansmen.hpp"
/***********************************************************************
 ** Function: turn
 ** Description: Negansmen's special action.  The player can fight a
 ** Savior to win guns or pay tribute (sacrifice food).  If a Savior
 ** dies, they are replaced with a Walker.
 ** Parameters: N/a.
 ** Pre-Conditions: Player has not interacted with space. If space
 ** has not been entered by a player, intitialized with a symbol
 ** on the map for geography (road, grass, etc).
 ** Post-Conditions: Player has interacted with space.  After entered 
 ** by a player, symbol will show on map that a Savior/walker is there.
 ** Return: N/a.
 ***********************************************************************/
void Negansmen::turn()
{
    if(computer->getChar() == 'S')
    {
        this->setSymbol('S');
    }
    else if(computer->getChar() == 'W')
    {
        this->setSymbol('W');
    }
    
    char ch;
    cout << "Saviors!" << endl;
    if(player->getKey())
    {
        cout << "No guns, must pay tribute, -1 food" << endl;
        player->setFood(-1);
    }
    else
    {
        cout << "T. Pay tribute (give food).\nF. Fight? (Attack for guns)." << endl;
        cin >> ch;
        ch = toupper(ch);
        cin.clear();
        cin.ignore();
    
        while((ch != 'T') && (ch != 'F'))
        {
            cout << "Please enter a choose T or F." << endl;
            cin >> ch;
            ch = toupper(ch);
            cin.clear();
            cin.ignore();
        }
        if(ch == 'T')
        {
            if(player->getFood()>0)
            {
                player->setFood(-1);
                cout << "Tribute paid: -1 food." << endl;
            }
            else if(player->getFood() <=  0)
            {
                cout << "No food to pay tribute, -1 strength." << endl;
                player->setStrength((player->getStrength())-1);
            }
        }
        else if(ch == 'F')
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
                
                if(roll1 >roll2) // If player wins, player guns +1 and space guns -1.
                {
                    cout << player->getType() << " wins " << endl;
                    player->setGuns(1);
                    this->setGuns((this->getGuns()-1));
                    computer->setGuns(-1);
                    cout << "+1 player guns." << endl;
                }
                else if(roll2 > roll1) // If computer wins, space guns +1 and player guns -1.
                {
                    cout << computer->getType() << " wins " << endl;
                    this->setGuns(this->getGuns()+1);
                    player->setGuns(-1);
                    cout << "-1 player guns." << endl;
                }
                else if(roll2 == roll1)
                {
                    cout << "draw!" << endl;
                }
            }
        }
   }
    if(computer->getStrength() <= 0)
    {
        computer->free();
        computer = new Walker();
        cout << "Savior dead, becomes walker!" << endl;
        cout << computer->getType() << endl;
    }
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
void Negansmen::setGuns(int g)
{
    guns = g;
  //  cout << "negan set guns: " << guns << endl;
}
/****************************************************
 ** Function: getGuns
 ** Description: Returns quantity of space's guns.
 ** Parameters: N/a.
 ** Pre-Conditions: Amount of guns unknown.
 ** Post-Conditions: Amount of guns known.
 ** Return: Integer value for amount space's of guns.
 ***************************************************/
int Negansmen::getGuns()
{
    return guns;
}
/*********************************************************************
 ** Function: Desconstructor.
 ** Description: Deletes computer controlled fighter.
 ** Parameters: N/a.
 ** Pre-Conditions:  Computer is alive.
 ** Post-Conditions: Computer is dead.
 ** Return: N/a.
 *********************************************************************/
Negansmen::~Negansmen()
{
    delete computer;
  //   cout << "negans deleted" << endl;
}
