#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
public:
    static bool comp(string &word1, string &word2) {
        return word1.length() < word2.length(); 
    }

    bool checkPred(string &curr, string &prev) {
        int M = prev.length(); 
        int N = curr.length(); 

        if(M >= N || N - M != 1) 
            return false; 

        int i = 0, j = 0; 
        while(i < M && j < N) {
            if(prev[i] == curr[j]) 
                i++; 
            j++; 
        }

        return i == M; 
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size(); 
        if(n <= 1) return n;

        sort(words.begin(), words.end(), comp); 
        vector<int> t(n, 1); 

        int maxi = 1; 
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(checkPred(words[i], words[j])) {
                    t[i] = max(t[j]+1, t[i]); 
                    maxi = max(maxi, t[i]); 
                }
            }
        }
        return maxi; 
    }
};