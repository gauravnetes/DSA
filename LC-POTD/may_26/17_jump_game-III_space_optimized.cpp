#include <vector>

using namespace std; 


class Solution {
public:
    int n; 
    bool dfs(vector<int> &arr, int curr) {
        if(curr < 0 || curr >= n || arr[curr] < 0) 
            return false;  
        
        if(arr[curr] == 0) 
            return true; 

        arr[curr] = -(arr[curr]); 

        return dfs(arr, curr + arr[curr]) || dfs(arr, curr - arr[curr]); 
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size(); 

        return dfs(arr, start); 
    }
};