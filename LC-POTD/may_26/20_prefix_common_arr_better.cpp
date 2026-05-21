#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(); 
        vector<int> res(n); 
        vector<bool> isPresentA(n+1, false); 
        vector<bool> isPresentB(n+1, false); 

        for(int i = 0; i < n; i++) {
            isPresentA[A[i]] = true; 
            isPresentB[B[i]] = true; 
            int cnt = 0; 
            for(int i = 1; i <= n; i++) {
                if(isPresentA[i] && isPresentB[i]) 
                    cnt++; 
            }
            res[i] = cnt; 
        }
        return res; 
    }
};