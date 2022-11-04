class Solution {
public:
    
    int dp[101][101] ;
    
     int helper(vector<int>&values, int i, int j){
         
         if(i >= j) 
             return 0 ;
         if(dp[i][j] != -1) 
             return dp[i][j] ;
         int mn = INT_MAX ;
         
         for(int k = i; k < j ; k++){
             int temp = helper(values,i,k) + helper(values,k+1,j) + values[i-1]*values[k]*values[j] ;
             mn = min(mn,temp) ; 
         }
         
         return dp[i][j] = mn ;
     }
    
    
    int minScoreTriangulation(vector<int>& values) {
     
        memset(dp,-1,sizeof(dp)) ;
        
        int i = 1;
        int j = values.size() -1 ;
        
        return helper(values,i,j) ;
    }
};