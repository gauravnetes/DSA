#include <vector>
#include <unordered_set>
using namespace std; 

class Solution {
  public:
    bool canPair(vector<int> &arr, int k) {
        // Code here.
        int n = arr.size(); 
        if(n % 2 != 0) return false; 
        unordered_set<int> st; 

        for(int i = 0; i < n; i++) {
            int r1 = arr[i] % k; 
            int r2 = k - r1; 

            if(st.find(r2) != st.end()) 
                st.erase(r2); 
            else if(r1 == 0 && st.find(0) != st.end()) 
                st.erase(0); 
            else 
                st.insert(r1); 
        }

        return st.size() == 0; 
    }
};