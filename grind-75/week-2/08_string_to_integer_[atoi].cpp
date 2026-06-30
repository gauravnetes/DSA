#include <string>

using namespace std; 

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length(); 
        int i = 0; 

        int max = INT_MAX / 10; 
        int min = INT_MIN / 10; 

        // ignoring whitespaces 
        while(i < n && isspace(s[i])) 
            i++; 

        // check if no more chars left after the whitespaces 
        if(i == n) 
            return 0; 

        // check for negative 
        bool neg = false; 
        if(s[i] == '-') {
            neg = true; 
            i++; 
        } else if(s[i] == '+') { 
            i++; 
        }
        // check for digits right after the sign if no digit then invalid input return 0 
        if(!isdigit(s[i]))  
            return 0; 

        // checking if no chars left to check 
        if(i == n) 
            return 0; 

        // skipping leading zeros 
        if(i < n && s[i] == '0')
            i++; 
        
        if(i == n) 
            return 0; 

        // extract the digit 
        int val = 0; 
        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0'; 

            // handling overflow & underflow  
            if(val > max) 
                return INT_MAX; 
            else if(val == max && digit > 7)
                return INT_MAX; 
            else if(val < min) 
                return INT_MIN; 
            else if(val == min && digit > 8)
                return INT_MIN;  

            if(neg) 
                val = val * 10 + (-digit); 
            else 
                val = val * 10 + digit; 

            i++; 
        }

        return val; 
    }
};