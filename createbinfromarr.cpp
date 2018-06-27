struct BinTree
{
    int data;
    BinTree *left;
    BinTree *right;
 
    BinTree(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
 
BinTree* createBNode(int data)
{
    return new BinTree(data);
}
 
BinTree* arr_to_tree(int *arr, int size)
{
    BinTree *newTree, *root;
    vector<BinTree*> node_list;
    int i=0;
    root = createBNode(arr[0]);
    node_list.push_back(root);
    while(!node_list.empty())
    {
        newTree = node_list.front();
        node_list.erase(node_list.begin());
        if(2*i + 1 >= size)
            break;
 
        newTree->left = createBNode(arr[2*i+1]);
        node_list.push_back(newTree->left);
        if(2*i+2 >= size)
            break;
 
        newTree->right = createBNode(arr[2*i+2]);
        node_list.push_back(newTree->right);
        i+=1;
    }
    return root;
}
 
void main()
{
    BinTree *tree;
    int arr[] = { 2,3,4,6};
 
    tree = arr_to_tree(arr,4);
 
}

