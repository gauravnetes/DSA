#include <vector>
using namespace std; 

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size(); 
        
        long long maxEl = INT_MIN; 
        long long minEl = INT_MAX; 

        for(int i = 0; i < n; i++) {
            maxEl = max((int)maxEl, nums[i]); 
            minEl = min((int)minEl, nums[i]); 
        }

        return (maxEl - minEl) * k; 
    }
};