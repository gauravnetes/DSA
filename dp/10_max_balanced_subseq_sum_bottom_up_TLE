#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
public:

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size(); 
        int maxEl = *max_element(nums.begin(), nums.end()); 

        if(maxEl <= 0)
            return maxEl; 
        vector<long long> t(n); 
        long long maxSum = LLONG_MIN; 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] - i >= nums[j] - j) {
                    t[i] = max<long long>((long long)t[i], (long long) t[j] + nums[i]); 
                    maxSum = max<long long>((long long)maxSum, (long long) t[i]); 
                }
            }
        }
        return maxSum > maxEl ? maxSum : maxEl; 
    }
};