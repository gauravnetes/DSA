#include <vector>
#include <algorithm>
#include <numeric>

using namespace std; 

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(); 
        int totalGas = accumulate(gas.begin(), gas.end(), 0); 
        int totalCost = accumulate(cost.begin(), cost.end(), 0); 

        if(totalGas < totalCost) return -1; 
        
        int total = 0, resIdx = 0; 
        for(int i = 0; i < n; i++) {
            total += gas[i]; 
            total -= cost[i]; 

            if(total < 0) {
                resIdx = i+1;
                total = 0;  
            }
        }
        return resIdx; 
    }
};