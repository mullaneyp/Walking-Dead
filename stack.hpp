/*********************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for stack class.
 ** Date: 11/28/16
 *********************************************/

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include <iostream>
#include "fighter.hpp"

using namespace std;

struct node{
    node *next;
    Fighter* fighter;
    
    node(Fighter* f, node* n= NULL){
        fighter = f;
        next = n;
    }
};

class Stack{
private:
    int count;
    node *top;
    
public:
    //Constructor.
    Stack();
    // Adds element to stack.
    void push(Fighter* f);
    // Remove element from stack.
    Fighter* pop();
    // Determine if stack is empty
    bool empty();
    // Display list
    void display();
    // Deconstructor.
    ~Stack();
};
#endif /* stack_hpp */
