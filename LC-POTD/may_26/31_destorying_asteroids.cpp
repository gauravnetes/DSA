#include <vector>
#include <algorithm>
using namespace std; 


class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end()); 

        int n = asteroids.size(); 

        long long currMass = mass;

        for(int i = 0; i < n; i++) {
            if(currMass >= asteroids[i]) {
                currMass += asteroids[i]; 
            } else {
                return false; 
            }
        }

        return true; 
    }
};