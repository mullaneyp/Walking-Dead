/*****************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementaiton file for simple menu
 ** functions.
 ** Date: 11/28/16
 *****************************************************/

#include "menu.hpp"

using std::cin;
using std::cout;
using std::endl;

/*******************************************************************
 ** Function: select
 ** Description: Simple menu function to select player controlled
 ** fighter.
 ** Parameters: n/a
 ** Pre-Conditions: Player not selected.
 ** Post-Conditions:  Player selected.
 ** Return: Pointer value indicating selected fighter.
 ******************************************************************/
Fighter* selection()
 {
     int selection;
     Fighter* player;
     
     cout << "Please select a character " << endl;
     cout << "1. Rick (revives 1 time)." << endl;
     cout << "2. Michonne (higher attack,  lower defense)." << endl;
     cout << "3. Daryl (higher health, heals more). " << endl;
     cin >> selection;
     cin.clear();
     cin.ignore();
     while((selection < 1) || (selection > 3))
     {
         cout << "Please enter a choice between 1 and 3." << endl;
         cin >> selection;
         cin.clear();
         cin.ignore();
     }
 
     if(selection == 1)
     {
         // Allocate memory for new fighter
         player = new Rick();
         return player;
     }
     else if(selection == 2)
     {
         // Allocate memory for new fighter
         player = new Michonne();
         return player;
     }
     else if(selection == 3)
     {
         player = new Daryl();
     }
     return player;
}
Fighter* selectTeam(Fighter *f)
{
    int selection;
    Fighter* player;
    player = f;
    Fighter* partner;
    
    cout << "Please select a character " << endl;
    if(player->getChar() == 'R')
    {
        cout << "2. Michonne (higher attack, lower defense)." << endl;
        cout << "3. Daryl (higher health, heals more). " << endl;
        cin >> selection;
        cin.clear();
        cin.ignore();
        while((selection != 2) && (selection != 3))
        {
            cout << "Please enter a choice between 2 or 3." << endl;
            cin >> selection;
            cin.clear();
            cin.ignore();
        }
    }
    else if(player->getChar() == 'M')
    {
        cout << "1. Rick (revives 1 time)." << endl;
        cout << "3. Daryl (higher health, heals more). " << endl;
        cin >> selection;
        cin.clear();
        cin.ignore();
        while((selection != 1) && (selection != 3))
        {
            cout << "Please enter a choice between 1 or 3." << endl;
            cin >> selection;
            cin.clear();
            cin.ignore();
        }
    }
    else if(player->getChar() == 'D')
    {
        cout << "1. Rick (revives 1 time)." << endl;
        cout << "2. Michonne (higher attack, lower defense)." << endl;
        cin >> selection;
        cin.clear();
        cin.ignore();
        while((selection != 1) && (selection != 3))
        {
            cout << "Please enter a choice between 1 and 2." << endl;
            cin >> selection;
            cin.clear();
            cin.ignore();
        }
    }
    
    if(selection == 1)
    {
        // Allocate memory for new fighter
        partner = new Rick();
        return partner;
    }
    else if(selection == 2)
    {
        // Allocate memory for new fighter
        partner = new Michonne();
        return partner;
    }
    else if(selection == 3)
    {
        partner = new Daryl();
        return partner;
    }
    return partner;
}
/*******************************************************************
 ** Function: move
 ** Description: Simple menu function to select direction for player
 ** to move.
 ** Parameters: n/a
 ** Pre-Conditions: Next space not selected by user.
 ** Post-Conditions:  Next space selected by user.
 ** Return: Integer value indicating next space for player to enter.
 *******************************************************************/
int move()
{
    int choice;
    cout << "1. Move up.\n2. Move down.\n3. Move left.\n4. Move right." << endl;
    cin >> choice;
    cin.clear();
    cin.ignore();
    while((choice < 1) || (choice > 4))
    {
        cout << "Please enter a choice between 1 and 4." << endl;
        cin >> choice;
        cin.clear();
        cin.ignore();
    }
    return choice;
}