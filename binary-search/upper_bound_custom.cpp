// upper_bound(target): Finds the index of the first element that is strictly greater than ($>$) the target.

#include <iostream>
#include <vector> 

using namespace std; 

int upper_bound(const vector<int> &nums, int target) {
    int l = 0; 
    int r = nums.size() - 1; 
    int ans = nums.size(); 

    while(l <= r) {
        int mid = l + (r - l) / 2; 
        if(nums[mid] > target) {
            ans = mid; 
            r = mid - 1;   
        } else {
            l = mid + 1; 
        }
    }

    return ans; 
}