#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(); 
        sort(nums.begin(), nums.end()); 
        vector<int> res; 
        vector<int> dp(n, 1); 
        vector<int> prevIdx(n, -1); 
        int maxL = 1; 
        int maxLIdx = 0; 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[i] < dp[j]+1) {
                        dp[i] = dp[j]+1; 
                        prevIdx[i] = j; 
                    }

                    if(dp[i] > maxL) {
                        maxL = dp[i]; 
                        maxLIdx = i; 
                    }
                }
            }
        }

        while(maxLIdx != -1) {
            res.push_back(nums[maxLIdx]); 
            maxLIdx = prevIdx[maxLIdx]; 
        }
        
        return res; 
    }
};