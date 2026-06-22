#include <vector>
#include <map>

using namespace std; 

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size(); 
        map<int, int> events;
        
        for(int i = 0; i < n; i++) {
            events[start[i]]++; 
            events[end[i]]--; 
        }
        
        int maxOverlaps = 0; 
        int overlaps = 0; 
        
        for(auto &e : events) {
            overlaps += e.second; 
            maxOverlaps = max(overlaps, maxOverlaps); 
        }
        
        return maxOverlaps; 
    }
};
