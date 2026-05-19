#include <vector>
#include <queue>
#include <unordered_map>

using namespace std; 


class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(); 
        unordered_map<int, vector<int>> mp; 
        vector<bool> vis(n, false); 
        
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i); 
        }

        queue<int> q; 
        q.push(0); 
        vis[0] = true; 
        int steps = 0; 

        while(!q.empty()) {
            int size = q.size(); 
            while(size--) {
                int curr = q.front(); 
                q.pop(); 

                int left = curr - 1; 
                int right = curr + 1; 

                if(curr == n-1) 
                    return steps; 

                if(left >= 0 && !vis[left]) {
                    q.push(left); 
                    vis[left] = true; 
                }

                if(right < n && !vis[right]) {
                    q.push(right); 
                    vis[right] = true; 
                } 

                for(int &idx : mp[arr[curr]]) {
                    if(!vis[idx]) {
                        q.push(idx); 
                        vis[idx] = true; 
                    }
                }

                mp.erase(arr[curr]); 
            }
            steps++; 
        }

        return -1; 
    }
};