#include <map>

using namespace std; 

class MyCalendarThree {
public:
    map<int, int> events; 

    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        events[startTime] += 1; 
        events[endTime] -= 1; 

        int cnt = 0; 
        int maxIntersection = 0; 
        for(auto &e : events) {
            cnt += e.second; 
            maxIntersection = max(maxIntersection, cnt); 
        }    

        return maxIntersection; 
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */