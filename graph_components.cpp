#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// return the number of connected components of the graph
// look at the problem statement for more detials
  vector <int> intersection(vector<int>v1,vector<int>v2)
  {
      vector<int> v3;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

    return v3;
  }
  vector<int> breadth(int n,int v,vector<vector<int> >list)
  { 
      vector<int>connected;
      int visited[n];
      for(int i=0;i<n;i++)
      visited[n]=0;
      queue<int> q;
      q.push(v);
      visited[v]=1;
      connected.push_back(v);
      while(!q.empty())
      {
          int l=q.front();
          q.pop();
          
          for(int i=0;i<list[l].size();i++)
          {
              if (!visited[list[l][i]])
              {
                  visited[list[l][i]]=1;
                  q.push(list[l][i]);
                  connected.push_back(list[l][i]);
                  
              }
          }
      }
      return connected;
  }
int no_of_connected_components( int N, vector< vector<int> > &adjList){
    // your code here
    vector<int>super;
    vector<int>sub;
    int count=0;
    for(int i=0;i<adjList.size();i++)
    {
        sub=breadth(N,i,adjList);
        vector<int> v=intersection(super,sub);
        if(v.empty())
        count++;
        else 
        super.insert(super.end(), v.begin(), v.end());

    }
    return count;
}

// write any additional function that you want to use here
