#include "header.h"
/*
  Do not remove the "header.h" file.
*/

//-----Include any additional required headers here-----

//-----End of additional headers-----

/*
  The graph is represented in the adjacency list representation using
  vector of vectors of int
  vector<vector<int> > graph;
*/

//-----Add new functions here(if any)-----


//-----New functions end here-----

/* Question: You need to write the implementations of the given functions .
             ( You may write any additional helper functions you want in the specified region only.
               Do not change the signature of the function already given)
               For detailed explanation of the question refer to the Description part) 
*/
 void helper(vector<vector<int> > graph ,int visited[],int start,int *count)
 {
     visited[start]=1;
     
     vector<int>::iterator i;
     for(i=graph[start].begin();i!=graph[start].end();++i)
     {   if (!visited[*i])
         *count+=graph[*i].size();
         helper(graph,visited,*i,count);
     }
     
     
 }

int numNodesReachable(vector<vector<int> > graph, int start){
 // write your code below this line
 
  int visited[graph.size()];
  for (int l=0;l<graph.size();l++)
   visited[l]=0;
   vector<int>::iterator i;
   int *count;
   *count=0;
   helper(graph,visited,start,count);
   return *count+1+graph[start].size();
   
  
 
 
}
