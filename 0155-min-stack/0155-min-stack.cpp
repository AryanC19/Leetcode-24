class MinStack {
public:

    stack<int> cur, minStack;
    MinStack() {
    }
    
    void push(int val) {    
        cur.push(val);
        if(minStack.empty() || minStack.top() >= val) minStack.push(val);
    }
    
    void pop() {
        if(minStack.top()==cur.top()) minStack.pop();
        cur.pop();
    }
    
    int top() {
        return cur.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */