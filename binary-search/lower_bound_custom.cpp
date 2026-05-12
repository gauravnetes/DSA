// lower_bound(target): Finds the index of the first element that is greater 
// than or equal to (>=) the target 

// usage: [2, 4, 4, 4, 4, 6] array contains duplicate element. 

// The "Ceiling" Problem (Just Barely Enough)
// Often, the exact target doesn't exist in the array, but you need the smallest number that is greater than or equal to your target.

// Example: You have an array of available box sizes [10, 20, 30]. You need to pack an item of size 15.

// How it applies: Standard BS returns -1 because 15 isn't there. lower_bound(15) will correctly return the index of 20, which is the tightest possible fit.

#include <iostream>
#include <vector> 

using namespace std; 

int lower_bound(const vector<int> &nums, int target) {
    int l = 0; 
    int r = nums.size() - 1; 
    int ans = nums.size(); 

    while(l <= r) {
        int mid = l + (r - l) / 2; 

        if(nums[mid] >= target) {
            ans = mid; 
            r = mid - 1;  
        } else {
            l = mid + 1; 
        }
    }

    return ans; 
}