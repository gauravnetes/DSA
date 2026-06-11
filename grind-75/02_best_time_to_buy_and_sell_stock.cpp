#include <vector>
using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        int maxProfit = 0; 
        int bestDayToBuy = INT_MAX; 

        for(int i = 0; i < n; i++) {
            bestDayToBuy = min(bestDayToBuy, prices[i]); 
            maxProfit = max(maxProfit, prices[i] - bestDayToBuy); 
        }

        return maxProfit; 
    }
};