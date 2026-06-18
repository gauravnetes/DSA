#include <vector>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        int sumEqTarget = 0; 

        for(int r = 0; r < m; r++) {
            for(int c = 1; c < n; c++) {
                matrix[r][c] += matrix[r][c-1]; 
            }
        }


        int res = 0; 
        for(int sc = 0; sc < n; sc++) {
            for(int j = sc; j < n; j++) {
                unordered_map<int, int> mp; 
                int cumSum = 0; 
                mp[0] = 1; 
                for(int row = 0; row < m; row++) {
                    cumSum += matrix[row][j] - (sc > 0 ? matrix[row][sc-1] : 0); 
                    if(mp.find(cumSum - target) != mp.end()) 
                        sumEqTarget += mp[cumSum - target];  
                    
                    mp[cumSum]++; 
                }
            }
        }

        return sumEqTarget; 
    } 
};