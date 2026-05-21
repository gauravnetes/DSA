#include <vector>
#include <unordered_set>
#include <string>

using namespace std; 

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> hash; 
        int m = arr1.size(); 
        int n = arr2.size(); 

        for(int i = 0; i < m; i++) {
            string s = to_string(arr1[i]); 
            for(int len = 1; len <= s.length(); len++) {
                string pref = s.substr(0, len); 
                hash.insert(pref); 
            }
        }

        int LCP = 0; 
        for(int j = 0; j < n; j++) {
            string s = to_string(arr2[j]); 
            for(int len = 1; len <= s.length(); len++) {
                string pref = s.substr(0, len); 
                if(hash.find(pref) != hash.end()) {
                    int prefLen = pref.length(); 
                    LCP = max(prefLen, LCP); 
                }
            }        
        }

        return LCP; 
    }
};