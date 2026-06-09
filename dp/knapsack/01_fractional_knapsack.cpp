#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size(); 
        vector<pair<int, int>> vec(n); 
        
        
        vector<int> valPerWt(n); 
        
        for(int i = 0; i < n; i++) {
            vec[i] = {val[i], wt[i]}; 
        }
        
        auto comp = [](pair<int, int> p1, pair<int, int> p2) {
            return (double) p1.first / p1.second > (double) p2.first / p2.second;     
        }; 
        
        sort(vec.begin(), vec.end(), comp); 
        
        double maxVal = 0; 
        for(int i = 0; i < n; i++) {
            if(capacity == 0) break; 
            
            if(capacity >= vec[i].second) {
                maxVal += vec[i].first; 
                capacity -= vec[i].second; 
            } else {
                double unitVal = (double) vec[i].first / vec[i].second; 
                maxVal += unitVal * capacity; 
                capacity = 0; 
                break; 
            }
        }
        return maxVal; 
    } 
};
