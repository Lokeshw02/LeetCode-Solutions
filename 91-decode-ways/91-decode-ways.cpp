class Solution {
public:
    
    
    int helper(int i, string &s, vector<int>&dp){
        if(i>=s.size()) return 1 ;
        if(dp[i] != -1) return dp[i] ;
        int ans = 0 ;
        int op1 = s[i] - '0' , op2 = 0 ;
        
        if(i<s.size()-1){
            op2 = op1*10 + (s[i+1] - '0') ;
            
        }
        if(op1>0) ans += helper(i+1,s,dp) ;
        if(op1>0 && op2>0 && op2<=26) ans+= helper(i+2,s,dp) ;
        
        return dp[i] = ans ;
    }
    
    
    
    
    
    
    
    int numDecodings(string &s) {
       vector<int> dp(101,-1) ;
       return helper(0,s,dp) ;   
    }
};