class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int i, j, n = nums.size(), res,cd ;
        
        vector<vector<int>>dp(n,vector<int>(1001,0)) ;
    
        
        for(i = 0 ; i < n ; i++){
            for( j = i-1; j >=0; j-- ){
                
                 cd = nums[i] - nums[j] ;
                
                if(dp[j][cd+500] == 0) 
                    dp[i][cd+500] = max(dp[i][cd+500], 2) ;
                else
                    dp[i][cd+500] = max(dp[i][cd+500], 1 + dp[j][cd+500]) ;
                
                 res = max(res, dp[i][cd+500]) ;
            }
            
           
        }
        
        return res ;
    }
};