#include <iostream>

using namespace std; 

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double totalHour = (double) hour + (double) minutes / 60; // 12 + 0.5 = 12.5
        double hourHandAngle = 30 * totalHour; // 375 
        double minHandAngle = 6 * minutes; // 180 

        double res = abs(hourHandAngle - minHandAngle); // 195 

        return (res > 180) ? (360 - res) : res; // 360 - 195 = 165 
    }
};