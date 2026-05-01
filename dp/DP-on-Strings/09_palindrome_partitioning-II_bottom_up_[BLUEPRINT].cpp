#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length(); 
        vector<vector<bool>> t(n, vector<bool>(n, false)); 

        for(int i = 0; i < n; i++) 
            t[i][i] = true; 

        for(int len = 2; len <= n; len++) {
            for(int i = 0; i+len-1 < n; i++) {
                int j = i + len - 1; 
                if(len == 2) {
                    t[i][j] = (s[i] == s[j]); 
                } else {
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]); 
                }
            }
        }


        vector<int> dp(n); 
        for(int i = 0; i < n; i++) {
            if(t[0][i]) 
                dp[i] = 0; 
            else {
                dp[i] = INT_MAX; 
                for(int k = 0; k < i; k++) {
                    if(t[k+1][i] && 1 + dp[k] < dp[i])
                        dp[i] = 1 + dp[k]; 
                }
            }
        }

        return dp[n-1]; 
    }
};