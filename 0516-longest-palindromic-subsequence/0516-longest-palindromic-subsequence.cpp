class Solution {
public:
    
    int helper(string &a, string &b, int m, int n,vector<vector<int>>&dp ){
        
        if(n  == 0 || m ==  0) return 0 ;
        
        if(dp[m][n] != -1) 
            return dp[m][n] ;
        
        if(a[m-1] == b[n-1]) 
            return dp[m][n] = 1 + helper(a,b,m-1,n-1,dp) ;
        else
            return dp[m][n] = max(helper(a,b,m,n-1,dp), helper(a,b,m-1,n,dp)) ;
 
    }
    
    int longestPalindromeSubseq(string s) {
        
        string text1 = s , text2 = s  ;
        reverse(text2.begin(),text2.end()) ;
           
        
        int m = s.size(), n =s.size() ;
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1)) ; 
        
        return helper(text1,text2,m,n,dp) ;
        
       
        
    }
};