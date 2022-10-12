class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp = matrix ;
        
        int n = matrix.size() ;
        
        for(int i = n-2; i >=0 ;i--){
            for(int j =0 ; j < n ; j++){
                int a = INT_MAX, b = INT_MAX, c = INT_MAX ;
                
                if(j-1 >= 0) 
                    a = dp[i+1][j-1] ;
                if(j+1 <n) 
                    c = dp[i+1][j+1] ;
                
                b = dp[i+1][j] ;
                    
                    dp[i][j] += min({a,b,c}) ;
            }
        }
        
        int ans = INT_MAX ;
        
        for(int i = 0 ; i < n ; i++){
            ans = min(ans,dp[0][i]) ;
        }
        return ans ;
    }
};