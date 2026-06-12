#include <vector>

using namespace std; 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        int potentialCandidate = nums[0]; 
        int cnt = 1; 
        for(int i = 1; i < n; i++) {
            if(nums[i] == potentialCandidate) 
                cnt++; 
            else {
                cnt--; 
                if(cnt == 0) {
                    potentialCandidate = nums[i]; 
                    cnt = 1; 
                }
            }
        }

        return potentialCandidate; 
    }
};