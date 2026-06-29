#include <vector>

using namespace std; 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                cnt0++;
            else if (nums[i] == 1)
                cnt1++;
        }

        int cnt2 = n - (cnt0 + cnt1);
        int i = 0;

        while (cnt0--)
            nums[i++] = 0;
        while (cnt1--)
            nums[i++] = 1;
        while (cnt2--)
            nums[i++] = 2;
    }
};