class RecentCounter {
    queue<int> log;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        log.push(t);
        while(log.front() < t-3000){
            log.pop();
        }
        return log.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */