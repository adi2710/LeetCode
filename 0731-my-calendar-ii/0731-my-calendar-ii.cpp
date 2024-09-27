class MyCalendarTwo {
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> doubleBookings;
    
    bool isOverlap(int st, int en, int start, int end) {
        return max(st, start) < min(en, end);
    }
    
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        for(auto [st, en] : doubleBookings) {
            if(isOverlap(st, en, start, end)) {
                return false;
            }
        }
        
        for(auto [st, en] : bookings) {
            if(isOverlap(st, en, start, end)) {
                doubleBookings.push_back({max(st, start), min(en, end)});
            }
        }
        
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */