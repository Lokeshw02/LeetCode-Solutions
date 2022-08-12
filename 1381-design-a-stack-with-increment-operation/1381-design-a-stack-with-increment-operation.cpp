class CustomStack {
public:
    vector<int> stk ;
    vector<int> inc ;
    
    int size_ ;
    
    CustomStack(int maxSize) {
        size_ = maxSize ;
    }
    
    void push(int x) {
        if(stk.size() < size_){
             stk.push_back(x) ;
        inc.push_back(0 ) ;
        }
       
    }
    
    int pop() {
        if(stk.size() == 0) return -1 ;
        
        int t = stk[stk.size()-1] ;
        stk.pop_back() ;
        
        int t1 = inc[inc.size() - 1] ;
        inc.pop_back() ;
        
        //Update the Predecessor 
        if(inc.size() > 0){
            inc[inc.size()-1] += t1 ;
        }
        
        return t + t1 ;
        
    }
    
    void increment(int k, int val) {
        
        if(stk.size() == 0) return ;
        
        int m = min  (k, (int)stk.size()) -1 ;
        
        inc[m] += val ;
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */