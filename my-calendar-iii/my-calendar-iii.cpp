class MyCalendarThree {
    map<int,int> log;
public:
    int book(int startTime, int endTime) {
       ++log[startTime]; 
       --log[endTime];
        int max_bookings = 0;
        int ongoing = 0;

        for(auto& ev : log){
            ongoing += ev.second;
            max_bookings = max(max_bookings, ongoing);
        }
        return max_bookings;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */