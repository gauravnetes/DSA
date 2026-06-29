#include <string>

using namespace std; 

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length(); 

        int l = 0; 
        int r = n-1;
    
        while(l < r) {
            if(!isalnum(s[l]) || isspace(s[l])) 
                l++;
            else if(!isalnum(s[r]) || isspace(s[r])) 
                r--; 
            else {
                if(tolower(s[l]) != tolower(s[r])) 
                    return false; 
                l++;
                r--; 
            }
        }
        return true; 
    }
};