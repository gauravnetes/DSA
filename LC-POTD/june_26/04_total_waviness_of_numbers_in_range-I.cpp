#include <string>

using namespace std; 

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num1 % 100 == num1 && num2 % 100 == num2) 
            return 0; 

        int waviness = 0; 
        for(int i = num1; i <= num2; i++) {
            string s = to_string(i); 
            for(int i = 1; i < s.length() - 1; i++) {
                if(s[i-1] > s[i] && s[i] < s[i+1])
                    waviness++; 
                else if(s[i-1] < s[i] && s[i] > s[i+1])
                    waviness++; 
            }
        }

        return waviness; 
    }
};