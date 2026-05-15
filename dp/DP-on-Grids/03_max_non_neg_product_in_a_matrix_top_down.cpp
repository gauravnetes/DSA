#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 

class Solution {
public:
    int n, m;
    typedef long long ll;
    int MOD = 1e9 + 7;
    vector<vector<pair<ll, ll>>> dp;

    pair<ll, ll> solve(vector<vector<int>>& grid, int i, int j) {
        if (i == m - 1 && j == n - 1)
            return {grid[i][j], grid[i][j]};

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if (dp[i][j] != make_pair(LLONG_MAX, LLONG_MIN))
            return dp[i][j];

        if (i + 1 < m) {
            auto [downMax, downMin] = solve(grid, i + 1, j);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        if (j + 1 < n) {
            auto [rightMax, rightMin] = solve(grid, i, j + 1);
            maxVal =
                max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal =
                min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return dp[i][j] = {minVal, maxVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp = vector<vector<pair<ll, ll>>>(
            m, vector<pair<ll, ll>>(n, {LLONG_MAX, LLONG_MIN}));

        auto [minProd, maxProd] = solve(grid, 0, 0);
        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};