class MyStack {
    queue<int> q1;
    queue<int> q2;
    int Top;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        Top = x;   
    }
    
    int pop() {
        while(q1.size()>1){
            Top = q1.front();
            q2.push(Top);
            q1.pop();
        }
        int x = q1.back();
        q1.pop();

        queue<int> temp = q2;
        q2 = q1;
        q1 = temp;

        Top = q1.back(); 
        return x;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */