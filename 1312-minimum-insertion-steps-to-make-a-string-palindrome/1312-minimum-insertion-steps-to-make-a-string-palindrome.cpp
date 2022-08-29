class Solution {
public:
    int minInsertions(string s) {
        
          string text1 = s , text2 = s  ;
        reverse(text2.begin(),text2.end()) ;
           
        
        int n = s.size(), m =s.size() ;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1)) ; 
        
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m ; j++){
                
                if(i == 0 || j == 0) dp[i][j] = 0 ;
            }
        }
        
        for(int i = 1 ; i < n+1; i++){
            for(int j = 1; j < m+1 ; j++){
                
                if(text1[i-1] == text2[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
            }
        }
        
        return  s.size() - dp[n][m] ;
        
    }
};