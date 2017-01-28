/**************************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for parent fighter class.
 ** Date: 11/28/16
 *************************************************************/

#include "fighter.hpp"

Fighter::Fighter(string t, int s, int a, char c, int g)
{
    type = t;
    strength = s;
    armor = a;
    symbol = c;
    guns = g;
    food = 5;
    key = false;
    tank = false;
    srand((unsigned)time(NULL));
    satchel = new Item*[2];
    satchel[0] = new Item("guns", g);
    satchel[1] = new Item("food", food);
}
/************************************************
 ** Function: getStrength
 ** Description: Returns strength of a fighter.
 ** Parameters: N/a.
 ** Pre-Conditions: Strength unknown.
 ** Post-Conditions: Strength known.
 ** Return: Integer value for fighter strength.
 ***********************************************/
int Fighter::getStrength()
{
    return strength;
}
/*********************************************
 ** Function: setStrength
 ** Description: Sets strength of a fighter.
 ** Parameters: Integer value for strength.
 ** Pre-Conditions: Strength unaltered.
 ** Post-Conditions: Strength set/updated.
 ** Return: N/a
 *********************************************/
void Fighter::setStrength(int s)
{
    strength = s;
}
/*******************************************
 ** Function: getArmor
 ** Description: gets armor of a fighter.
 ** Parameters: Integer value for armor.
 ** Pre-Conditions: Armor unknown.
 ** Post-Conditions: Armor known.
 ** Return: Integer value for armor.
 ******************************************/
int Fighter::getArmor()
{
    return armor;
}
/***********************************************
 ** Function: getType
 ** Description: gets type or name of a fighter.
 ** Parameters: N/a.
 ** Pre-Conditions: Type unknown.
 ** Post-Conditions: Type known.
 ** Return: String value for type.
 ***********************************************/
string Fighter::getType()
{
    return type;
}
/*****************************************
 ** Function: getChar
 ** Description: Gets symbol of a fighter.
 ** Parameters: N/a.
 ** Pre-Conditions: Symbol unknown.
 ** Post-Conditions: Symbol known.
 ** Return: Char value for symbol.
 *****************************************/
char Fighter::getChar()
{
    return symbol;
}
/******************************************************
 ** Function: setGuns
 ** Description: If player is carrying guns, sets
 ** quantity, else if carrying tank key, outputs error.
 ** Parameters: N/a.
 ** Pre-Conditions: Amount of guns not altered.
 ** Post-Conditions: Amount of guns updated.
 ** Return: N/a
 *****************************************************/
void Fighter::setGuns(int g)
{
    if(satchel[0]->getName() == "guns")
    {
        satchel[0]->setQuantity(satchel[0]->getQuantity() + g);
     //  cout << "set g guns added " << g << endl;
    }
    else
        cout << "Cannot carry guns any more" << endl;
}
/****************************************************
 ** Function: getGuns
 ** Description: If player is carrying guns, returns
 ** quantity, else if carrying tank key, returns 0.
 ** Parameters: N/a.
 ** Pre-Conditions: Amount of guns unknown.
 ** Post-Conditions: Amount of guns known.
 ** Return: Integer value for amount of guns.
 ***************************************************/
int Fighter::getGuns()
{
    if(satchel[0]->getName() == "guns")
    {
        return satchel[0]->getQuantity();
    }
    else
    return 0;
}
/******************************************************
 ** Function: setFood
 ** Description: Updates the amount of food in satchel.
 ** Parameters: N/a.
 ** Pre-Conditions: Amount of food not altered.
 ** Post-Conditions: Amount of food updated.
 ** Return: N/a
 *****************************************************/
void Fighter::setFood(int f)
{
    food = f;
    //cout << "fighter set food " << food << endl;
    satchel[1]->setQuantity(satchel[1]->getQuantity() + f);
 //   cout << "set food: " << f << endl;
}
/****************************************************
 ** Function: getFood
 ** Description: Returns amount of food in satchel.
 ** Parameters: N/a.
 ** Pre-Conditions: Amount of food unknown.
 ** Post-Conditions: Amount of food known.
 ** Return: Integer value for amount of food.
 ***************************************************/
int Fighter::getFood()
{
    return satchel[1]->getQuantity();
}
/******************************************************
 ** Function: setLoc
 ** Description: Updates player location.
 ** Parameters: Space*.
 ** Pre-Conditions: Player location unaltered.
 ** Post-Conditions: Player location updated.
 ** Return: N/a
 *****************************************************/
void Fighter::setLoc(Space* s)
{
    location = s;
}
/****************************************************
 ** Function: getLoc
 ** Description: Returns space* to player location.
 ** Parameters: N/a.
 ** Pre-Conditions: Player location unknown.
 ** Post-Conditions: Player location known.
 ** Return: Space* to player location.
 ***************************************************/
Space* Fighter::getLoc()
{
    return location;
}
/****************************************************
 ** Function: getSatchel
 ** Description: Returns Item** to player's satchel.
 ** Parameters: N/a.
 ** Pre-Conditions: Player satchel not accessed.
 ** Post-Conditions: Access to player's satchel.
 ** Return: Item** representing player's satchel.
 ***************************************************/
Item** Fighter::getSatchel()
{
    return satchel;
}
/****************************************************
 ** Function: getKey
 ** Description: Returns bool key which determines
 ** whether player has obtained tank key.
 ** Parameters: N/a.
 ** Pre-Conditions: Bool key unknown.
 ** Post-Conditions: Bool key known.
 ** Return: Bool representing whether key obtained.
 ***************************************************/
bool Fighter::getKey()
{
    return key;
}
/****************************************************
 ** Function: setKey
 ** Description: Sets bool key which determines
 ** whether player has obtained tank key.
 ** Parameters: Bool value.
 ** Pre-Conditions: Bool key set to false.
 ** Post-Conditions: Bool key set to true.
 ** Return: Bool n/a
 ***************************************************/
void Fighter::setKey(bool b)
{
    key = b;
}
/****************************************************
 ** Function: getTank
 ** Description: Returns bool tank which determines
 ** whether player has traded key for tank.
 ** Parameters: N/a.
 ** Pre-Conditions: Bool tank unknown.
 ** Post-Conditions: Bool tank known.
 ** Return: Bool representing whether tank obtained.
 ***************************************************/
bool Fighter::getTank()
{
    return tank;
}
/****************************************************
 ** Function: setTank
 ** Description: Sets bool tank which determines
 ** whether player has obtained the tank.
 ** Parameters: Bool value.
 ** Pre-Conditions: Bool tank set to false.
 ** Post-Conditions: Bool tank set to true.
 ** Return: Bool n/a
 ***************************************************/
void Fighter::setTank(bool b)
{
    tank = b;
}
/****************************************************
 ** Function: addItem
 ** Description: Updates item quantity in satchel or
 ** replaces gun item with key item if key is selected.
 ** Parameters: Item object.
 ** Pre-Conditions: Satchel contents not updated.
 ** Post-Conditions: Satchel contents updated.
 ** Return: N/a.
 ***************************************************/
void Fighter::addItem(Item* newItem)
{
    //try 2
    if(newItem->getName() == "key")
    {
        Item* temp;
        temp = satchel[0];
        satchel[0] = newItem;
        delete temp;
        cout << "you got the key!" << endl;
    }
    else if(newItem->getName() == "gun")
    {
        int newQuantity;
        newQuantity = newItem->getQuantity();
        newQuantity = satchel[0]->getQuantity()+ newQuantity;
        satchel[0]->setQuantity(newQuantity);
        delete newItem;
    }
    else if(newItem->getName() == "food")
    {
        int newQuantity;
        newQuantity = newItem->getQuantity();
        newQuantity = satchel[1]->getQuantity()+ newQuantity;
        satchel[1]->setQuantity(newQuantity);
    }
}
/***************************************************
 ** Function: free
 ** Description: Deallocates memory for new fighter
 ** objects.
 ** Parameters: N/a.
 ** Pre-Conditions: Memory allocated to fighter.
 ** Post-Conditions: N/a.
 ** Return: N/a.
 **************************************************/
void Fighter::free()
{
    delete this;
}
Fighter::~Fighter()
{
    // First delete items in satchel, then delete satchel.
   for(int i = 0; i < 2; i++)
    {
        if(satchel[i])
        {
            delete satchel[i];
            //cout << "delete item" << endl; ***used for testing
        }
    }
    delete [] satchel;
  //  cout << "delete fighter" << endl; ***used for testing
}