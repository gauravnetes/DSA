#include <vector>
#include <map>

using namespace std; 

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2); 
        map<int, int> mp; 

        for(auto &match : matches) {
            int winner = match[0]; 
            int loser = match[1]; 

            if(mp.find(winner) == mp.end()) 
                mp[winner] = 0; 

            mp[loser]++; 
        }

        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second == 0) 
                res[0].push_back(it->first); 
            else if(it->second == 1)
                res[1].push_back(it->first); 
        }

        return res; 
    }
};