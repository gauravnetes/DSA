#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(); 
        int maxLen = 0; 

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) 
                nums[i] = -1;  
        }

        for(int i = 0; i < n; i++) {
            int cumSum = nums[i]; 
            for(int j = i+1; j < n; j++) {
                cumSum += nums[j]; 
                if(cumSum == 0) 
                    maxLen = max(j-i+1, maxLen); 
            }    
        }

        return maxLen; 
    }
};