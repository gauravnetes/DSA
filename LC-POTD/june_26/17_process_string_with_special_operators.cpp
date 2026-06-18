#include <string>

using namespace std; 


class Solution {
public:
    string processStr(string s) {
        string res = ""; 
        for(char &ch : s) {
            if(islower(ch)) 
                res += ch; 
            else if(res.size() > 0 && ch == '*') {
                res.pop_back(); 
            } else if(ch == '#') {
                string temp = res; 
                res.append(temp); 
            } else {
                reverse(res.begin(), res.end()); 
            }
        }
        return res; 
    }
};