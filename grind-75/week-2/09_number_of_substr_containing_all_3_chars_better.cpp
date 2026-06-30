#include <string>

using namespace std; 

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length(); 
        int res = 0; 

        for(int i = 0; i < n; i++) {
            int hash[3] = {0}; 
            for(int j = i; j < n; j++) {
                hash[s[j] - 'a']--;  

                if(hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
                    res += (n-j);
                    break;  
                }
            }
        }

        return res; 
    }
};