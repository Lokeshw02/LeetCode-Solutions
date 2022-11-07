class Solution {
public:
    int numDecodings(string s) {
        int n = s.size() ;
        
        vector<int>dp(n+1,0) ;
        
        dp[0] = 1 ;
        dp[1] = s[0] == '0' ? 0 : 1  ;
        
        for(int i = 2; i <= n ; i++){
            
        // Last one char 
          if(s[i-1] > '0' && s[i-1] <= '9' ) 
              dp[i] += dp[i-1] ;
            
          if(s[i-2] == '1' || (s[i-1] <= '6' && (s[i-2] == '2') ))
             dp[i] += dp[i-2] ;
            
            
        }
        return dp[n] ;
    }
};