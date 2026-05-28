#include <vector>
#include <unordered_map>
using namespace std; 

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(); 

        unordered_map<int, int> freq;
        int cnt = 0; 
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++; 
        }

        for(int i = 0; i < n; i++) {
            int N = freq[nums[i]] - 1; 
            int pairCnt = (N * (N + 1)) / 2; 
            cnt += pairCnt; 
            freq.erase(nums[i]); 
        }

        return cnt;
    }
};