class MyQueue {

    Stack<Integer> input,output;
    int peekElement=-1;

    
    public MyQueue() {
        input=new Stack<>();
        output=new Stack<>();    
    }
    
    public void push(int x) {
        if(input.isEmpty()) peekElement=x;
        input.push(x);
    }
    
    public int pop() {
        if(output.isEmpty()){
            while(!input.isEmpty()){
                output.push(input.peek());
                input.pop();
            }
        }

        int x=output.peek();
        output.pop();
        return x;
    }
    
    public int peek() {
        if(!output.isEmpty()) return output.peek();
        return peekElement;
    }
    
    public boolean empty() {
        return input.isEmpty() && output.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */