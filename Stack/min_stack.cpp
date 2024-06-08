class MinStack {
    long long min;
    stack<long long> stk;
public:
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        long long value = val;
        if(stk.empty()){
            min = value;
            stk.push(value);
        }else{
            if(value<min){
                //for the modified value
                long long y =2*value - min;
                min = value;
                stk.push(y);
            }else{
                stk.push(value);
            }
        }
    }
    
    void pop() {
        if(stk.empty()){
            return;
        }
        long long val = stk.top();
        if(val<min){
            //for the modified value
            min = 2*min - val;
            stk.pop();
        }else{
            stk.pop();
        }
    }
    
    int top(){
        long long val = stk.top();
        if(val<min){
            //for the modified value
            return min;
        }else{
            return val;
        }
    }
    
    int getMin() {
        return min;
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