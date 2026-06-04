#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int getOneWay(vector<int>& fS, vector<int>& fD, vector<int>& sS, vector<int>& sD) {
        int m = fS.size();
        int n = sS.size(); 

        vector<pair<int, int>> secondRides(n); 
        for(int i = 0; i < n; i++) {
            secondRides[i] = {sS[i], sD[i]}; 
        }

        sort(secondRides.begin(), secondRides.end()); 

        vector<int> prefixMinDuration(n); 
        vector<int> suffixMinSum(n);

        prefixMinDuration[0] = secondRides[0].second; 
        for(int i = 1; i < n; i++) {
            prefixMinDuration[i] = min(prefixMinDuration[i-1], secondRides[i].second); 
        } 

        suffixMinSum[n-1] = secondRides[n-1].first + secondRides[n-1].second;
        for(int i = n-2; i >= 0; i--) {
            suffixMinSum[i] = min(suffixMinSum[i+1], secondRides[i].first + secondRides[i].second); 
        }

        int globalMinFinish = INT_MAX; 
        for(int i = 0; i < m; i++) {
            int firstEnd = fS[i] + fD[i]; 

            int l = 0, r = n; 
            while(l < r) {
                int mid = l + (r - l) / 2; 
                if(secondRides[mid].first <= firstEnd) 
                    l = mid + 1; 
                else 
                    r = mid; 
            }
            int idx = l; 

            int currMinFinish = INT_MAX; 
            if(idx > 0) 
                currMinFinish = min(currMinFinish, firstEnd + prefixMinDuration[idx-1]);

            if(idx < n)
                currMinFinish = min(currMinFinish, suffixMinSum[idx]); 

            globalMinFinish = min(currMinFinish, globalMinFinish);  
        }

        return globalMinFinish; 
    }

    int earliestFinishTime(vector<int>& lS, vector<int>& lD, vector<int>& wS, vector<int>& wD) {
        int landFirst = getOneWay(lS, lD, wS, wD); 
        int waterFirst = getOneWay(wS, wD, lS, lD); 

        return min(landFirst, waterFirst); 
    }
};