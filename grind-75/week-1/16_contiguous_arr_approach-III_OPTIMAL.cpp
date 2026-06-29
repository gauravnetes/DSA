#include <vector>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(); 
        int maxLen = 0; 

        unordered_map<int, int> mp; 

        int currSum = 0;  
        mp[0] = -1; 

        for(int i = 0; i < n; i++) {
            currSum += (nums[i] == 0 ? -1 : 1); 
            if(mp.find(currSum) != mp.end()) {
                maxLen = max(maxLen, i - mp[currSum]); 
            } else {
                mp[currSum] = i; 
            }
        }

        return maxLen; 
    }
};