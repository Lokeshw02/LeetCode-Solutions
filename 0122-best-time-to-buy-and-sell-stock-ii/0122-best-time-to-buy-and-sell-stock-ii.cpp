class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int bp = -prices[0], sp = 0 ;
        
        for(int i =1 ; i< prices.size(); i++){
            
            bp = max(bp, sp - prices[i]) ; 
            sp = max(sp,bp + prices[i]) ;
            
        }
        
        return sp ;
            
        
    }
};