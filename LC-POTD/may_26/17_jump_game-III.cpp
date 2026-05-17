#include <vector>

using namespace std; 

class Solution {
public:
    int n; 
    bool dfs(vector<int> &arr, int curr, vector<bool> &vis) {
        if(curr < 0 || curr >= n) 
            return false; 
        
        if(vis[curr]) 
            return false; 
        
        if(arr[curr] == 0) 
            return true; 

        vis[curr] = true; 
        
        return dfs(arr, curr + arr[curr], vis) || dfs(arr, curr - arr[curr], vis); 
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size(); 

        vector<bool> vis(n, false); 

        return dfs(arr, start, vis); 
    }
};