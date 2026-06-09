#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(); 
        int countLess = 0, countEqual = 0;

        for(int x = 0; x < n; x++) {
            if(nums[x] < pivot) 
                countLess++; 
            else if(nums[x] == pivot) 
                countEqual++; 
        }

        int i = 0; 
        int j = countLess; 
        int k = countLess + countEqual; 

        vector<int> res(n); 
        for(int y = 0; y < n; y++) {
            if(nums[y] < pivot) {
                res[i] = nums[y]; 
                i++; 
            } else if(nums[y] > pivot) {
                res[k] = nums[y]; 
                k++; 
            } else {
                res[j] = pivot;
                j++;  
            }
        }

        return res; 
    }
};