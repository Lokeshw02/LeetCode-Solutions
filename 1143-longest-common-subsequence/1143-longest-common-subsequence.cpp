class Solution {
public:
    
    int helper(string &S1, string &S2, int n, int m, vector<vector<int>>&dp){
        
        if(n == 0 || m == 0) return 0  ;
        
        
        if(dp[n][m] != -1) return dp[n][m] ;
        
        if(S1[n-1] == S2[m-1]) 
        return dp[n][m] = 1 + helper(S1,S2,n-1,m-1,dp) ;
        
      
        
        else 
        return dp[n][m]  =  max( helper(S1,S2,n-1,m,dp), helper(S1,S2,n,m-1,dp) )  ;
        
        
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size(), m =text2.size() ;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1)) ;
        
        
        return helper(text1,text2,n,m,dp) ;
    }
};