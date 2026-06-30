#include <string>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0; 
        unordered_map<char, int> mp; 

        for(char &ch : s) {
            mp[ch]++;  
        }

        bool containsOdd = false; 
        for(auto &it : mp) {
            if(it.second % 2 == 0) {
                res += it.second; 
            } else {
                res += it.second - 1;
                containsOdd = true; 
            }
        }

        return containsOdd ? res + 1 : res;   
    }
};