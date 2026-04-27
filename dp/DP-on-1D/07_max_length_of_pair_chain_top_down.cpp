#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int dp[1001][1001]; 

    int solve(vector<vector<int>> &pairs, int idx, int prev) {
        if(idx >= pairs.size()) 
            return 0; 

        if(dp[idx][prev+1] != -1) 
            return dp[idx][prev+1]; 

        int take = 0; 
        if(prev == -1 || pairs[prev][1] < pairs[idx][0]) 
            take = 1 + solve(pairs, idx+1, idx); 

        int skip = solve(pairs, idx+1, prev); 

        return dp[idx][prev+1] = max(take, skip);  
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end()); 
        memset(dp, -1, sizeof(dp)); 
        return solve(pairs, 0, -1); 
    }
};