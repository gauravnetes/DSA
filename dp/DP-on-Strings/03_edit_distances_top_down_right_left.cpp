#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 


class Solution {
public:
    int m, n; 
    int dp[501][501];
    int solve(string &s1, string &s2, int m, int n) {
        if(m == 0 || n == 0) 
            return m+n; 

        if(dp[m][n] != -1) 
            return dp[m][n]; 

        if(s1[m-1] == s2[n-1])
            return dp[m][n] = solve(s1, s2, m-1, n-1); 

        int insertion = 1 + solve(s1, s2, m, n-1); 
        int deletion = 1 + solve(s1, s2, m-1, n); 
        int replace = 1 + solve(s1, s2, m-1, n-1); 

        return dp[m][n] = min({insertion, deletion, replace}); 
    }

    int minDistance(string s1, string s2) {
        m = s1.length(); 
        n = s2.length(); 
        memset(dp, -1, sizeof(dp)); 
        return solve(s1, s2, m, n); 
    }
};