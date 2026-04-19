#include <vector>

using namespace std; 

class Solution {
public:
    int t[101]; 

    int rob(vector<int>& nums) {
        int n = nums.size(); 

        if(n == 1) return nums[0];  
        if(n == 2) return max(nums[0], nums[1]); 

        vector<int> t(n+1, 0); 
        t[0] = 0; 
        for(int i = 1; i < n; i++) {
            int skip = t[i - 1]; 
            int take = nums[i-1] + (i - 2 >= 0 ? t[i-2] : 0); 
            t[i] = max(skip, take); 
        }
        int res1 = t[n - 1]; 

        t.clear(); 
        t[0] = 0; 
        t[1] = 0; 
        for(int i = 2; i <= n; i++) {
            int skip = t[i - 1]; 
            int take = nums[i-1] + (i + 2 >= 0 ? t[i-2] : 0); 
            t[i] = max(skip, take); 
        }
        int res2 = t[n]; 

        return max(res1, res2); 
    }
};