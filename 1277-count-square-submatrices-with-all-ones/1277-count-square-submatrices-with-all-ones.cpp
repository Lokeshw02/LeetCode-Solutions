class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size())) ;
        
        int i , j ; 
        
        int count = 0 ;
        
        for(i = 0;i<matrix.size();i++){
            for(j=0;j<matrix[0].size();j++){
                
                if(i == 0) dp[i][j] = matrix[i][j] ;
                 else if(j == 0) dp[i][j] = matrix[i][j] ; 
                
                else{
                    
                    if(matrix[i][j] ==0) dp[i][j] =0 ;
                    
                    else{
                        dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) ;
                   
                  
                    }
                  
               } 
                
                count += dp[i][j] ; 
            }
        }
           
        
                
              
           
        return count ;
    }
};