#include <string>

using namespace std; 

class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int cnt = 0; cnt <= s.length(); cnt++) {
            rotate(s.begin(), s.begin()+1, s.end()); 
            if(s == goal)
                return true; 
        }
        return false; 
    }
};