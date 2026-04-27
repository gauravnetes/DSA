#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 


class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> t(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = i + j;
                else if (s1[i - 1] == s2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = 1 + min(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        string scs = "";
        while (m > 0 && n > 0) {
            if (s1[m - 1] == s2[n - 1]) {
                scs.push_back(s1[m - 1]);
                m--, n--;
            } else {
                if (t[m - 1][n] < t[m][n - 1]) {
                    scs.push_back(s1[m - 1]);
                    m--;
                } else {
                    scs.push_back(s2[n - 1]);
                    n--;
                }
            }
        }

        while (m > 0) {
            scs.push_back(s1[m - 1]);
            m--;
        }

        while (n > 0) {
            scs.push_back(s2[n - 1]);
            n--;
        }

        reverse(scs.begin(), scs.end());
        return scs;
    }
};