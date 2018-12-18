#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
  Do not remove the "header.h" file.
*/

//-----Include any additional required headers here-----

//-----End of additional headers-----

//-----Add new functions here(if any)-----


//-----New functions end here-----

/* You need to write the implementation of the given function.
             ( You may write any additional helper functions you want in the specified region only.
               Do not change the signature of the function already given)
               For detailed explanation of the question refer to the Description part)
*/
 void right(int coordinateX, int coordinateY, queue<int> & Qx, queue<int> & Qy, vector<vector<char> > & graph , bool visited[10][10] , vector <char> & answer)
 {
     if (++coordinateX>9)
     return;
     
     if(!visited[coordinateX][coordinateY]&&graph[coordinateX][coordinateY]!='x')
     {
         Qx.push(coordinateX);
         Qy.push(coordinateY);

         answer.push_back(graph[coordinateX][coordinateY]);
     }


 }
 void left(int coordinateX, int coordinateY, queue<int> & Qx, queue<int> & Qy, vector<vector<char> > & graph , bool visited[10][10] , vector <char> & answer)
 {
     if (--coordinateX<0)
     return;
     if(!visited[coordinateX][coordinateY]&&graph[coordinateX][coordinateY]!='x')
     {
         Qx.push(coordinateX);
         Qy.push(coordinateY);
visited[coordinateX][coordinateY]=true;
answer.push_back(graph[coordinateX][coordinateY]);
     }
 }
 void up(int coordinateX, int coordinateY, queue<int> & Qx, queue<int> & Qy, vector<vector<char> > & graph , bool visited[10][10], vector <char> & answer)
 {
     if (--coordinateY<0)
     return;
     if(!visited[coordinateX][coordinateY]&&graph[coordinateX][coordinateY]!='x')
     {
         Qx.push(coordinateX);
         Qy.push(coordinateY);
         visited[coordinateX][coordinateY]=true;
         answer.push_back(graph[coordinateX][coordinateY]);
     }
 }
 void down(int coordinateX, int coordinateY, queue<int> & Qx, queue<int> & Qy, vector<vector<char> > & graph , bool visited[10][10] , vector <char> & answer)

{
    if (++coordinateY>9)
     return;
     if(!visited[coordinateX][coordinateY]&&graph[coordinateX][coordinateY]!='x')
     {
         Qx.push(coordinateX);
         Qy.push(coordinateY);
         visited[coordinateX][coordinateY]=true;
         answer.push_back(graph[coordinateX][coordinateY]);
     }
}
void move(int coordinateX, int coordinateY, queue<int> & Qx, queue<int> & Qy, vector<vector<char> > & graph , bool visited[10][10] , vector <char> & answer)
{   // DO NOT CHANGE THIS!
    /*
    coordinateX, coordinateY are your current coordinates
    Qx,Qy are the queues where you have to store the coordinates of x and y for the valid blocks
    graph is the matrix representation for the city as a 2D vector
    */
    // start your code below this line
    Qx.push(coordinateX);
    Qy.push(coordinateY);
    while(!Qx.empty())
    {
        int x=Qx.front();
        Qx.pop();
        int y=Qy.front();
        Qy.pop();
        right(x,y,Qx,Qy,graph,visited,answer);

        down(x,y,Qx,Qy,graph,visited,answer);
        left(x,y,Qx,Qy,graph,visited,answer);
        up(x,y,Qx,Qy,graph,visited,answer);
    }
}

int main()
{
	vector<vector<char> > graph {{ '6', '0', '6', '2', '2', '8', '8', '5', '9', '3' } , { '0', '5', '7', 'x', '2', '7', '3', '3', '6', '8' }, {'0', '6', '1','6', '6', '5', '0', '3', '9', '0' },  {'5','2', '9','1', '2', '0' ,'9', '8', '6' ,'5'  }, {'0', '4', 'x', '6', '3', 'x', '2', '5', '2', '8'}, {'2', '1', '3', '3', '7', '7', '7', '5', 'x', '3'}, {'4', '3', '5', '2', '4', '7', '3', '0', '5', '7' }, {'4', '3', '9', '3', '7', '2', '3', '9', '7', '3'}, { '4', '7', '4', '6', '0', '9', '0','5','4', '9' }, { '8', '8', 't', '0', 'x', '5' ,'5' ,'0', '3', '8' } };
	bool  visited[10][10];
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
		visited[i][j]=false;
	queue<int> Qx;
	queue<int> Qy;
	vector<char>answer;

        move(0,0,Qx,Qy,graph,visited,answer);
	for(int i=0;i<answer.size();i++)
		cout<<answer[i]<<endl;
}
