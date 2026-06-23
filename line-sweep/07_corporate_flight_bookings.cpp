#include <vector>
#include <map>

using namespace std;  

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> events(n, 0); 

        for(auto &booking : bookings) {
            events[booking[0] - 1] += booking[2]; 
            if(booking[1] < n)
                events[booking[1]] -= booking[2]; 
        } 

        int cumSum = 0; 
        vector<int> res; 

        for(int i = 0; i < n; i++) {
            cumSum += events[i]; 
            res.push_back(cumSum); 
        }

        return res; 
    }
};