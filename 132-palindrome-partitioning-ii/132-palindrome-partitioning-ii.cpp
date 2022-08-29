class Solution {
public:
    
     int dp[2001][2001] ;
    
    
   bool isPalindrome(string &s, int i, int j){
       while(i <= j){
           if(s[i] != s[j]) 
           return false ;
           i++; j-- ;
           
       }
       return true ;
   }
   
   int helper(string &s , int i, int j){
       if(i >= j) 
       return 0 ;
       
       if(dp[i][j] != -1) 
       return dp[i][j] ;  
       
       if( isPalindrome(s,i,j)) 
       return 0 ;
       
       int mn = INT_MAX, temp ; 
       
       for(int k = i ; k <= j-1 ; k++ ){
           
            
           
           if(isPalindrome(s,i,k))
            temp = 1 + helper(s,k+1,j) ; 
           
           mn = min(temp,mn) ;
           
       }
       
       return dp[i][j] = mn ;
       
       
   }
    int minCut(string s) {
        
        memset(dp,-1,sizeof(dp)) ; 
        int n = s.size() ;
        return helper(s,0,n-1) ;
    }
};