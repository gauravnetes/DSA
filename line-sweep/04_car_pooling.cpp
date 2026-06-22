#include <vector>
#include <map>

using namespace std; 


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> events;

        for(auto &trip : trips) {
            events[trip[1]] += trip[0]; 
            events[trip[2]] -= trip[0]; 
        } 

        int passCnt = 0; 
        for(auto &e : events) {
            passCnt += e.second; 
            if(passCnt > capacity) 
                return false; 
        }

        return true; 
    }
};