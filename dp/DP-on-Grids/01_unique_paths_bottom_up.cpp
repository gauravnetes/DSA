#include <vector>
using namespace std; 

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n)); 
        t[0][0] = 1; // assuming the start and destination is both (0, 0) and it's a path
        for(int i = 0; i < m; i++) t[i][0] = 1; 
        for(int j = 0; j < n; j++) t[0][j] = 1; 

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                t[i][j] = t[i][j-1] + t[i-1][j]; 
            }
        }
        return t[m-1][n-1]; 
    }
};