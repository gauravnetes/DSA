#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); 
        int globalProd = 1;  
        int zeroCnt = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) 
                zeroCnt++; 
            else 
                globalProd *= nums[i];
        }

        vector<int> res; 
        for(int i = 0; i < n; i++) {
            if(zeroCnt > 1) 
                res.push_back(0); 
            else if(zeroCnt == 1 && nums[i] == 0) 
                res.push_back(globalProd); 
            else if(zeroCnt == 1 && nums[i] != 0)
                res.push_back(0); 
            else if(zeroCnt == 0)
                res.push_back(globalProd / nums[i]); 
        }

        return res; 
    }
};