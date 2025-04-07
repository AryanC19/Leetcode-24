class MyQueue {
public:
    stack<int> in,op;
    int first=-1;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(in.empty()) first=x;
        in.push(x);
    }
    
    int pop() {
     
        while(!in.empty()){
            op.push(in.top());
            in.pop();
        }
        
        int rem=op.top();
        op.pop();
        if(!op.empty())
            first=op.top();

        while(!op.empty()){
            in.push(op.top());
            op.pop();
        }
        return rem;

    }
    
    int peek() {
        return first;
    }
    
    bool empty() {
        return in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */