class StockSpanner {
public:
    
    stack<pair<int,int>> stk ;
    int idx = 0 ;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
      
       if( stk.empty() ) {
            stk.push({price,idx++}) ; 
            return 1  ;
       }
       else
       {
           while(!stk.empty() && stk.top().first <= price) 
               stk.pop() ;
       }
        
        int res = 0 ;
        
        res = stk.empty() ? idx+1 : idx - stk.top().second ;
        stk.push({price,idx++}) ;
        
        return res ;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */