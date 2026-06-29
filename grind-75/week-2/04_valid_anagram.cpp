#include <string>
#include <vector>

using namespace std; 


class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0); 

        // anagrams must be of exact same length 
        if(s.length() != t.length())
            return false; 
            
        for(char &ch : s) {
            freq[ch - 'a']++; 
        }

        for(char &ch : t) {
            freq[ch - 'a']--; 
        }

        for(int f : freq) {
            if(f != 0) 
                return false; 
        }

        return true; 
    }
};