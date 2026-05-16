#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std; 

class Solution {
public:
    int m, n; 
    unordered_map<string, bool> mp; 

    bool canSurvive(int i, int j, int mid, vector<vector<int>> &grid) {
        if(i >= m || j >= n) 
            return false; 

        mid += grid[i][j]; 

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(mid); 
        if(mp.count(key)) 
            return mp[key]; 

        if(mid <= 0) return mp[key] = false; 

        if(i == m-1 && j == n-1) 
            return mp[key] = true; 

        return mp[key] = canSurvive(i+1, j, mid, grid) || canSurvive(i, j+1, mid, grid);  
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size(); 
        n = dungeon[0].size(); 
 
        int l = 1, r = 4 * 1e7; 
        int minHealth = 4 * 1e7; 

        while(l <= r) {
            int mid = l + (r - l) / 2; 
            mp.clear(); 
            if(canSurvive(0, 0, mid, dungeon)) {
                minHealth = mid; 
                r = mid - 1;  
            } else {
                l = mid + 1; 
            }
        }

        return minHealth; 
    }
};