class Solution {
public:
    
    int helper(vector<int>& prices,int n, vector<vector<vector<int>>>&dp, int idx,int buy, int cap){
        
        if(idx == n || cap == 0) return 0 ;
        
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap] ;
        
        int profit ;
        
        if(buy == 0) {
            profit = max(0 + helper(prices,n,dp,idx+1,0,cap), -prices[idx] + helper(prices,n,dp,idx+1,1,cap)) ;
        }
        
        if(buy == 1){
            profit = max(0+helper(prices,n,dp,idx+1,1,cap), prices[idx] + helper(prices,n,dp,idx+1,0,cap-1)) ;
        }
        
        return dp[idx][buy][cap] = profit ;
    }
    
    
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1))) ;
        
        return helper(prices,n,dp,0,0,k) ;
    }
};