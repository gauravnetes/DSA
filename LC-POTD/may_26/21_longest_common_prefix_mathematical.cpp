#include <vector>
#include <unordered_set>

using namespace std; 

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> hash; 
        int m = arr1.size(); 
        int n = arr2.size(); 

        for(int i = 0; i < m; i++) {
            int temp = arr1[i]; 
            while(temp > 0) {
                hash.insert(temp); 
                temp /= 10; 
            }
        }

        int LCP = 0; 
        for(int j = 0; j < n; j++) {
            int temp = arr2[j]; 
            while(temp > 0) {
                if(hash.find(temp) != hash.end()) {
                    int prefLen = log10(temp) + 1; 
                    LCP = max(prefLen, LCP); 
                }
                temp /= 10; 
            }     
        }

        return LCP; 
    }
};