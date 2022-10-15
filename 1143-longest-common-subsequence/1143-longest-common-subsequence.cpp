class Solution {
public:
    
    int helper(string &S1, string &S2, int m, int n, vector<vector<int>>&dp){
        
        if(n == 0 || m == 0) return 0  ;
        
        
        if(dp[m][n] != -1) return dp[m][n] ;
        
        if(S1[m-1] == S2[n-1]) 
        return dp[m][n] = 1 + helper(S1,S2,m-1,n-1,dp) ;
        
      
        
        else 
        return dp[m][n]  =  max( helper(S1,S2,m-1,n,dp), helper(S1,S2,m,n-1,dp) )  ;
        
        
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int  m = text1.size(), n =text2.size() ;
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1)) ;
        
        
        return helper(text1,text2,m,n,dp) ;
    }
};