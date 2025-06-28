class MyStack {
public:
    queue<int> curr, temp;

    MyStack() {
        
    }
    
    void push(int x) {
        
        temp.push(x);
        while(!curr.empty()){
            temp.push(curr.front());
            curr.pop();
        }
        swap(curr,temp);
    }
    
    int pop() {
        int x=curr.front();
        curr.pop();
        return x;
    }
    
    int top() {
        return curr.front();
    }
    
    bool empty() {
        return curr.empty() && temp.empty();
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