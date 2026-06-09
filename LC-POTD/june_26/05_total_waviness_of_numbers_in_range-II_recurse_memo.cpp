#include <vector>
#include <string>
using namespace std; 

class Solution {
public:
    typedef long long ll;
    int n;
    string s;

    ll dpTotalNumbers[16][10][10];
    ll dpTotalWaviness[16][10][10];

    pair<ll, ll> solve(int curr, int prevPrev, int prev,
                       bool isLimitedWithActualNumber, bool isLeadingZero) {
        if (curr == n)
            return {1, 0}; // no more score can be generated, num finished,found
                           // 1 last number

        // both needs to be false to memoize
        if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 &&
            prev >= 0) {
            if (dpTotalNumbers[curr][prevPrev][prev] != -1 &&
                dpTotalWaviness[curr][prevPrev][prev] != -1) {
                return {dpTotalNumbers[curr][prevPrev][prev],
                        dpTotalWaviness[curr][prevPrev][prev]};
            }
        }

        ll totalNumbers = 0;
        ll totalWaviScore = 0;

        int limitDigit = isLimitedWithActualNumber ? (s[curr] - '0') : 9;

        for (int digit = 0; digit <= limitDigit; digit++) {
            bool newIsLeadingZero = isLeadingZero && (digit == 0);

            int newPrevPrev = prev;
            int newPrev = newIsLeadingZero ? -1 : digit;

            auto [remainingTotalNumbers, remainingTotalWaviScore] =
                solve(curr + 1, newPrevPrev, newPrev,
                      (isLimitedWithActualNumber && (digit == limitDigit)),
                      newIsLeadingZero);

            if (!newIsLeadingZero && prevPrev >= 0 && prev >= 0) {
                bool isPeak = prevPrev < prev && prev > digit;
                bool isValley = prevPrev > prev && prev < digit;

                if (isPeak || isValley)
                    totalWaviScore += remainingTotalNumbers;
            }
            totalNumbers += remainingTotalNumbers;
            totalWaviScore += remainingTotalWaviScore;
        }

        if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 &&
            prev >= 0) {
            dpTotalNumbers[curr][prevPrev][prev] = totalNumbers; 
            dpTotalWaviness[curr][prevPrev][prev] = totalWaviScore; 
        }

        return {totalNumbers, totalWaviScore};
    }

    ll func(ll num) {
        if (num < 100)
            return 0;
        
        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers)); 
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness)); 

        s = to_string(num);
        n = s.length();

        auto [totalNumbers, totalWaviScore] = solve(0, -1, -1, true, true);

        return totalWaviScore;
    }

    long long totalWaviness(long long num1, long long num2) {
        if (num1 % 100 == num1 && num2 % 100 == num2)
            return 0;

        return func(num2) - func(num1 - 1);
    }
};