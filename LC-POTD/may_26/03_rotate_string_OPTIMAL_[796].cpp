#include <string>

using namespace std; 

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false; 

        string _s = s+s; 
        if(_s.find(goal) != string::npos)
            return true; 

        return false; 
    }
};