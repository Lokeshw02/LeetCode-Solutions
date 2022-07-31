class CustomStack {
public:

    vector<int> v ;
    int max_size ;
    
    CustomStack(int maxSize) {
       
        max_size = maxSize ;
    }
    
    void push(int x) {
        
        if(v.size() < max_size){
             // stk.push(x) ; 
             v.push_back(x) ;
        }
           
        
    }
    
    int pop() {
        if(v.size() > 0 ){
             int temp = v[v.size() -1] ; 
            // stk.pop() ;
             v.pop_back() ;
             return temp ;
        }
         
       return -1 ;
        
        
    }
    
    void increment(int k, int val) {
        if(v.size() < k) {
            
            for(int i = 0; i < v.size()  ; i++){
                v[i] +=  val ;
               // stk.pop() ;
            }
            
           
            
        }
        
        else{
            
             for(int i = 0; i < k   ; i++){
                v[i] +=  val ;
                
            }
            
         
            
        }
        
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */