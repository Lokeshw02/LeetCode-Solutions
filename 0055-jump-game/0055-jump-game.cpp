class Solution {
public:
    
    int helper(vector<int>& nums,vector<int>&dp, int i, int n){
        
        if(i == n-1 ) 
            return 1 ;
        if(i >= n) 
            return 0 ;
        if(dp[i] != -1) 
            return dp[i] ;
        
        int k = nums[i] ;
        
        for(int j = 1; j <= k ; j++){
            
            if(helper(nums,dp,i+j,n)) 
                return dp[i] = 1 ;
        }
        
        return dp[i] = 0 ;
    }
    
    
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>dp(n,-1) ;
        
        return helper(nums,dp,0,n) ;
        
        
    }
};