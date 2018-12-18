#include "header.h"



using namespace std;



Graph::Graph(int V)

{

    this->V = V;

    adj = new list<int>[V];

}



void Graph::addEdge(int node1, int node2)

{

    adj[node1].push_back(node2);

}







bool Graph::checkCyclicNode(int node, bool visited[], bool *currentIter)

{

  //Write your code here

  

  

}



bool Graph::checkCyclicGraph()

{

//Write your code here

 bool *visited = new bool[V];

    bool *currentIter = new bool[V];

    for(int i = 0; i < V; i++)

    {

        visited[i] = false;

        currentIter[i] = false;

    }

 

    // Call the recursive helper function to detect cycle in different

    // DFS trees

    for(int i = 0; i < V; i++)

        if (checkCyclicNode(i, visited, currentIter))

            return true;

 

    return false;





}


