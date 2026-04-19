#include <vector>

using namespace std; 

class Solution {
public:
    int solve(vector<int> &nums, int l, int r) {
        int prev = 0, prevPrev = 0; 
        for(int i = l; i <= r; i++) {
            int steal = nums[i] + prevPrev; 
            int skip = prev; 

            int temp = max(steal, skip); 
            prevPrev = prev; 
            prev = temp; 
        }
        return prev; 
    }

    int rob(vector<int>& nums) {
        int n = nums.size(); 

        if(n == 1) return nums[0];  
        if(n == 2) return max(nums[0], nums[1]); 

        int take_0th_house = solve(nums, 0, n-2); 
        int skip_0th_house = solve(nums, 1, n-1); 

        return max(take_0th_house, skip_0th_house); 
    }
};