#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    bool KMP(string &pat, string &txt) {
        // code here
        int n = txt.length(); 
        int m = pat.length(); 
        
        // LPS[i] = the longest prefix of pat[0..i] 
        //          which is also a suffix of pat[0..i]
        if(m > n) return false; 

        vector<int> LPS(m, 0); 
        LPS[0] = 0; 
        int length = 0; 
        int i = 1; 
        
        while(i < m) {
            if(pat[i] == pat[length]) {
                length++;
                LPS[i] = length;
                i++;
            } else {
                if(length > 0) {
                    length = LPS[length - 1]; 
                } else {
                    LPS[i] = 0; 
                    i++; 
                }
            }
        }
        
        i = 0;
        int j = 0; 
        vector<int> res; 
        
        while(i < n) {
            if(txt[i] == pat[j]) {
                i++; 
                j++; 
            } 
            if(j == m) {
                return true; 
            } else if(txt[i] != pat[j]) {
                if(j > 0)
                    j = LPS[j-1]; 
                else 
                    i++; 
            }
        }
        return false; 
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0; 

        for(string &pat : patterns) {
            cnt += KMP(pat, word);   
        }

        return cnt; 
    }
};