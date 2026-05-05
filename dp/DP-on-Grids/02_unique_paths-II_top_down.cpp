#include <vector>
using namespace std; 

class Solution {
public:
    int m, n; 
    int dp[101][101];

    int solve(int i, int j, vector<vector<int>>& grid) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j]) 
            return 0; 

        if(dp[i][j] != -1) 
            return dp[i][j]; 

        if(i == m-1 && j == n-1) 
            return dp[i][j] = 1; 

        int right = solve(i, j+1, grid); 
        int down = solve(i+1, j, grid); 

        return dp[i][j] = right+down; 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m = grid.size(); 
        n = grid[0].size(); 

        memset(dp, -1, sizeof(dp)); 
        return solve(0, 0, grid); 
    }
};