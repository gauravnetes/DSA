#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.length(); 
        if(n == 1)
            return s; 
        if(n == 2) {
            if(s[0] == s[1])
                return s; 
            else 
                return s.substr(0, 1); 
        } 
       
        vector<vector<int>> t(n, vector<int>(n, false)); 

        for(int i = 0; i < n; i++) {
            t[i][i] = true; 
        }


        int maxLen = 1, idx = 0; 
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i+len-1 < n; i++) {
                int j = i+len-1; 
                if(s[i] == s[j] && len == 2) {
                    t[i][j] = true;  
                    maxLen = 2; 
                    idx = i; 
                } else if(s[i] == s[j] && t[i+1][j-1]) {
                    t[i][j] = true; 
                    if(j-i+1 > maxLen) {
                        maxLen = j-i+1; 
                        idx = i; 
                    }
                } else {
                    t[i][j] = false; 
                }
            }
        }
        return s.substr(idx, maxLen); 
    }
};