#include <vector>

using namespace std; 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = INT_MIN;  
        int i = 0; 
        int j = n-1; 

        while(i < j) {
            int width = j - i; 
            int area = width * min(height[i], height[j]); 
            maxArea = max(area, maxArea); 

            if(height[i] < height[j]) 
                i++; 
            else if(height[i] > height[j]) 
                j--; 
            else {
                i++;
                j--; 
            }
        }
        
        return maxArea; 
    }
};