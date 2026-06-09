#include <vector>

using namespace std;

class Solution {
  public:
    int n; 
    int dp[1001][1001];
    
    int solve(int n, vector<int> &wt, vector<int> &val, int W) {
        if(n == 0 || W == 0) 
            return 0; 
        
        if(dp[n][W] != -1) 
            return dp[n][W]; 
            
        int take = 0; 
        int skip = 0; 
        if(W >= wt[n-1]) {
            take = val[n-1] + solve(n-1, wt, val, W - wt[n-1]); 
        }
        
        skip = solve(n-1, wt, val, W); 
        
        return dp[n][W] = max(take, skip); 
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n = val.size(); 
        memset(dp, -1, sizeof(dp)); 
        return solve(n, wt, val, W); 
    }
};