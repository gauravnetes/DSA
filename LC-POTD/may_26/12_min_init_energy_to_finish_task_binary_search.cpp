#include <vector>
#include <string>
#include <algorithm>
using namespace std; 



class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b) {
        int buffA = a[1] - a[0]; 
        int buffB = b[1] - b[0]; 

        return buffA > buffB; 
    }

    bool isValid(int initEnergy, vector<vector<int>> &tasks) {
        int currEnergy = initEnergy; 
        for(auto &task : tasks) {
            if(currEnergy < task[1]) 
                return false; 
            currEnergy -= task[0]; 
        }

        return true; 
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), comp); 

        int l = 1; 
        int r = 1e9; 
        int ans = -1; 

        while(l <= r) {
            int mid = l + (r - l) / 2; 
            if(isValid(mid, tasks)) {
                ans = mid; 
                r = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }
        
        return ans; 
    }
};