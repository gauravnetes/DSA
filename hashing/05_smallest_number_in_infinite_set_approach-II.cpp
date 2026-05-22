#include <vector>
#include <queue>
#include <unordered_set>
#include <set>

using namespace std; 

class SmallestInfiniteSet {
public:
    int currSmallest; 
    unordered_set<int> st; 
    priority_queue<int, vector<int>, greater<int>> pq; 

    SmallestInfiniteSet() {
        currSmallest = 1; 
    }
    
    int popSmallest() {
        int res; 

        if(!pq.empty()) {
            res = pq.top(); 
            pq.pop(); 
            st.erase(res); 
        } else {
            res = currSmallest; 
            currSmallest++; 
        }

        return res; 
    }
    
    void addBack(int num) {
        if(num >= currSmallest || st.find(num) != st.end()) {
            return; 
        }
        st.insert(num); 
        pq.push(num); 
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */