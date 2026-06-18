#include <vector>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        int sumEqK = 0; 
        
        unordered_map<int, int> mp; 

        int cumSum = 0; 
        mp[0] = 1; // as the cumulative sum is = 0 at the start 
        for(int i = 0; i < n; i++) {
            cumSum += nums[i]; 
            if(mp.find(cumSum - k) != mp.end()) {
                sumEqK += mp[cumSum-k];  
            } 
            mp[cumSum]++; 
        }

        return sumEqK; 
    }
};