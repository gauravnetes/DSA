#include <vector>
#include <set>

using namespace std; 

class SmallestInfiniteSet {
public:
    int currSmallest; 
    set<int> st; 

    SmallestInfiniteSet() {
        currSmallest = 1; 
    }
    
    int popSmallest() {
        int res; 

        if(!st.empty()) {
            res = *st.begin(); 
            st.erase(st.begin()); 
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
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */