/****************************************************
 ** Author: Patrick Mullaney
 ** Description: Header file for queue class used to
 ** hold team of fighter pointers for final battle.
 ** Date: 11/28/16
 ***************************************************/
#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
#include <iostream>
#include "fighter.hpp"

using namespace std;

class Queue{
private:
    struct node{
        Fighter* fighter;
        node *next;
        
        node(Fighter* f, node* n = NULL)
        {
            fighter = f;
            next = n;
        }
    };
    
    int count;
    node *front;
    node *back;
    
public:
    // Constructor
    Queue();
    // Adds element to stack.
    void push(Fighter* f);
    // Remove element from stack.
    Fighter* pop();
    // Determine if stack is empty
    bool empty();
    // Display list
    void display();
    // Deconstructor
    ~Queue();
};
#endif /* queue_hpp */
