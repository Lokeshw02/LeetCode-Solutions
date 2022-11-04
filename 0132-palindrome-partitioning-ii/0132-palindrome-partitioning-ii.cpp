class Solution {
public:
    
    
    bool ispalindrome(string &s,int i, int j){
        
        while( i <= j){
            if(s[i] != s[j]) 
                return false ;
            i++;j-- ;
        }
        return true ;
    }
 
    int helper(string &s,int i, int  j, vector<vector<int>>&dp ){
        
        if(i >= j) 
            return 0 ;
            
        if(ispalindrome(s,i,j)) 
            return 0 ;
        if(dp[i][j] != -1) 
            return dp[i][j] ;
        
        int mn = INT_MAX ;
        
        for(int k = i; k <j ; k++){
            
           if (ispalindrome(s,i,k)){
                
                int temp = 1 + helper(s,k+1,j,dp) ;
                mn = min(temp,mn) ;
            }
        }
        
        return dp[i][j] = mn ;
    }
    
    
    int minCut(string s) {
        vector<vector<int>>dp(2001,vector<int>(2001,-1)) ;
        int i = 0 , j = s.size() -1 ;
        
        return helper(s,i,j,dp) ;
        
    }
};