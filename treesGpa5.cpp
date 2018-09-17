/*
  Do not remove the "header.h" file.
  
*/
//-----Include any additional required headers here-----

//-----End of additional headers-----
/*
    //-----Don't change/delete struct -----
    struct node {
        int data;
        node * left;
        node * right;
    };
    //----- Struct ends here
*/
//-----Add new functions here(if any)-----



//-----New functions end here-----

/* Question: You need to write the implementations of the given functions .
             ( You may write any additional helper functions you want in the specified region only.
               Do not change the signature of the functions or structs already given.)
               Note that we would be explicitly calling makeBinarySearchTree(vec <int>) and inOrderElements(root) and makeBSTFromSortedVector(vec)
               to check the the functions. In summary, makeBinarySearchTree() function should take the distinct elements present in vector and form a BST from them
               by inserting the elements in same order as present in vector. It should follow the algorithm specified in class which is also present in description
               as pseudo code. inOrderElements() function, which takes the root node of BST as argument, must return the in-order traversal elements as a vector.
               makeBalancedBSTFromSortedVector() function must take a sorted vector and return the root node of a balanced binary search tree.
               You can assume that the vector always contains distinct elements and the length of vector is always of the form 2^n - 1, to form a balanced binary search tree.
               For detailed explanation of the question refer to the description part) 
*/
#include "header.h"
node* make_node(int val)
{
    node* root=(node*)malloc(sizeof(node));
    root->data=val;
    root->left=NULL;
    root->right=NULL;
    return root;
}
 

void insert(node ** pRoot, int val)
{
    if(*pRoot == NULL)
        *pRoot = make_node(val);
    else if((*pRoot)->data<= val)
        insert(&((*pRoot)->right), val);
    else if((*pRoot)->data > val)
        insert(&((*pRoot)->left), val);
}

node* makeBinarySearchTree(vector<int> elements){
node * pRoot = NULL;
    for(int i = 0; i < elements.size(); i++)
        insert(&pRoot, elements[i]);
    return pRoot;
}
void inorder(node* root,vector<int>&data)
{
if (root==NULL)
return;
inorder(root->left,data);
data.push_back(root->data);
inorder(root->right,data);

}
vector<int> inOrderElements(node* root){
  vector<int> data;
    inorder(root,data);
  
    
    return data;    // Make sure to change this to your correct return value..
}
node* makebalanced(vector<int>elements,int start ,int end)
{
    if(start>end)
    return NULL;
    int mid=(start+end)/2;
    node *root=make_node(elements[mid]);
    root->left=makebalanced(elements,start,mid-1);
    root->right=makebalanced(elements,mid+1,end);
    return root;

}
node* makeBalancedBSTFromSortedVector(vector<int> sorted_elements){
   node* root=makebalanced(sorted_elements,0,sorted_elements.size()-1);
    
    
    return root;    // Make sure to change this to your correct return value..
}



