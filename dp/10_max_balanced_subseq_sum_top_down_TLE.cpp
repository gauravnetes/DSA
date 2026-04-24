#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std; 

class Solution {
public:
    // long long dp[1000001][1000001]; out of bounds 
    unordered_map<string, long long> mp; 
    long long solve(int idx, int prev, vector<int> &nums) {
        if(idx >= nums.size()) 
            return 0; 
        
        string key = to_string(prev) + "_" + to_string(idx); 
        if(mp.find(key) != mp.end())
            return mp[key]; 
        
        long long take = LLONG_MIN; 
        long long skip = LLONG_MIN; 

        if(prev == -1 || nums[idx] - idx >= nums[prev] - prev) 
            take = nums[idx] + solve(idx+1, idx, nums); 

        skip = solve(idx+1, prev, nums); 

        return mp[key] = max<long long>(take, skip); 
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int maxEl = *max_element(nums.begin(), nums.end()); 

        if(maxEl <= 0)
            return maxEl; 
        return solve(0, -1, nums); 
    }
};