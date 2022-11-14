class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
        //int dp[amount+1] = {INT_MAX}  ; 
        
       vector<int>dp(amount+1, INT_MAX) ;
        
        dp[0] = 0 ;
        
        for(int i = n-1 ; i >= 0; i--){
            
            for(int j = 0 ; j<= amount ;  j++){
                
                if(j - coins[i] >= 0){
                    
                    if(dp[j-coins[i]] != INT_MAX) 
                       dp[j] = min(1 + dp[j-coins[i]], dp[j]) ;
                    
                }
                
            }
        }
        
        return dp[amount] == INT_MAX ? -1 :dp[amount] ;
    }
};