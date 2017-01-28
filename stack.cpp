/****************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for stack class.
 ** Date: 11/28/16
 ***************************************************/

#include "stack.hpp"
using std::cout;

Stack::Stack()
{
    top = NULL;
}
/*******************************************************************
 ** Function: push
 ** Description: Push adds Fighter pointer to stack.  If back is
 ** Null, new node added to back, if back is not empty, pointers
 ** adjusted and new node becomes back.
 ** Parameters: Fighter pointer.
 ** Pre-Conditions: Fighter not yet added to stack.
 ** Post-Conditions:  Fighter pointer added to stack.
 ** Return: N/a.
 ******************************************************************/
void Stack::push(Fighter* f)
{

    // Top is null, f becomes first fighter.
    if(top == NULL)
    {
        top = new node(f);
        count++;
    }
    else
    {   // Else fighter becomes new top.
        node *temp;
        temp = new node(f);
        temp->next = top;
        top = temp;
        count++;
    }
}
/*******************************************************************
 ** Function: empty
 ** Description: Bool function to check if stack is empty.
 ** Parameters: n/a
 ** Pre-Conditions: Stack not checked to determine if empty.
 ** Post-Conditions:  Stack checked.
 ** Return: Bool value determining whether stack is empty or not.
 ******************************************************************/
bool Stack::empty()
{
    if(top == NULL)
    {
        return true;
    }
    else
        return false;
}
/*********************************************************
 ** Function: pop
 ** Description: Pop removes Fighter pointer from stack.
 ** Parameters: n/a
 ** Pre-Conditions: Fighter pointer is in queue.
 ** Post-Conditions:  Fighter pointer removed from stack.
 ** Return: Fighter pointer removed from queue.
 *********************************************************/
Fighter* Stack::pop()
{
    Fighter* pop;
    if((top == NULL) && (count == 0))
    {
        cout << "Empty stack, nothing to pop." << endl;
        return 0;
    }
    else if(top!= NULL)
    {
        node *temp;
        pop = top->fighter;
        temp = top;
        top = top->next;
        count--;
        //  delete temp;
        return pop;
    }
    else
        return pop;
}
/*******************************************************************
 ** Function: display
 ** Description: Function to display contents of stack.
 ** Parameters: n/a
 ** Pre-Conditions: Contents not displayed.
 ** Post-Conditions:  Contents displayed.
 ** Return: N/a
 ******************************************************************/
void Stack::display()
{
    node *temp = top;
    while(temp!= NULL)
    {
        cout << temp->fighter->getType() << " " << endl;;
        temp = temp->next;
    }
}
/*********************************************************************
 ** Function: deconstructor
 ** Description: Deconstructor first deallocates the fighter objects
 ** pointed to by the nodes, then deletes the nodes themselves.
 ** Parameters: n/a
 ** Pre-Conditions: Contents not deallocated/deleted.
 ** Post-Conditions:  Contents deallocated/deleted.
 ** Return: N/a
 **********************************************************************/
Stack::~Stack()
{
    node* temp, *cleanup;
    temp = top;
    // First delete Fighter objects.
    while(temp!= NULL)
    {
        cleanup = temp;
        temp = temp->next;
        cleanup->fighter->free();;
    }
    // Second delete nodes.
    temp = top;
    while(temp!= NULL)
    {
        cleanup = temp;
        temp = temp->next;
        delete cleanup;
    }
}