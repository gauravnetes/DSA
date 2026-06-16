#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(); 
        int maxLen = 0; 

        for(int i = 0; i < n; i++) {
            int cnt0 = nums[i] == 0 ? 1 : 0;  
            int cnt1 = nums[i] == 1 ? 1 : 0; 
            int len = 1; 
            for(int j = i+1; j < n; j++) {
                if(nums[j] == 1) {
                    cnt1++; 
                    len++; 
                } else {
                    cnt0++; 
                    len++; 
                }   

                if(cnt1 == cnt0) {
                    maxLen = max(len, maxLen); 
                }
            }
        }
        return maxLen; 
    }
};