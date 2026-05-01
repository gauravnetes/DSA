#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int t[2001][2001]; 
    int dp[2001][2001]; 
    bool isPalindrome(string &s, int i, int j) {
        if(dp[i][j] != -1)
            return dp[i][j]; 
        while(i <= j) {
            if(s[i] != s[j]) 
                return dp[i][j] = false; 

            i++; j--; 
        }
        return dp[i][j] = true; 
    }

    int solve(string &s, int i, int j) {
        if(i >= j) return 0; 

        if(t[i][j] != -1) 
            return t[i][j]; 

        if(isPalindrome(s, i, j)) 
            return 0; 

        int minCuts = INT_MAX; 
        for(int k = i; k < j; k++) {
            int temp = 1 + solve(s, i, k) + solve(s, k+1, j); 
            minCuts = min(temp, minCuts); 
        }
        return t[i][j] = minCuts; 
    }

    int minCut(string s) {
        int n = s.length(); 
        memset(dp, -1, sizeof(dp)); 
        memset(t, -1, sizeof(t)); 
        return solve(s, 0, n-1); 
    }
};