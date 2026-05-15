#include <vector>

using namespace std; 


class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size(); 
        int maxEl = *max_element(nums.begin(), nums.end()); 

        if(n != maxEl + 1) 
            return false; 

        vector<int> freq(maxEl+1, 0); 

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++; 
            if(nums[i] != maxEl && freq[nums[i]] > 1) 
                return false;  
            else if(nums[i] == maxEl && freq[i] > 2) 
                return false;  
        }

        return true; 
    }
};