class Solution {
public:
    
    int helper(vector<int>&prices, vector<vector<vector<int>>>&dp, int idx, int buy, int cap){
        
        if(idx == prices.size() || cap == 0 ) 
            return 0 ;
        
        if(dp[idx][buy][cap] != -1) 
            return dp[idx][buy][cap] ; 
        
        int profit ;
        
        if(buy == 0 ){ //Buy a stock OR DO nothing
            profit = max(-prices[idx] + helper(prices,dp,idx+1,1,cap) , 0 + helper(prices,dp,idx+1,0,cap) ) ;
            
        }
        
        if(buy == 1){ //Selling ot doing nothing 
            

            profit = max(prices[idx] + helper(prices,dp,idx+1,0,cap-1), 0 + helper(prices,dp,idx+1,1,cap)) ;
        } 
        
        return dp[idx][buy][cap] = profit ;
        
    }
    
    
    
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size() ;
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1))) ; 
        
        return helper(prices,dp,0,0,k) ;
    }
};