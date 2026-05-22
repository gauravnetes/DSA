#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std; 

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size(); 
        unordered_map<int, int> mp; 

        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        unordered_set<int> st;  
        for(auto &it : mp) { 
            st.insert(it.second); 
        }   

        return st.size() == mp.size(); 
    }
};