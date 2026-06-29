#include <vector>
#include <algorithm>

using namespace std; 


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(); 
        auto comp = [&](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1]; 
        }; 

        sort(intervals.begin(), intervals.end(), comp);

        
        int removals = 0;
        int lastEnd = intervals[0][1];

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < lastEnd) {
                removals++;
            } else {
                lastEnd = intervals[i][1]; 
            }
        }

        return removals; 
    }
};