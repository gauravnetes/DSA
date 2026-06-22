#include <vector>

using namespace std; 

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {0}; 

        for(auto &trip : trips) {
            diff[trip[1]] += trip[0]; 
            diff[trip[2]] -= trip[0]; 
        } 

        int cumSum = 0; 
        for(int i = 0; i < 1001; i++) {
            cumSum += diff[i]; 
            if(cumSum > capacity) 
                return false; 
        }

        return true; 
    }
};