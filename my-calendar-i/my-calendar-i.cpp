class MyCalendar {
    vector<vector<int>> bookings;
public:
    MyCalendar() {
        
    }

    bool book(int start, int end) {
        if(bookings.empty()){
            bookings.push_back({start, end});
            return true;
        }

        int idx = -1;
        int l = 0; int r = bookings.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(bookings[mid][0] <= start){
                idx = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if(idx == -1){ // insert at start
            if(end > bookings[0][0]){ // overlap
                return false;
            }
            else{
                bookings.insert(bookings.begin(), {start,end});
                return true;
            }
        }
        else if(idx == bookings.size()-1){ // insert at end
            if(bookings[idx][1] > start){
                return false;
            }
            else{
                bookings.insert(bookings.begin()+idx+1, {start,end});
                return true;
            }
        }
        else{
            if((bookings[idx][1] > start) || (end > bookings[idx+1][0])){
                return false;
            }
            else{
                bookings.insert(bookings.begin()+idx+1, {start,end});
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */