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
       
       if(i >= j) return 0 ;
       
       if(isPalindrome(s,i,j)) 
           return 0 ;
       
       if(dp[i][j] != -1) 
           return dp[i][j] ;
       
       int mn = INT_MAX ;
       
       for(int k =  i ; k < j ; k++){
           
           if(isPalindrome(s,i,k)) {
                int tempans = 1 + helper(s,k+1,j) ; 
                mn = min(mn,tempans) ;
           }
              
       }
       
       return dp[i][j] = mn ;
       
       
       
   }
    int minCut(string s) {
        
        memset(dp,-1,sizeof(dp)) ; 
        int n = s.size() ;
        return helper(s,0,n-1) ;
    }
};