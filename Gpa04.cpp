//-----Include required headers here-----
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//-----End of headers-----


//-----Add new functions here(if any)-----

//-----New functions end here-----

//-----A Doubly Linked List Node-----
// DO NOT MODIFY IT
struct DLLNode {
    struct DLLNode *prev;
    int data;
    struct DLLNode *next;
};
 
/* Representation of the stack data structure that supports findMiddle(),
   deleteMiddle() in O(1) time.  The Stack is implemented using Doubly 
   Linked List. It maintains pointer to head node, pointer to middle 
   node and count of nodes */
// DO NOT MODIFY IT
struct myStack {
    struct DLLNode *head;
    struct DLLNode *mid;
    int count;
};
 
//-----Function to create the stack data structure-----
// DO NOT uncomment the below function. It is for your reference purpose only.
// We will use this function to create the stack.
/*struct myStack *createMyStack() {
    struct myStack *ms = (struct myStack*) malloc(sizeof(struct myStack));
    ms->count = 0;
    ms->head = NULL;
    ms->mid = NULL;
    return ms;
}; */
 
//-----Function to push an element to the stack-----
void push(struct myStack *ms, int new_data) {
    /* allocate DLLNode and put in data */
    struct DLLNode* new_DLLNode = (struct DLLNode*) malloc(sizeof(struct DLLNode));
    new_DLLNode->data  = new_data;
    if (ms->head==NULL)
        {
            ms->head=new_DLLNode;
            ms->mid=new_DLLNode;
            ms->head->next=NULL;
            ms->head->prev=NULL;
            ms->count++;
        
        }
        struct DLLNode *temp;
        temp=ms->head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_DLLNode;
    new_DLLNode->next=NULL;
    new_DLLNode->prev=temp;
    ms->count++;
    if (ms->count%2==0)
    {
         struct DLLNode *temp2;
         temp2=ms->head;
        for(int i=0;i<(ms->count/2)+1;i++)
        {
            temp2=temp2->next;
            
        }
        ms->mid=temp2;
    }
     else 
    {
         struct DLLNode *temp3;
         temp3=ms->head;
        for(int i=0;i<ms->count/2;i++)
        {
            temp3=temp3->next;
            
        }
        ms->mid=temp3;
    }
    //-----Appropriately update new_DLLNode and ms to get the functionality-----
    
    
    //-----code ends here-----
}
 
//-----Function to pop an element from stack. Return the popped element-----
//-----Will not be called for empty stack-----
int pop(struct myStack *ms) {
    struct DLLNode *head = ms->head;
    int item = head->data;
    ms->head=head->next;
    ms->head->prev=NULL;
    
    //-----Appropriately update ms to get the required functionality-----
    
    
    //-----code ends here-----
 
    free(head);
 
    return item;
}
 
//-----Function for finding middle of the stack-----
//-----Will not be called for empty stack-----
int findMiddle(struct myStack *ms) {
    //-----code begins here-----
    return ms->mid->data;
    
    //-----code ends here-----
}

//-----Function for deleting middle of the stack-----
//-----Return the value deleted, will not be called for empty stack-----
int deleteMiddle(struct myStack *ms) {
    
    //-----code begins here-----
    struct DLLNode * temp4=ms->head;
    temp4->next->prev=temp4->prev;
    temp4->prev->next=temp4->next;
    if(ms->count%2==0)
    {
        ms->mid=temp4->prev;
        
    }
    else 
    ms->mid=temp4->next;
    //-----code ends here-----
    free(temp4);
}

