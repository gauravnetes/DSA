#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int m, n; 
    int dp[201][201]; 

    int solve(int i, int j, vector<vector<int>> &grid) {
        if(i >= m || j >= n) 
            return 1e9; 
        
        if(dp[i][j] != -1) 
            return dp[i][j]; 

        if(i == m-1 && j == n-1) {
            if(grid[i][j] > 0) 
                return dp[i][j] = 1; 
            else 
                return dp[i][j] = abs(grid[i][j]) + 1; 
        }

        int right = solve(i, j+1, grid); 
        int down = solve(i+1, j, grid); 

        int res = min(right, down) - grid[i][j]; 
        return dp[i][j] = res > 0 ? res : 1; 
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size(); 
        n = dungeon[0].size(); 

        memset(dp, -1, sizeof(dp)); 
 
        return solve(0, 0, dungeon); 
    }
};