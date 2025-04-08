class MyQueue {
public:
    stack<int> in, op;

    MyQueue() {}

    void push(int x) { in.push(x); }

    int pop() {
        int rem = -1;
        if (!op.empty()) {
            rem = op.top();
            op.pop();
            return rem;
        } else {
            while (!in.empty()) {
                op.push(in.top());
                in.pop();
            }
        }
        rem=op.top();
        op.pop();
        return rem;
    }

    int peek() {

        if (!op.empty()) {
            return op.top();
        } else {
            while (!in.empty()) {
                op.push(in.top());
                in.pop();
            }
        }
        return op.top();
    }

    bool empty() { return in.empty() && op.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */