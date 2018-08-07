#include<iostream>
#include<queue>
using namespace std;
int main()
{

queue<int> q;
q.push(0);
q.push(1);
for(int i =0;i<13;i++)
{

	int a=q.front();
		q.pop();
	int b=q.front();
		q.pop();
	q.push(b);
	q.push(a+b);
	cout<<a<<endl;
}
}
