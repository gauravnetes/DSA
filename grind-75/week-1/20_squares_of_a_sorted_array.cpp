#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> res(n); 
        
        int i = 0; 
        int j = n-1; 
        int k = n-1; 
        while(i <= j && k >= 0) {
            int sq_i = nums[i] * nums[i]; 
            int sq_j = nums[j] * nums[j]; 
            if(sq_i >= sq_j) {
                res[k] = sq_i; 
                i++; 
            } else {
                res[k] = sq_j; 
                j--; 
            }
            
            k--; 
        }

        return res; 
    }
};