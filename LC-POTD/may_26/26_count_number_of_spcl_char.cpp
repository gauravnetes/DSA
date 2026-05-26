#include <vector>
#include <string>
using namespace std; 


class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lowerSeen(26, false); 
        vector<bool> upperSeen(26, false); 
        int spcl = 0; 
        
        for(char &c : word) {
            if(islower(c)) 
                lowerSeen[c - 'a'] = true;
            else if(isupper(c)) 
                upperSeen[c - 'A'] = true;   
        }

        for(int i = 0; i < 26; i++) {
            if(lowerSeen[i] && upperSeen[i]) 
                spcl++; 
        }

        return spcl; 
    }
};