#include <vector>
using namespace std; 

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt = 0; 
        int n = grid.size(); 

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                bool isEqual = true; 
                for(int i = 0; i < n; i++) {
                    if(grid[r][i] != grid[i][c]) {
                        isEqual = false; 
                        break; 
                    }
                }
                if(isEqual) cnt++; 
            }
        }
        return cnt; 
    }
};