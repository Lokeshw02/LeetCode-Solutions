class Solution {
public:
    
    
    int climbHelper(int start,int n,vector<int>&dp){
        
        if(start == n) return 1;
        
        if(start>n) return 0 ;
        
        if(dp[start] != -1) return dp[start]  ;
        
        int res = climbHelper(start+1,n,dp) ;
        
        res += climbHelper(start+2,n,dp) ;
        
        dp[start] = res ;
        
        return dp[start] ;
        
    }
    
    
    
    
    
    int climbStairs(int n) {
       
        vector<int> dp(n+1,-1) ;
        
        return climbHelper(0,n,dp) ;
        
    }
};

