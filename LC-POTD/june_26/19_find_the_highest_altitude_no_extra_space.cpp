#include <vector>

using namespace std; 

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size(); 
        
        int currAlt = 0; 
        int highestAlt = 0; 
        
        for(int i = 0; i < n; i++) {
            currAlt += gain[i];  
            highestAlt = max(currAlt, highestAlt); 
        }

        return highestAlt; 
    }
};