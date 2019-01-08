#include "header.h"
/*
  Do not remove the "header.h" file.
  
*/
//-----Include any additional required headers here-----

//-----End of additional headers-----
/* Problem definition below :  
   DONOT UNCOMMENT BELOW CODE OR DESCRIPTION        
    class hiddenString {
        private:
          string data;
        public:
        int getSize();
    };
    
    bool s1OfiEqualTos2Ofj(hiddenString s1, int i, hiddenString s2, int j);

    //----- Struct's end here
  Assume that above class and function are defined and an object of this class is given as input to your function getPatternMatchIndices

/* Question: You need to implement below given function
             ( You may write any additional helper functions you want in the specified region only.
               You cannot change the signature of the functions or struct's already given.)
               Note that we would be explicitly calling getPatternMatchIndices(hiddenString& word, hiddenString& pattern) to check the the functions. Also, note that changing the signature of this function in anyway would cause your code not to compile.
              
              Since the string data declared in the above class is private, you cannot directly access it to find the duplicate indices.
              You can only invoke the function bool s1OfiEqualTos2Ofj(hiddenString &s1, int i, hiddenString &s2, int j) on the object of class hiddenVector given as an input to your function, which returns true if and only if the s1.data[i] is equal to s2.data[i]. However you cannot directly do the above check in your function because data is a private member of the class hiddenVector.
              In addition you could also use the function getSize on the object passed as input to your function of class hiddenVector to know the size of the underlying string data.

              For detailed explanation of the question refer to the Description part) 
*/
//-----Add new functions here(if any)-----





//-----New functions end here-----
/* Following program is a C implementation of Rabin Karp 
Algorithm given in the CLRS book */
// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 

void computeLPSArray(hiddenString& pat, int M, int* lps); 

// Prints occurrences of txt[] in pat[] 
vector<int>  KMPSearch(hiddenString&  pat, hiddenString& txt) 
{ 
	int M = pat.getSize(); 
	int N = txt.getSize(); 
     vector<int>match;
     //create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int lps[M]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (s1OfiEqualTos2Ofj(pat,j,txt,i)) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			//printf("Found pattern at index %d ", i - j); 
			match.push_back(i-j);
			
			j = lps[j - 1]; 
		} 

		// mismatch after j matches 
		else if (i < N && (!s1OfiEqualTos2Ofj(pat,j,txt,i)))
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	 
	return match;
} 

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(hiddenString& pat, int M, int* lps) 
{ 
	// length of the previous longest prefix suffix 
	int len = 0; 

	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 
	while (i < M) { 
		if (s1OfiEqualTos2Ofj(pat,i,pat,len)) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (pat[i] != pat[len]) 
		{ 
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) { 
				len = lps[len - 1]; 

				// Also, note that we do not increment 
				// i here 
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

// Driver program to test above function 
/*
int main() 
{ 
	char txt[] = "ABABDABACDABABCABAB"; 
	char pat[] = "ABABCABAB"; 
	KMPSearch(pat, txt); 
	return 0; 
} */



vector<int> getPatternMatchIndices(hiddenString& word, hiddenString& pattern){
    vector <int> matchedIndices;
     matchedIndices=KMPSearch(pattern,word);
    return matchedIndices;

}
