class FreqStack {
    unordered_map<int,int> frq;
    unordered_map<int, stack<int>> log;
    int max_frq;
public:
    FreqStack() {
        frq.clear();
        log.clear();
        max_frq = 0;
    }
    
    void push(int val) {
        ++frq[val];
        log[frq[val]].push(val);

        max_frq = max(max_frq, frq[val]);
    }
    
    int pop() {
        int ans = log[max_frq].top();
        log[max_frq].pop();
        --frq[ans];
        
        // while((log[max_frq].empty()) && (max_frq > 0)){
        //     --max_frq;
        // }
        if(log[max_frq].empty()){
            --max_frq;
        }

        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */