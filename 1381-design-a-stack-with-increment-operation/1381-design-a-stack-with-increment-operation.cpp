class CustomStack {
public:
     vector<int> st;
    vector<int> inc;
    int size_;
    CustomStack(int maxSize) {
        size_ = maxSize;
    }
    
    void push(int x) {
        if(st.size() < size_){
            st.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() {
        if(st.size() == 0)
            return -1;
        
        int t = st[st.size()-1];
        st.pop_back();
        
        int t2 = inc[inc.size()-1];
        inc.pop_back();
        
        // Update the predecessor
        if(inc.size() > 0) {
            inc[inc.size()-1] += t2;
        }
        
        return t+t2;
    }
    
    // O(1)
    // Lazy increment
    void increment(int k, int val) {
        if(st.size() == 0) return;
        
        inc[min(k, (int)st.size())-1] += val;
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */