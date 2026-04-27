#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
  public:
    int dp[501][501]; 
    int solve(string &s1, string &s2, int m, int n) {
        if(m == 0 || n == 0)
            return m+n; 
            
        if(dp[m][n] != -1)
            return dp[m][n]; 
            
        if(s1[m-1] == s2[n-1]) 
            return dp[m][n] = 1 + solve(s1, s2, m-1, n-1); 
        else 
            return dp[m][n] = 1 + min(solve(s1, s2, m, n-1), solve(s1, s2, m-1, n)); 
    
        return 0; 
    }
    
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int m = s1.length(); 
        int n = s2.length(); 
        memset(dp, -1, sizeof(dp)); 
        return solve(s1, s2, m, n); 
    }
};