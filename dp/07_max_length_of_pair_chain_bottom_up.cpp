#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n == 1) return 1; 

        sort(pairs.begin(), pairs.end()); 
        
        vector<int> t(n, 1); 
        int maxLIS = 1; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    t[i] = max(t[i], t[j]+1); 
                    maxLIS = max(maxLIS, t[i]); 
                }
            }
        }
        return maxLIS;  
    }
};