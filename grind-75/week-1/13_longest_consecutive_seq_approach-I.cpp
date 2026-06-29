#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 0 || n == 1) return n;  
        sort(nums.begin(), nums.end()); 
        int seqLen = 1; 
        int maxSeqLen = 1; 
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) continue; 
            if(nums[i] == nums[i-1]+1) {
                seqLen++; 
            } else {
                maxSeqLen = max(seqLen, maxSeqLen); 
                seqLen = 1; 
            }
            maxSeqLen = max(seqLen, maxSeqLen); 
        } 
        return maxSeqLen; 
    }
};