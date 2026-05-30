#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 



class Solution {
public:
    void dfs(int curr, int prev, unordered_map<int, vector<int>> &adj, vector<int> &res) {
        res.push_back(curr); 

        for(int ngbr : adj[curr]) {
            if(ngbr != prev) {
                dfs(ngbr, curr, adj, res); 
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj; 

        for(auto &pair : adjacentPairs) {
            int u = pair[0]; 
            int v = pair[1]; 

            adj[u].push_back(v); 
            adj[v].push_back(u); 
        }

        int startNode; 
        for(auto &it : adj) {
            if(it.second.size() == 1) {
                startNode = it.first; 
                break; 
            }
        }

        vector<int> res;
        int prev = INT_MAX;

        dfs(startNode, prev, adj, res); 

        return res; 
    }
};