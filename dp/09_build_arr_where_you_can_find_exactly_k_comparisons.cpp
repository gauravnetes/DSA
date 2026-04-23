#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int N, M, K; 
    int dp[51][51][101]; 
    int MOD = 1e9+7; 
    
    int solve(int idx, int sc, int maxVal) {
        if(idx == N) {
            if(sc == K) 
                return 1; 
            return 0; 
        }

        if(dp[idx][sc][maxVal] != -1)
            return dp[idx][sc][maxVal]; 

        int res = 0; 
        for(int i = 1; i <= M; i++) {
            if(i > maxVal) 
                res = (res + solve(idx+1, sc+1, i)) % MOD; 
            else 
                res = (res + solve(idx+1, sc, maxVal)) % MOD; 
        }
        return dp[idx][sc][maxVal] = res; 
    }

    int numOfArrays(int n, int m, int k) {
        N = n; 
        M = m; 
        K = k; 
        memset(dp, -1, sizeof(dp)); 
        return solve(0, 0, 0); 
    }
};