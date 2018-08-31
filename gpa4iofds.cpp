//************************************************************************************//
/*Example.
#id Name     Friends_id
0   Avik     {1,2}
1   Barath   {2,3,4,5,6}
2   chetty   {4,5,6,7,8}
3   Dinash   {6,7,8,9,10,11,12,13,14}

Input list= { 
            struct{0,{1,2}}, 
            struct{1,{2,3,4,5,6}}, 
            struct{2,{4,5,6,7,8}},
            struct{3,{6,7,8,9,10,11,12,13,14}} 
            }
            
1. Mutual friends between chetty(2) and Barath(1) -> {4,5,6} so result should be 3
2. Uniqe friends of Avik (0) -> {1} so the answer should be 1
3. Strangers to Avik(1)
    - Direct friends {1,2}
    - Friends of friends (1 level) {3,4,5,6,7,8}
    - So, not strangers {1,2,3,4,5,6,7,8}
    - Strangers - { 9,10,11,12,13,14} so the answer should be 6. 
    Note : since Dinash (3) is not a direct friend of Avik(0), but friend through 
    Barath(1). So, friends of Dinash(3) are not friends of Avik(0)
    
//----------------Do not uncommand or recreate struct fbUser------------------------------------------//
//Structure for facebook users, each hase fb unique id -> userID and list of
//friends -> friends
struct fbUser{
    int userID;
    list<int> friends;
};
//------------------------------------------------------------------------------//
    
*/
//************************************************************************************//


//List of Headers
#include<iostream>
#include "header.h"
#include <list>
#include<algorithm>
using namespace std;


//------------------------------------------------------------------------------//


//    **Spcace to add you own functions**           //









//------------------------------------------------------------------------------//
//1. Mutual friends between chetty(2) and Barath(1) -> {4,5,6} so result should be 3
//---------------------------------------------------------------------------------//
int find_mutual_friends(int person1_id,int person2_id, list<fbUser> list_of_fbusers)
{
    int mutual_friends=0;
    list<fbUser>::iterator pt1,pt2;
    for(list<fbUser>::iterator it=list_of_fbusers.begin();it!=list_of_fbusers.end();++it)
    {
        if (it->userID==person1_id)
        pt1=it;
        if(it->userID==person2_id)
        pt2=it;
    }
    for(list<int>::iterator it2=pt1->friends.begin();it2!=pt1->friends.end();it2++)
    
    {
        if (find(pt2->friends.begin(),pt2->friends.end(),*it2)!=pt2->friends.end())
        mutual_friends++;
    }
    //-----------------------------------------//
    //Please write your code here
    
    
    
    //-----------------------------------------//
    return mutual_friends;
}



//---------------------------------------------------------------------------------//
//2, Uniqe friends of Avik (0) -> {1} so the answer should be 1
//---------------------------------------------------------------------------------//
int find_uniq_friends(int person_id, list<fbUser> list_of_fbusers)
{
    int uniq_friends=0;
    //-----------------------------------------//
    //Please write your code here
    
     list<fbUser>::iterator pt1;
    for(list<fbUser>::iterator it=list_of_fbusers.begin();it!=list_of_fbusers.end();++it)
    {
        if (it->userID==person_id) {
        
        
        pt1=it;
       break;
        }
    }
    
   
    for(list<int>::iterator it3=pt1->friends.begin();it3!=pt1->friends.end();++it3)
    {
         bool flag=true;
        for(list<fbUser>::iterator it=list_of_fbusers.begin();it!=list_of_fbusers.end();++it)
        {
            if (it->userID==pt1->userID)
            continue;
           if(find(it->friends.begin(),it->friends.end(),*it3)!=it->friends.end())
          {
          flag=false;
          }
        
        
        }
        if(flag)
        uniq_friends++;
        
        
    
    }
    
        
    
    
    //-----------------------------------------//
    return uniq_friends;
}


//------------------------------------------------------------------------------//
/*3. Strangers to Avik(1)
    - Direct friends {1,2}
    - Friends of friends (1 level) {3,4,5,6,7,8}
    - So, not strangers {1,2,3,4,5,6,7,8}
    - Strangers - { 9,10,11,12,13,14} so the answer should be 6. 
    Note : since Dinash (3) is not a direct friend of Avik(0), but friend through 
    Barath(1). So, friends of Dinash(3) are not friends of Avik(0)
*/
//------------------------------------------------------------------------------//
//Funciton to find the number of strangers
int find_strangers(int person_id, list<fbUser> list_of_fbusers)
{
    int strangers=0;
     list<fbUser>::iterator pt1;
    for(list<fbUser>::iterator it=list_of_fbusers.begin();it!=list_of_fbusers.end();++it)
    {
        if (it->userID==person_id) {
        
        
        pt1=it;
       break;
        }
    }
    for(list<fbUser>::iterator it=list_of_fbusers.begin();it!=list_of_fbusers.end();++it)
    {
        if(it->userID==pt1->userID)
        continue;
        bool flag=true;
         for(list<int>::iterator it3=it->friends.begin();it3!=it->friends.end();++it3)
         {
             if(find(pt1->friends.begin(),pt1->friends.end(),*it3)!=pt1->friends.end())
             {flag =false;
             continue;
             }
             else
             {
                 for(list<int>::iterator it5=pt1->friends.begin();it5!=pt1->friends.end();++it5)
                 {
                     list<fbUser>::iterator pt2;
                     
        for(list<fbUser>::iterator it4=list_of_fbusers.begin();it4!=list_of_fbusers.end();++it4)
    {
    
        if (it4->userID==*it5) {
        
        pt2=it4;
       break;
        }
    }
    if(find(pt2->friends.begin(),pt2->friends.end(),*it3)!=pt2->friends.end())
    flag=false;
                     
                 }
             }
             if(flag)
             strangers++;
         }
    }
    //-----------------------------------------//
    //Please write your code here
    
    //-----------------------------------------//
    return strangers;
}
//------------------------------------------------------------------------------//
