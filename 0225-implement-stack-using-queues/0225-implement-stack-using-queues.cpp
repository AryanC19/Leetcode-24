class MyStack {
public:

    queue<int> in,op;
    int last=-1;

    MyStack() {
        
    }
    
    void push(int x) {
        in.push(x);
        last=x;
    }
    
    int pop() {
        int rem=0;

        while(!in.empty()){
            
            if(in.size()==2) 
                last=in.front();
            if(in.size()>1){
                op.push(in.front());
            }else{
                rem=in.front();
            }
            in.pop();
        }
        
        while(!op.empty()){
            in.push(op.front());
            op.pop();
        }
        return rem;
    }
    
    int top() {
        return last;
    }
    
    bool empty() {
        return in.empty();
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