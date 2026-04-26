#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int n; 
    void solve(int idx, vector<int> &nums, vector<int> &res, vector<int> &temp, int prev) {
        if(idx >= n) {
            if(temp.size() > res.size()) 
                res = temp; 
            return; 
        }

        if(prev == -1 || nums[idx] % prev == 0) {
            temp.push_back(nums[idx]); 
            solve(idx+1, nums, res, temp, nums[idx]); 
            temp.pop_back(); 
        }

        solve(idx+1, nums, res, temp, prev); 
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size(); 
        sort(nums.begin(), nums.end()); 
        vector<int> res; 
        vector<int> temp; 
        solve(0, nums, res, temp, -1); 
        return res; 
    }
};