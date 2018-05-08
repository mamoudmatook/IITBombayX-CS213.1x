#include "header.h"
/* DON"T REMOVE OR CHANGE THE ABOVE HEADER
class twoStacks
{
	int *arr;// array has only non negative elements.
	int size;
	int top1;
    //top1 is index of the topmost element of stack1 and is -1 if stack1 is empty  
    int top2;
    // top2 is index of the topmost element of stack2 and is equal to size if stack2 is empty 
public:
	twoStacks(int n) // constructor
	{
		size = n;
		arr = new int[n];
		top1 = -1; // note this initialization
		top2 = size;// note this initialization
	}
	bool push1(int i);//push i onto stack 1
	bool push2(int i);
	int pop1();// pop top element from stack 1
	int pop2();
    void double_resize();// resize the arr to double its current size
};
*/

/*
Function double_size() must double the size of the array by reallocating the array using the C++ operator new, and copy both the stacks into this newly created array.
It must also deallocate the dynamic memory previously allocated to the arr by using the keyword delete in C++
*/
void twoStacks::double_resize() {
    int l=0;
                                    int *arr2=arr;
                                    arr=new int[2*size];
                                    for(int i=size-1; i>=top2;i--)
                                    {
                                        arr[2*size-1-1]=arr2[i];
                                     l++;   
                                    }
                                    top2=2*size-(size-top2);
                                    for(int i=0;i<=top1;i++)
                                    arr[i]=arr2[i];
                                    delete arr2;
                                    size=2*size;
 
	// WRITE YOUR CODE HERE
  


}


/*
	If stack1 is not full then the function push1(int i) should add element i into stack1 and return true. 
	Else it should return false
*/
bool twoStacks::push1(int i) {
    if(top2-top1==1)
     //double_resize(); if we want to resiz
     return false;
     top1++;
     arr[top1]=i;
     return true;
    
    
	//WRITE YOUR CODE HERE



	// RETURN A BOOLEAN VALUE HERE
}

/*
	If stack2 is not full then the function push2(int i) should add element i into stack2 and return true. 
	Else it should return false
*/

bool twoStacks::push2(int i) {
	//WRITE YOUR CODE HERE
	if(top2-top1==1)
     //double_resize(); if we want to resiz
     return false;
     top2--;
     arr[top2]=i;
     return true;



	// RETURN A BOOLEAN VALUE HERE
}

/*
If stack1 is not empty then the function pop1() should pop the top most element from the stack and return its value.
If stack1 is empty then the function pop1() must return -1
You may assume that the arr contains only non-negative integers
*/
int twoStacks::pop1() {
	// FUNCTION MUST RETURN AN INTEGER VALUE
	//WRITE YOUR CODE HERE
 if (top1==-1)
 return  -1;
 int m=arr[top1];
 top1--;
 return m;
}



/*
If stack2 is not empty then the function pop2() should pop the top most element from the stack and return its value.
If stack2 is empty then the function pop2() must return -1
You may assume that the arr contains only non-negative integers
*/
int twoStacks::pop2() {
	// FUNCTION MUST RETURN AN INTEGER VALUE
	//WRITE YOUR CODE HERE
	if (top2==size)
 return  -1;
 int m=arr[top2];
 top2++;
 return m;


}
