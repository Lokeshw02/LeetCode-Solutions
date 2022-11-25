class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size() ;
        vector<int>dp(n,0) ;
        int res = INT_MIN ;
        
        
        if(n == 0 || n == 1) return 0 ; 
        
        //ith index will store the lenght of LVP till that index \
        
        dp[0] = 0 ;
        
        for(int i = 1 ; i < n ; i++){
            
            if(s[i] == '(')
                dp[i] = 0 ;
            else
            {
                int L = dp[i-1] ;
                //i - L -1 >>> 
                
                if( i - L -1 >= 0 && s[i - L -1] == '(') {
                    
                    dp[i] = 2 + dp[i-1] ; 
                    
                   if(i-L-2 >= 0) 
                   dp[i] += dp[i-L-2] ;
                    
                }

            }
            
            res = max(res,dp[i]) ;
        }
        
        return res ;
    }
};