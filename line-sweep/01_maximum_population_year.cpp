#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int, int>> events; 

        for(auto &log : logs) {
            events.push_back({log[0], +1}); 
            events.push_back({log[1], -1}); 
        }

        sort(events.begin(), events.end()); 

        int maxPop = 0; 
        int currPop = 0; 
        int minYear = 2050; 

        for(auto &e : events) {
            currPop += e.second; 
            if(currPop > maxPop) {
                maxPop = currPop; 
                minYear = e.first; 
            }
        }

        return minYear; 
    }
};