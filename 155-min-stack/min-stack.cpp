class MinStack {
    stack<int> s;
    stack<int> mini;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        if(mini.empty() || s.top()<mini.top()){
            mini.push(value);
        }else{
            mini.push(mini.top());
        }
    }
    
    void pop() {
        s.pop();
        mini.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */