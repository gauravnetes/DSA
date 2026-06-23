#include <vector>
#include <map>

using namespace std;  

class Solution {
public:
    typedef long long ll; 

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, ll> events; 

        for(auto &segment : segments) {
            events[segment[0]] += segment[2]; 
            events[segment[1]] -= segment[2];  
        }

        vector<vector<ll>> res; 
        auto it = events.begin(); 
        int start = it->first; 
        ll cumSum = it->second; 
        it++; 

        while(it != events.end()) {
            if(cumSum > 0) 
                res.push_back({start, it->first, cumSum}); 
            start = it->first; 
            cumSum += it->second; 
            it++;  
        }

        return res; 
    }   
};