class StockSpanner {
public:
    
    stack<pair<int,int>> s ; 
    int idx = 0 ;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        if(s.empty()) {
            s.push({price,idx++});
             return 1;
        }
           
        else{
            while(!s.empty() && s.top().first <= price) 
                s.pop() ;
        }
        int res = 0 ;
        
        res = s.empty()? idx +1 : idx - s.top().second ;
        s.push({price,idx++}) ;
        
        return res ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */