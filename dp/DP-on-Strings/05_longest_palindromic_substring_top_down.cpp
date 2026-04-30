#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int dp[1001][1001]; 

    bool checkPalindrome(string &s, int i, int j) {
        if(i >= j) 
            return true; 

        if(dp[i][j] != -1)
            return dp[i][j]; 

        if(s[i] == s[j]) 
            return dp[i][j] = checkPalindrome(s, i+1, j-1); 
        else 
            return dp[i][j] = false; 
    }

    string longestPalindrome(string s) {
        int n = s.length(); 
        if(n == 1)
            return s; 
        if(n == 2 && s[0] == s[1]) {
            return s; 
        } 

        memset(dp, -1, sizeof(dp)); 

        int maxLen = 0, start = 0; 
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(checkPalindrome(s, i, j)) {
                    if(j-i+1 > maxLen) {
                        maxLen = j-i+1; 
                        start = i; 
                    }
                }
            }
        }

        return s.substr(start, maxLen); 
    }
};