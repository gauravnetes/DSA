#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size(); 
        sort(cost.begin(), cost.end()); 

        int totalCost = 0; 
        int cnt = 0; 
    
        for(int i = n-1; i >= 0; i--) {
            if(cnt == 2) {
                cnt = 0; 
                continue; 
            }
            totalCost += cost[i]; 
            cnt++; 
        }
        return totalCost; 
    }
};