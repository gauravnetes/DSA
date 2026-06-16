#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std; 


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 0 || n == 1) return n;   
        unordered_set<int> st(nums.begin(), nums.end()); 
        int maxSeqLen = 1; 

        for(auto &num : st) {
            // start finding the seq if num is the first number 
            // checking if num - 1 exist in the set or not 
            if(st.find(num - 1) == st.end()) {
                int currNum = num; 
                int currSeqLen = 1; 

                while(st.find(currNum + 1) != st.end()) {
                    currNum++; 
                    currSeqLen++; 
                } 
                maxSeqLen = max(maxSeqLen, currSeqLen); 
            }   
        } 
        return maxSeqLen; 
    }
};