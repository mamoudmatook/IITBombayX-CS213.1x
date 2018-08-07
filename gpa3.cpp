#include "header.h"
/*
  Do not remove the "header.h" file.
*/

//-----Include any additional required headers here-----

//-----End of additional headers-----

//-----Add new functions here(if any)-----
        void look_right(int x,int y,queue<int> & Qx, queue<int> & Qy, vector<vector<char> > & graph , vector<vector<bool> > & visited , vector <char> & answer)
        {
            if (y+1>graph[x].size()-1)
            return;
            else
            {
                if(!visited[x][y+1]&&graph[x][y+1]!='x')
                {
                    Qx.push(x);
                    Qy.push(y+1);
                    answer.push_back(graph[x][y+1]);
                    visited[x][y+1]=true;
                }
            }
            
        }
        void look_down(int x,int y,queue<int> & Qx, queue<int> & Qy, vector<vector<char> > & graph , vector<vector<bool> > & visited , vector <char> & answer)
        {
            
        if (x+1>graph.size()-1)
            return;
            else
            {
                if(!visited[x+1][y]&&graph[x+1][y]!='x')
                {
                    Qx.push(x+1);
                    Qy.push(y);
                    answer.push_back(graph[x+1][y]);
                    visited[x+1][y]=true;
                }
            }
            
        }
        void look_left(int x,int y,queue<int> & Qx, queue<int> & Qy, vector<vector<char> > & graph , vector<vector<bool> > & visited , vector <char> & answer)
        {
            if (y-1)
            return;
            else
            {
                if(!visited[x][y-1]&&graph[x][y-1]!='x')
                {
                    Qx.push(x);
                    Qy.push(y-1);
                    answer.push_back(graph[x][y-1]);
                    visited[x][y-1]=true;
                }
            }
            
        }
        void look_up(int x,int y,queue<int> & Qx, queue<int> & Qy, vector<vector<char> > & graph , vector<vector<bool> > & visited , vector <char> & answer)
        {
               
        if (x-1<0)
            return;
            else
            {
                if(!visited[x-1][y]&&graph[x-1][y]!='x')
                {
                    Qx.push(x-1);
                    Qy.push(y);
                    answer.push_back(graph[x-1][y]);
                    visited[x-1][y]=true;
                }
            }
        }
        


//-----New functions end here-----

/* You need to write the implementation of the given function.
             ( You may write any additional helper functions you want in the specified region only.
               Do not change the signature of the function already given)
               For detailed explanation of the question refer to the Description part) 
*/

void move(int coordinateX, int coordinateY, queue<int> & Qx, queue<int> & Qy, vector<vector<char> > & graph , vector<vector<bool> > & visited , vector <char> & answer)
{   // DO NOT CHANGE THIS!
    /*
    coordinateX, coordinateY are your current coordinates
    Qx,Qy are the queues where you have to store the coordinates of x and y for the valid blocks
    graph is the matrix representation for the city as a 2D vector
    */
    // start your code below this line
    while((!Qx.empty())&&(!Qy.empty()) )
    {
        int x=Qx.front();
        Qx.pop();
        int y=Qy.front();
        Qy.pop();
        if (graph[x][y]=='t')
        break;
        look_right(coordinateX,coordinateY,Qx,Qy,graph,visited,answer);
        look_down(coordinateX,coordinateY,Qx,Qy,graph,visited,answer);
        look_left(coordinateX,coordinateY,Qx,Qy,graph,visited,answer);
        look_up(coordinateX,coordinateY,Qx,Qy,graph,visited,answer);
    
   
    }
}
