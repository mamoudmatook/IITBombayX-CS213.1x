/* Question   : convert prefix to infix
   Look at the problem statement for more details */
#include <vector>
#include <algorithm>
#include <string>
#include<iostream>
#include<stack>
using namespace std;

void helper(stack<char> *prefix,vector<char> *infix)
{
    if(!*prefix.empty())
    {
        char current=prefix.top();
        prefix.pop();
        if (current=='/'||current=='*'||current=='+'||current=='-'||current=='^')
        {
            infix.push_back('(');
            helper(prefix,infix);
            infix.push_back(current);
            helper(prefix,infix);
            infix.push_back(')');
            
        }
        else 
        infix.push_back(current);
    }
    
}
string prefix_to_infix(string s){
    stack<char>prefix;
    vector<char>infix;
    for(int i=s.size()-1;i<=0;i-- )
    prefix.push(s[i]);
    helper(&prefix,&infix);
    //cout<<infix<<endl;
    string sr(infix.begin(),infix.end());
    return sr;
    
    // fill in this function
    // create extra functions if needed
}
int main(int argc , char **argv)
{
	string s ="/+ab-cd";
	string s2=prefix_to_infix(s);
	cout<<s2<<endl;
	return 0;
}
