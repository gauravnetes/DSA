#include <string>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.length();
        int n = s.length();

        if (m > n)
            return "";

        unordered_map<char, int> mp;

        for (char& ch : t)
            mp[ch]++;

        int reqCnt = m;
        int i = 0, j = 0;

        int minWindowSize = INT_MAX;
        int start_i = 0;

        while (j < n) {
            char ch = s[j];

            if (mp[ch] > 0) {
                reqCnt--;
            }
            mp[ch]--;

            while (reqCnt == 0) {
                int currWindowSize = j - i + 1;
                if (currWindowSize < minWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    reqCnt++;

                i++;
            }
            j++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};