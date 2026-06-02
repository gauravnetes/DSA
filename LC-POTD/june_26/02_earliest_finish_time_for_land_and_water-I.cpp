#include <vector>
using namespace std; 

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size(); 
        int n = waterStartTime.size(); 
        int minFinishTime = INT_MAX; 

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int finishLand = landStartTime[i] + landDuration[i]; 
                int startWater = max(finishLand, waterStartTime[j]); 
                int finishA = startWater + waterDuration[j];  

                minFinishTime = min(minFinishTime, finishA); 

                int finishWater = waterStartTime[j] + waterDuration[j]; 
                int startLand = max(finishWater, landStartTime[i]); 
                int finishB = startLand + landDuration[i]; 

                minFinishTime = min(minFinishTime, finishB); 
            }
        }
        return minFinishTime; 
    }
};