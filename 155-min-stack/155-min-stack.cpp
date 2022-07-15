class MinStack {
public:
    stack<int> reg_stack_ ;
    stack<int> min_stack_;
    
    
    MinStack() {
        
    }
    
    void push(int val) {
        reg_stack_.push(val) ;
        
        if(min_stack_.empty())
            min_stack_.push(val) ;
        
        else 
        min_stack_.push(min(min_stack_.top(),val)) ;
    }
    
    void pop() {
        reg_stack_.pop() ;
        min_stack_.pop() ;
        
        
    }
    
    int top() {
        return reg_stack_.top() ;
        
    }
    
    int getMin() {
        return min_stack_.top() ;
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