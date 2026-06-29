#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        k = k % n; 
        vector<int> res; 

        int j = n-1;  
        int _k = k; 
        while(_k--) {
            res.push_back(nums[j]); 
            j--; 
        }

        reverse(res.begin(), res.end()); 
 
        for(int x = 0; x < n-k; x++) {
            res.push_back(nums[x]); 
        }

        nums = res; 
    }
};