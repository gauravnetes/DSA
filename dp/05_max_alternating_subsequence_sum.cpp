#include <vector>

using namespace std; 

class Solution {
public:
    typedef long long ll; 
    ll t[1000001][2]; 

    ll solve(vector<int> &nums, int idx, bool isEven) {    
        if(idx >= nums.size()) return 0; 

        if(t[idx][isEven] != -1) 
            return t[idx][isEven]; 

        ll skip = solve(nums, idx + 1, isEven); 

        ll val = nums[idx]; 
        if(!isEven)
            val = -val; 

        ll take = solve(nums, idx + 1, !isEven) + val; 

        return t[idx][isEven] = max(skip, take); 
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; 
        memset(t, -1, sizeof(t)); 
        bool isEven = true; 
        return solve(nums, 0, isEven); 
    }
};