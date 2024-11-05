class MyStack {
public:
    queue<int> q1,q2;
    int last=0;
    MyStack() {
        
    }
    
    void push(int x) {
        last=x;
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() >1){
            q2.push(q1.front());
            q1.pop();
        }
        int del=q1.front();
        q1.pop();
        while(!q2.empty()){
            last=q2.front();
            q1.push(q2.front());
            q2.pop();
        }

        return del;
    }
    
    int top() {
        return last;
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