#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        int cand1 = NULL; 
        int cnt1 = 0; 
        int cand2 = NULL; 
        int cnt2 = 0; 
        for(int i = 0; i < n; i++) {
            if(nums[i] == cand1) 
                cnt1++; 
            else if(nums[i] == cand2)
                cnt2++; 
            else if(cnt1 == 0) {
                cand1 = nums[i]; 
                cnt1++; 
            }
            else if(cnt2 == 0) {
                cand2 = nums[i]; 
                cnt2++; 
            } else {
                cnt1--; 
                cnt2--; 
            }
        }

        int verificationCnt1 = 0; 
        int verificationCnt2 = 0; 
        for(int i = 0; i < n; i++) {
            if(nums[i] == cand1) 
                verificationCnt1++;
            else if (nums[i] == cand2)
                verificationCnt2++;  
        }

        if(verificationCnt1 > (n/3) && verificationCnt2 > (n/3)) 
            return {cand1, cand2}; 
        else if(verificationCnt1 > (n/3)) 
            return {cand1}; 
        else if(verificationCnt2 > (n/3))
            return {cand2}; 
        else 
            return {};  
    }
};