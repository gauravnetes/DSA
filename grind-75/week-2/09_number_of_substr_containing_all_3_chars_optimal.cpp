#include <string>

using namespace std; 

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int res = 0;

        int hash[3] = {0};
        int i = 0, j = i;

        while (j < n) {
            hash[s[j] - 'a']++;

            while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
                res += (n - j);
                hash[s[i] - 'a']--;
                i++;
            }

            j++;
        }

        return res;
    }
};