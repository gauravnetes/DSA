#include <string>

using namespace std; 

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length(); 
        long long l = 0; 
        for(char &ch : s) {
            if(islower(ch)) 
                l++;  
            else if(ch == '*') {
                if(l > 0) 
                    l--; 
            } else if(ch == '#') 
                l *= 2; 
            else 
                continue;  
        }

        if(k >= l) return '.'; 

        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '*') 
                l++; 
            else if(s[i] == '#') {
                l = l/2; 
                k = (k >= l) ? k - l : k; 
            } else if(s[i] == '%') {
                k = l - k - 1; 
            } else {
                l--; 
            }

            if(k == l) return s[i]; 
        }

        return '.'; 
    }
};