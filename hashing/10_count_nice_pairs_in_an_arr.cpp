#include <vector>
#include <unordered_map>
using namespace std; 


class Solution {
public:
    int MOD = 1e9+7; 

    int rev(int num) {
        int revNum = 0; 
        while(num > 0) {
            int temp = num % 10; 
            revNum = revNum * 10 + temp; 
            num /= 10; 
        }

        return revNum; 
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size(); 

        for(int i = 0; i < n; i++) {
            nums[i] = (nums[i] - rev(nums[i])); 
        }

        int res = 0; 
        unordered_map<int, int> mp; 
        for(int i = 0; i < n; i++) {
            res = (res + mp[nums[i]]) % MOD; 
            mp[nums[i]]++; 
        }

        return res; 
    }
};