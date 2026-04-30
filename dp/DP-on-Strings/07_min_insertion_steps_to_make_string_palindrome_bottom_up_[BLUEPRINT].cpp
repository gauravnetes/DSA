#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length(); 
        if(n == 1) return 0;    
        if(n == 2) {
            if(s[0] == s[1]) 
                return 0; 
            else 
                return 1; 
        }

        vector<vector<int>> t(n, vector<int>(n)); 
        for(int i = 0; i < n; i++) 
            t[i][i] = 0; 

        for(int len = 2; len <= n; len++) {
            for(int i = 0; i+len-1 < n; i++) {
                int j = i + len - 1; 
                if(s[i] == s[j]) 
                    t[i][j] = t[i+1][j-1]; 
                else 
                    t[i][j] = 1 + min(t[i][j-1], t[i+1][j]); 
            }
        }
        return t[0][n-1]; 
    }
};