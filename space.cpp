/************************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for parent space class.
 ** Space class is an abstract class for various
 ** spaces that will occupy the map for the game.
 ** Date: 11/28/16
 ************************************************************/

#include "space.hpp"
Space::Space(char s, string n, Space ***g, int r, int c)
{
    symbol = s;
    name = n;
    grid = g;
    row = r;
    col = c;
    zeke = false;
    player = NULL;
   // computer = NULL;
}
/******************************************************************
 ** Functions: setTop, setBottom, setLeft, and setRight
 ** Description: Set functions that initialize the four repsective
 ** space pointers in each space.
 ** Parameters: A space pointer to the next respective space is 
 ** passed and sets the pointer to that space.
 ** Pre-Conditions: Each space pointer set to null.
 ** Post-Conditions: Spaces are linked by pointers.
 ** Return: N/a
 *******************************************************************/
void Space::setTop(Space* s)
{
    top = s;
}
void Space::setBottom(Space* s)
{
    bottom = s;
}
void Space::setLeft(Space* s)
{
    left = s;
}
void Space::setRight(Space* s)
{
    right = s;
}
/******************************************************************
 ** Functions: getTop, getBottom, getLeft, and getRight
 ** Description: get functions return a space pointer to each
 ** linked space in their respective direction.
 ** Parameters: N/a.
 ** Pre-Conditions: Linked space unknown.
 ** Post-Conditions: Linked space known.
 ** Return: Space pointer to the respective direction.
 *******************************************************************/
Space* Space::getTop()
{
    return top;
}
Space* Space::getBottom()
{
    return bottom;
}
Space* Space::getLeft()
{
    return left;
}
Space* Space::getRight()
{
    return right;
}
/*****************************************
 ** Function: getChar
 ** Description: Gets symbol of a space.
 ** Parameters: N/a.
 ** Pre-Conditions: Symbol unknown.
 ** Post-Conditions: Symbol known.
 ** Return: Char value for symbol.
 *****************************************/
char Space::getChar()
{
    return symbol;
}
/***********************************************
 ** Function: getName
 ** Description: gets type or name of a space.
 ** Parameters: N/a.
 ** Pre-Conditions: Name unknown.
 ** Post-Conditions: Name known.
 ** Return: String value for name.
 ***********************************************/
string Space::getName()
{
    return name;
}
/***********************************************
 ** Function: getPlayer
 ** Description: gets player-controlled fighter.
 ** Parameters: N/a.
 ** Pre-Conditions: Player unknown.
 ** Post-Conditions: Player known.
 ** Return: Fighter* value for player.
 ***********************************************/
Fighter* Space::getPlayer()
{
    return player;
}
/***********************************************
 ** Function: getComputer
 ** Description: gets computer-controlled fighter.
 ** Parameters: N/a.
 ** Pre-Conditions: Computer player unknown.
 ** Post-Conditions: Computer player known.
 ** Return: Fighter* value for computer.
 ***********************************************/
Fighter* Space::getComputer()
{
    return computer;
}
/********************************************************
 ** Function: setPlayer
 ** Description: sets player-controlled fighter value.
 ** Parameters: N/a.
 ** Pre-Conditions: Player value null or unaltered.
 ** Post-Conditions: Player value updated.
 ** Return: N/a
 *******************************************************/
void Space::setPlayer(Fighter* f)
{
    // If null value passed when player is leaving this space, set player to null.
    if(f == NULL)
    {
        this->player = NULL;
    }
    else if(player == NULL)
    {
      //  cout << "this player: " << this->row << " " << this->col << endl;
        this->player = f;
    }
}
/************************************************************
 ** Function: setZeke
 ** Description: Sets bool value for Zeke.  When Zeke is 
 ** activiated to true, he can join the player in boss fight.
 ** Parameters: Bool.
 ** Pre-Conditions: Zeke value is initialized to false.
 ** Post-Conditions: Zeke is set to true.
 ** Return: N/a
 ************************************************************/
void Space::setZeke(bool b)
{
    zeke = b;
}
/*********************************************
 ** Function: getZeke
 ** Description: Returns bool value for Zeke.
 ** Parameters: N/a
 ** Pre-Conditions: Zeke value is known.
 ** Post-Conditions: Zeke value is unknown.
 ** Return: Bool value for Zeke.
 *********************************************/
bool Space::getZeke()
{
    return zeke;
}
/*****************************************
 ** Function: setSymbol
 ** Description: Sets symbol of a space.
 ** Parameters: N/a.
 ** Pre-Conditions: Symbol unaltered.
 ** Post-Conditions: Symbol updated.
 ** Return: N/a
 *****************************************/
void Space::setSymbol(char s)
{
    symbol = s;
}
/***************************************************
 ** Function: free
 ** Description: Deallocates memory for new space
 ** objects.
 ** Parameters: N/a.
 ** Pre-Conditions: Memory allocated to space.
 ** Post-Conditions: N/a.
 ** Return: N/a.
 **************************************************/
void Space::free()
{
    delete this;
}
/*********************************************************************
 ** Function: Desconstructor.
 ** Description: Deletes critter.
 ** Parameters: N/a.
 ** Pre-Conditions:  Critter is alive.
 ** Post-Conditions: Critter is dead.
 ** Return: N/a.
 *********************************************************************/
Space::~Space()
{
    // for testing.
  /*  if(computer != NULL)
    {
        cout << "computer free" << endl;
        this->computer->free();
        cout << "computer freed" << endl;
    }*/
  //  cout << "space deleted" << endl;
    if(player != NULL)
    {
        cout << "player exists in space" << endl;
      //  player->free();
    }
}