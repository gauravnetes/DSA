#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closestSum = INT_MAX;
        int minDiff = INT_MAX; 

        for (int i = 0; i < n; i++) {

            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k]; 
                int diff = abs(target - sum);  
                
                if(diff < minDiff) {
                    minDiff = diff; 
                    closestSum = sum; 
                }

                if(sum < target)  
                    j++; 
                else 
                    k--; 
            }
        }

        return closestSum;
    }
};