#include <vector>
using namespace std; 

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size(); 
        if(n % 2 != 0) return false; 

        vector<int> mp(k, 0); 

        for(int &num : arr) {
            int rem = (num % k + k) % k; 
            mp[rem]++; 
        }

        if(mp[0] % 2 != 0) return false; 

        for(int rem = 1; rem*2 <= k; rem++) {
            int counterPart = k - rem; 

            if(mp[counterPart] != mp[rem]) 
                return false;  
        } 

        return true; 
    }
};