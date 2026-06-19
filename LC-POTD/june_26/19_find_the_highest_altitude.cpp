#include <vector>

using namespace std; 

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size(); 

        vector<int> altitude;
        
        int highest = max(0, gain[0]); 

        altitude.push_back(0);  
        altitude.push_back(gain[0]); 
        
        for(int i = 1; i < n; i++) {
            altitude.push_back(altitude.back() + gain[i]); 
            highest = max(highest, altitude.back()); 
        }

        return highest; 
    }
};