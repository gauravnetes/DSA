#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 


class Solution {
public:
    int MOD = 1e9+7; 
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(); 
        sort(arr.begin(), arr.end()); 

        unordered_map<int, long long> mp; 

        mp[arr[0]] = 1; 
        for(int i = 1; i < n; i++) {
            int root = arr[i]; 
            mp[root] = 1; 
            for(int j = 0; j < i; j++) {
                int lc = arr[j]; 
                int rc = root / lc; 

                if(root % lc == 0 && mp.find(rc) != mp.end()) {
                    mp[root] += mp[lc] * mp[rc]; 
                }
            }
        }

        long long res = 0; 
        for(auto &it : mp) {
            res = (res + it.second) % MOD; 
        }

        return res; 
    }
};