class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) {
            return 0;
        }
        
        int maxProfit = 0;
        int mnSoFar = prices[0];
        for(int i = 1; i < n; ++i) {
            maxProfit = max(maxProfit, prices[i] - mnSoFar);
            mnSoFar = min(mnSoFar, prices[i]);
        }
        
        return maxProfit;
        
        
    }
};