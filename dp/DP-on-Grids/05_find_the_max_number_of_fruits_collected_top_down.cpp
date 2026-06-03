#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int n; 
    int dp[1001][1001]; 
    int solveChB(int i, int j, vector<vector<int>> &fruits) {
        if(i < 0 || i >= n || j < 0 || j >= n || i == j || i > j) 
            return 0; 

        if(i == n-1 && j == n-1) // collected by c1
            return 0; 

        if(dp[i][j] != -1) 
            return dp[i][j]; 

        int dir1 = fruits[i][j] + solveChB(i+1, j-1, fruits);
        int dir2 = fruits[i][j] + solveChB(i+1, j, fruits); 
        int dir3 = fruits[i][j] + solveChB(i+1, j+1, fruits);  

        return dp[i][j] = max({dir1, dir2, dir3}); 
    }

    int solveChC(int i, int j, vector<vector<int>> &fruits) {
        if(i < 0 || i >= n || j < 0 || j >= n || i == j || i < j) 
            return 0; 

        if(i == n-1 && j == n-1) // c1 already collected this room
            return 0; 

        if(dp[i][j] != -1) 
            return dp[i][j]; 

        int dir1 = fruits[i][j] + solveChC(i-1, j+1, fruits);
        int dir2 = fruits[i][j] + solveChC(i, j+1, fruits); 
        int dir3 = fruits[i][j] + solveChC(i+1, j+1, fruits);  

        return dp[i][j] = max({dir1, dir2, dir3}); 
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size(); 

        memset(dp, -1, sizeof(dp)); 

        int c1 = 0; 
        for(int i = 0; i < n; i++) {
            c1 += fruits[i][i]; 
        }

        int c2 = solveChB(0, n-1, fruits); 
        int c3 = solveChC(n-1, 0, fruits); 

        return c1 + c2 + c3; 
    }
};