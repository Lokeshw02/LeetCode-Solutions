class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) {
            return 0;
        }
        
        int minpricesofar = INT_MAX; int profit = 0 ;
        
        for(int i = 0; i< prices.size(); i++){
            
            profit = max(profit,  prices[i] -minpricesofar );
            minpricesofar = min(minpricesofar, prices[i]) ;
        }
        
        return profit ;
        
    }
};