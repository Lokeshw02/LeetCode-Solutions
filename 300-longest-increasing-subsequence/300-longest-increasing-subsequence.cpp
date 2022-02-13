class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),i,j,res = 0 ;
        vector<int> dp(n,0) ;
        
        
        
        dp[i] = 1 ;
        for(i = 0; i<n; i++){
            //Fill from 0 to n-1 
        //dp[i] <== LIS ending at i  
        //Descision on the predecessor 
            dp[i] = 1 ;
            
            for(j = n-1 ; j>= 0; j--){
                if(nums[j]<nums[i])
                    dp[i] = max(dp[i], 1+dp[j]) ;
            }
            //By now we have dp[i] ;
            //res = max of dp[0],dp[1],dp[2] ...dp[n-1] 
            
            res = max(res,dp[i]);
            
        }
        
        return res ;
        
    }
};