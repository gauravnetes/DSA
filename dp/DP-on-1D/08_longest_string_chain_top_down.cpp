#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
public:

    int dp[1001][1001]; 
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

    int LIS(vector<string> &words, int idx, int prev) {
        if(idx >= words.size()) 
            return 0; 

        if(dp[idx][prev+1] != -1) 
            return dp[idx][prev+1];

        int take = 0; 
        if(prev == -1 || checkPred(words[idx], words[prev])) 
            take = 1 + LIS(words, idx+1, idx); 

        int skip = LIS(words, idx+1, prev); 

        return dp[idx][prev+1] = max(take, skip); 
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size(); 
        if(n <= 1) return n;

        memset(dp, -1, sizeof(dp)); 

        sort(words.begin(), words.end(), comp); 

        return LIS(words, 0, -1); 
    }
};