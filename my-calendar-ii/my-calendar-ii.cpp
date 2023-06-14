class MyCalendarTwo {
    map<int,int> log;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ++log[start];
        --log[end];
        int onGoing = 0;
        for(auto& booking : log){
            onGoing += booking.second;
            if(onGoing > 2){
                --log[start];
                ++log[end];
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */