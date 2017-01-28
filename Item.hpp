/*********************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for Item class.
 ** Date: 11/28/16
 ********************************************/

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Item{
    
private:
    string name;
    int quantity;
    
public:
    //Constructor
    Item(string, int);
    
    // Get methods for name and quantity.
    string getName();
    int getQuantity();
    // Set method for quantity.
    void setQuantity(int);
    
    // Print Item.
    void print();
    
    ~Item();
    
};

#endif /* Item_hpp */
