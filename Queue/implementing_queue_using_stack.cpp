class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {}

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s2.push(s1.top());
            s2.top();
        }
    }

    int pop() {
        int y = s1.top();
        s1.pop();
        return y;
    }

    int peek() { return s1.top(); }

    bool empty() { return s1.empty(); }
};

//logic 2 
class MyQueue {
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int y = output.top();
            output.pop();
            return y;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int z = output.top();
        output.pop();
        return z;
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();  
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }
    
    bool empty() {
        return (input.empty()&&output.empty());
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