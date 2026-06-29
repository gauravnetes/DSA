#include <string>
#include <vector>

using namespace std; 

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        int n = txt.length(); 
        int m = pat.length(); 
        
        // LPS[i] = the longest prefix of pat[0..i] 
        //          which is also a suffix of pat[0..i]
        
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
                res.push_back(i-m); 
                j = LPS[j-1]; 
            } else if(txt[i] != pat[j]) {
                if(j > 0)
                    j = LPS[j-1]; 
                else 
                    i++; 
            }
        }
        return res; 
    }
};