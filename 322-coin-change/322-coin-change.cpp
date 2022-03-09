class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      
        int n = coins.size(),i,j, temp ;
        vector<int>dp(amount+1,INT_MAX) ;
        
        dp[0] = 0 ;
        
        for(i = n-1; i>= 0; i--){
            for(j=0;j<=amount;j++){
                //Include 
                if(j-coins[i] >= 0){
                    if(dp[j-coins[i]] != INT_MAX)
                        dp[j] = min(dp[j],1+dp[j-coins[i]]) ;
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount] ;
    }
};