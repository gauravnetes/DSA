#include <string>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 1)
            return 1;

        unordered_map<char, int> mp; 
        int maxLen = 0;
        int i = 0, j = 0; 

        while(j < n) {
            mp[s[j]]++;  
            if(mp.size() == (j-i+1)) {
                int len = j-i+1; 
                maxLen = max(len, maxLen); 
                j++; 
            } else {
                while(mp.size() < (j-i+1)) {
                    mp[s[i]]--; 
                    if(mp[s[i]] == 0) 
                        mp.erase(s[i]); 
                    i++;   
                }
                j++; 
            }
        }

        return maxLen;
    }
};