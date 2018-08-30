#include "LinkedList.hpp"

void LinkedList::deleteNode(Node *toDelete)
{
    Node*temp=LinkedList::head;
    if (toDelete==temp)
    {
    LinkedList::head=temp->next;
    delete temp;
    
    }
    else
    while(temp!=NULL)
    {
        if (temp->next->value==toDelete->value)
        {
            temp->next=temp->next->next;
            delete toDelete;
            break;
        }
        temp=temp->next;
    }
}
