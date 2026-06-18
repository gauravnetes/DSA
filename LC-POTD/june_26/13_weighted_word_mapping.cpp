#include <vector>
#include <string>

using namespace std; 

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s = ""; 
        for(string &word : words) {
            int res = 0; 
            for(char &ch : word) {
                res += weights[ch - 'a']; 
            }
            res = res % 26; 
            char mappedChar = 'z' - res;  
            s += mappedChar; 
        }
        return s; 
    }
};