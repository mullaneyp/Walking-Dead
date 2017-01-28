/***************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for Item class.
 ** Date: 11/28/16
 **************************************************/

#include "Item.hpp"

Item::Item(string n, int q)
{
    name = n;
    quantity = q;
}
/********************************************
 ** Function: getName
 ** Description: Returns name for item.
 ** Parameters: N/a.
 ** Pre-Conditions: Item name not known.
 ** Post-Conditions: Item name known.
 ** Return: String value for name of item..
 *******************************************/
string Item::getName()
{
    return name;
}
/**********************************************
 ** Function: getQuantity
 ** Description: Returns quantity for item.
 ** Parameters: N/a.
 ** Pre-Conditions: Quantity unknown.
 ** Post-Conditions: Quantity known.
 ** Return: Integer value for quantity of item.
 **********************************************/
int Item::getQuantity()
{
    return quantity;
}
/*****************************************
 ** Function: setQuantity
 ** Description: sets quantity for item.
 ** Parameters: Integer value.
 ** Pre-Conditions: Quantity not updated.
 ** Post-Conditions: Quantity updated.
 ** Return: N/a
 ****************************************/
void Item::setQuantity(int q)
{
    quantity = q;
}
/**** Removed from final, not an option to view all satchel contentents ******/
void Item::print()
{
    cout << "Name: " << name << "\nQuantity: " << quantity << endl;
}
Item::~Item()
{
    // For testing.
    // cout << "item deleted" << endl;
}