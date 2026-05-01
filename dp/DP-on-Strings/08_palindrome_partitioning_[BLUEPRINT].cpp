#include <vector>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int n; 
    vector<vector<string>> res; 
    vector<vector<bool>> t;

    void fill(string &s) {
        t = vector<vector<bool>>(n, vector<bool>(n, false)); 
        for(int i = 0; i < n; i++) 
            t[i][i] = true;
        
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i+len-1 < n; i++) {
                int j = i + len - 1; 
                if(s[i] == s[j]) {
                    if(len == 2)
                        t[i][j] = true; 
                    else 
                        t[i][j] = t[i+1][j-1]; 
                }
            }
        }
    } 

    void partition(string &s, int i, vector<string> &part) {
        if(i == s.length()) {
            res.push_back(part); 
            return; 
        } 

        for(int j = i; j < s.length(); j++) {
            if(t[i][j]) {
                part.push_back(s.substr(i, j-i+1)); 
                partition(s, j+1, part); 
                part.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length(); 
        fill(s); 

        vector<string> part; 
        partition(s, 0, part); 
        return res; 
    }
};