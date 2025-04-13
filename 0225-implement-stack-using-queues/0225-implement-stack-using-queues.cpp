class MyStack {
public:
    // prepped this for ion interview, lifes a fucking joke 

    queue<int> primary, temp;
    
    MyStack() {
        
    }
    
    void push(int x) {
        temp.push(x);

        while(!primary.empty()){
            temp.push(primary.front());
            primary.pop();
        }
        swap(temp,primary);
    }
    
    int pop() {
        int x=primary.front();
        primary.pop();
        return x;
    }
    
    int top() {
        return primary.front();
    }
    
    bool empty() {
        return primary.empty();
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