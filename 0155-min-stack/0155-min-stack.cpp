class MinStack {
public:

    stack<int> st1,st2;
    int mini=1e9;

    MinStack() {

    }
    
    void push(int val) {
        st1.push(val);
        mini=min(mini,val);
    }
    
    void pop() {

        int p=st1.top();
        st1.pop();

        if(mini==p){
            mini=1e9;
            while(!st1.empty()){
                int temp=st1.top();
                st2.push(temp);
                st1.pop();
                mini=min(mini,temp);
            }

            while(!st2.empty()){
                int temp=st2.top();
                st1.push(temp);
                st2.pop();
            }
        }
    }
    
    int top() {
        
        return st1.top();
    }
    
    int getMin() {
        return mini;
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