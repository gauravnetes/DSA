#include <vector>

using namespace std; 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = INT_MIN;  
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int unit = j - i; 
                int area = min(height[i], height[j]) * unit; 
                maxArea = max(area, maxArea); 
            }
        }
        return maxArea; 
    }
};