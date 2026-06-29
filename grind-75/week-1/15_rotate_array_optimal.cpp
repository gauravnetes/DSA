#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        k = k % n; 
        int _n = n-k; 
        reverse(nums.begin(), nums.begin() + _n); 
        reverse(nums.begin() + _n, nums.end()); 
        reverse(nums.begin(), nums.end()); 
    }
};