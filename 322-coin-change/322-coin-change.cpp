class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
       int n = coins.size() ;
        
       // if(n == 1){
       //     if(coins[0] == amount ) return 1 ;
       //     if(amount % coins[0] == 0 ) return amount/coins[0] ;
       //     return -1 ;
       // } 
       vector<vector<int>> dp(n+1, vector<int>(amount +1) );
      /////////  
       for(int i = 0 ;i < amount +1  ; i++){
          
                dp[0][i] = INT_MAX -1  ;
            
       }
         for(int j = 1 ;j < n +1  ; j++){
          
                dp[j][0] = 0  ;
            
       }
         for(int j = 1 ;j < amount +1  ; j++){
          
                if(j%coins[0] == 0) dp[1][j] = j/coins[0] ;
                else 
                    dp[1][j] = INT_MAX -1 ;
            
       }
        
        
        /////////////////
        
         for(int i = 2 ;i < n+1 ; i++){
           for(int j = 1 ; j< amount+1 ; j++){
              
               if(coins[i-1] <= j)
                   dp[i][j] =  min (1 + dp[i][j-coins[i-1]] , dp[i-1][j] )  ;
               else 
                   dp[i][j] = dp[i-1][j] ;
           }
       }
        
        return dp[n][amount] == (INT_MAX -1) ? -1 : dp[n][amount];
        
    }
};