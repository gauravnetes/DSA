#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    bool solve(string &s, int i, int j) {
        if(i >= j) 
            return true; 
        
        if(s[i] == s[j])
            solve(s, i+1, j-1); 
        else 
            return false; 
    }
        
    bool isPalindrome(string& s) {
        // code here
        int n = s.length();  
        return solve(s, 0, n-1); 
    }
};