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

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), comp); 

        int ans = 0; 
        int currEnergy = 0; 

        for(auto &task : tasks) {
            int actual = task[0]; 
            int minReq = task[1]; 
            if(currEnergy < minReq) {
                int deficit = minReq - currEnergy; 
                ans += deficit; 
                currEnergy += deficit; 
            }
            currEnergy -= actual; 
        }
        
        return ans; 
    }
};