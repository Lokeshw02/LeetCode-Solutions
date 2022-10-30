class Solution {
public:
    
    int helper(vector<int>& nums, int idx, vector<int>&dp) {
        
       
        if(idx >= nums.size()) 
            return 0 ;
        
         if(idx == nums.size() -1) 
            return 1 ;
        
        if(dp[idx] != -1) 
            return dp[idx] ;
        
        int k = nums[idx] ;
        
        for(int i = 1 ; i <= k ; i++){
            
            if(helper(nums,idx+i,dp) )
                return dp[i] = 1 ;
        }
        
        return dp[idx]= 0 ;
    }
    
    bool canJump(vector<int>& nums) {
        
        int n = nums.size() ;
        
        vector<int>dp(n,-1) ;
        
        return helper(nums,0,dp) ;
        
        
        
    }
};