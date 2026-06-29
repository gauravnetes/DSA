#include <vector>

using namespace std; 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        int sumEqK = 0; 
        for(int i = 0; i < n; i++) {
            int currSum = 0; 
            for(int j = i; j < n; j++) {
                currSum += nums[j]; 
                if(currSum == k) 
                    sumEqK++; 
            }
        }
        return sumEqK; 
    }
};