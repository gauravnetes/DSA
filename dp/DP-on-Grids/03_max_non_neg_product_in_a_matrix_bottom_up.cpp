#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<ll, ll>>> dp(
            m, vector<pair<ll, ll>>(n, {LLONG_MAX, LLONG_MIN}));

        dp[0][0] = {grid[0][0], grid[0][0]};

        for (int j = 1; j < n; j++) {
            dp[0][j].first = dp[0][j - 1].first * grid[0][j];
            dp[0][j].second = dp[0][j - 1].second * grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            dp[i][0].first = dp[i - 1][0].first * grid[i][0];
            dp[i][0].second = dp[i - 1][0].second * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                ll topMax = dp[i - 1][j].first;
                ll topMin = dp[i - 1][j].second;

                ll leftMax = dp[i][j - 1].first;
                ll leftMin = dp[i][j - 1].second;

                dp[i][j].first =
                    max({topMax * grid[i][j], topMin * grid[i][j],
                         leftMax * grid[i][j], leftMin * grid[i][j]});
                dp[i][j].second =
                    min({topMax * grid[i][j], topMin * grid[i][j],
                         leftMax * grid[i][j], leftMin * grid[i][j]});
            }
        }

        auto [maxProd, minProd] = dp[m - 1][n - 1];

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};