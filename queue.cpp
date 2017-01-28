/****************************************************
 ** Author: Patrick Mullaney
 ** Description: Implementation file for queue class.
 ** Date: 11/28/16
 ***************************************************/

#include "queue.hpp"

using std::cout;
// Constructor initializes front and back nodes to NULL.
Queue::Queue()
{
    back = NULL;
    front = NULL;
}
/*******************************************************************
 ** Function: push
 ** Description: Push adds fighter pointer to queue.  If back is
 ** Null, new node added to back, if back is not empty, pointers
 ** adjusted and new node becomes back.
 ** Parameters: fighter pointer.
 ** Pre-Conditions: Fighter not yet added to queue.
 ** Post-Conditions:  Fighter pointer added to queue.
 ** Return: N/a.
 ******************************************************************/
void Queue::push(Fighter* f)
{
    node *temp;
    temp = new node(f);
    temp->next = NULL;
    if(back == NULL)
    {
        back = temp;
        front = temp;
        count++;
    }
    else
    {
        back->next = temp;
        back = temp;
        count++;
    }
}
/*******************************************************************
 ** Function: empty
 ** Description: Bool function to check if queue is empty.
 ** Parameters: n/a
 ** Pre-Conditions: Queue not checked to determine if empty.
 ** Post-Conditions:  Queue checked.
 ** Return: Bool value determining whether queue is empty or not.
 ******************************************************************/
bool Queue::empty()
{
    if(back == NULL)
    {
        return true;
    }
    else if(back != NULL)
    {
        return false;
    }
    else return false;
}
/*******************************************************************
 ** Function: pop
 ** Description: Pop removes fighter pointer from Queue.
 ** Parameters: n/a
 ** Pre-Conditions: Fighter pointer is in queue.
 ** Post-Conditions:  Fighter pointer removed from queue.
 ** Return: Fighter pointer removed from queue.
 ******************************************************************/
Fighter* Queue::pop()
{
    Fighter* pop;
    if((back == NULL) && (count == 0))
    {
        cout << "Empty queue, nothing to pop." << endl;
        return 0;
    }
    else
    {
        node *temp;
        pop = front->fighter;
        temp = front;
        front = front->next;
        delete temp;
        if(front == NULL)
        {
            back = NULL;
        }
        return pop;
    }
}
/*******************************************************************
 ** Function: display
 ** Description: Function to display contents of queue.
 ** Parameters: n/a
 ** Pre-Conditions: Contents not displayed.
 ** Post-Conditions:  Contents displayed.
 ** Return: N/a
 ******************************************************************/
void Queue::display()
{
    node *temp = front;
    while(temp!= NULL)
    {
        cout << temp->fighter->getType() << endl;
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
Queue::~Queue()
{
    node* cleanup, *temp;
    // Deallocate/delete objects.
    temp = front;
    while(temp!= NULL)
    {
        cleanup = temp;
        temp = temp->next;
        cleanup->fighter->free();
    }
    // Deallocate/delete nodes.
    temp = front;
    while(temp!=NULL)
    {
        cleanup = temp;
        temp = temp->next;
        delete cleanup;
    }
    delete temp;
}