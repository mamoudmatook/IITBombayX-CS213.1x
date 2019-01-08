#include "header.h"

#include <string>

using namespace std;



/*

  Do not remove the "header.h" file.

*/



//-----Include any additional required headers here-----



//-----End of additional headers-----



//-----Add new functions here(if any)-----





//-----New functions end here-----



/* Question: You need to write the implementation of the given function.

             ( You may write any additional helper functions you want in the specified region only.

               Do not change the signature of the function already given)

               For detailed explanation of the question refer to the description part) 

*/



/*

    

   The function findMinHashDiff takes two strings,a text and a pattern as input.Both of these strings contain only numeric digits from '0' to '9' as their characters.

   Given a string , we define the hash value of the string by the numeric value of that string (in base-10) modulo 1000000007 (10^9 + 7 - A prime !!). 

   Now consider the set of all substrings of the 'text' which are of length equal to that of the pattern. (A substring implies a consecutive streak of characters,i.e. consider

   all text.substr(pattern,pattern.size()) ) .We wish to find the minimum possible difference in hash values of an element from the set of substrings and the original pattern.

   (Note that difference between hash values is non-negative)

   

   Your aim is to complete the function which finds out this minimum possible difference in hash values given the text and the pattern. 

   We check the correctness of your function by calling your function with an input text and pattern parameters.

    

   We expect an O((m-n+1)*n)) algorithm where m is the length of the text and n is the length of the pattern.

   (Hint : You NEED NOT compute the hash value of the substring from the beginning each time !!)

   (Also remember to use long long's instead of int's)

   

   Constraints for graded-test cases ::



   length(text)    <= 1000000

   length(pattern) <= 1000

    

   If your program takes too much time, you would get a timeout !! (your process would be killed by default)

*/



long long findMinHashDiff(string text,string pattern) {

 long long minHash=0;

long long  hpat=atoi(pattern.c_str())%1000000007;



unsigned int M=pattern.size();

unsigned int N=text.size();

long long htxt=atoi(text.substr(0,M).c_str())%1000000007;

minHash=abs(htxt-hpat);

long long lhash;

for (unsigned int i=0;i<=N-M;i++)

{

    lhash=atoi(text.substr(i,M).c_str())%1000000007;

    if(abs(lhash-hpat)<minHash)

    minHash=lhash;

}

return minHash;



    

    

}
