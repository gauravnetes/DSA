#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(2051, 0); 

        for(auto &log : logs) {
            int birth = log[0]; 
            int death = log[1]; 

            diff[birth] += 1; 
            diff[death] -= 1; 
        }

        int maxPop = 0; 
        int currPop = 0; 
        int minYear = 2050; 

        for(int year = 1950; year < 2051; year++) {
            currPop += diff[year]; 
            if(currPop > maxPop) {
                maxPop = currPop;  
                minYear = year; 
            }
        }

        return minYear; 
    }
};