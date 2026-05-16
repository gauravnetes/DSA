#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> t(m, vector<int>(n));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    if (dungeon[i][j] > 0)
                        t[i][j] = 1;
                    else
                        t[i][j] = abs(dungeon[i][j]) + 1;
                } else {
                    int right = (j + 1 >= n) ? 1e9 : t[i][j + 1];
                    int down = (i + 1 >= m) ? 1e9 : t[i + 1][j];

                    int res = min(right, down) - dungeon[i][j];
                    t[i][j] = res > 0 ? res : 1;
                }
            }
        }

        return t[0][0];
    }
};