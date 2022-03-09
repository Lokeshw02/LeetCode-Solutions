class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int  n = nums.size(),i,j ;
        
      //  if(target>1000) return 0 ;
        
        vector<vector<int>>dp(2,vector<int>(2001,0)) ;
        
        dp[n%2][0 + 1000] = 1 ;
        
        for(i = n-1;i>=0;i--){
            for(j = -1000;j<= 1000; j++){
                
                dp[i%2][j+1000] = 0 ;
                
                //Two choices : add +a
                if(j-nums[i] >= -1000)
                    dp[i%2][j+1000] += dp[(i+1)%2][j-nums[i]+1000] ;
                // add -a 
                
                if(j+nums[i] <= 1000)
                    dp[i%2][j+1000] += dp[(i+1)%2][j+nums[i]+1000]  ;
             }
            
        }
        
        return dp[0][target+1000] ;
    }
};